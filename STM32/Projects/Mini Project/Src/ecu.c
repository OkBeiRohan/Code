/**
 ******************************************************************************
 * @file           : ecu.c
 * @author         : Rohan K
 * @brief          : Mini ECU
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <ecu.h>
#include <common.h>

#define TIM_FREQ 16000000 // 16 MHz (Frequency of the TIM3 clock)

#define ENGINE_STATUS_POS 2
#define ENGINE_STATUS_LINE 0

#define LIGHT_STATUS_POS 8
#define LIGHT_STATUS_LINE 0

#define UART_STATUS_POS 14
#define UART_STATUS_LINE 0

#define FUEL_LEVEL_POS 2
#define FUEL_LEVEL_LINE 1

#define TURN_STATUS_POS 9
#define TURN_STATUS_LINE 1

enum UART_STATUS uart_status = UART_OFF;
enum HEAD_LIGHT_STATUS headlight_status = HEAD_LIGHT_OFF;
enum TURN_INDICATOR_STATUS turn_indicator_status = TURN_INDICATOR_OFF;
enum ENGINE_STATUS engine_status = ENGINE_OFF;
enum ECU_MODE mode = LCD_ON;
uint8_t uart_data = 0x0;
uint8_t fuel_level = 0;

/**
 * @brief Initialize the UART
 */
void initialize_uart(void);

/**
 * @brief Set the ignition status
 * @param status The status of the ignition
 */
void set_uart_status(enum UART_STATUS);

/**
 * @brief Initialize the PWM for Head Light
 */
void initialize_pwm(void);

/**
 * @brief Set the duty cycle for the PWM
 * @param duty_cycle Duty Cycle (0 - 1000)
 * @param frequency Frequency (Hz)
 */
void start_pwm(uint16_t, uint16_t);

/**
 * @brief Stop the PWM
 */
void stop_pwm(void);

/**
 * @brief Start the timer
 * @param autoreload Auto Reload Value
 */
void start_timer(uint16_t);

/**
 * @brief Stop the timer
 */
void stop_timer(void);

/**
 * @brief Write a byte to the UART
 * @param data Data to be written
 * @return Status of the transmission
 */
enum UART_STATUS uart_write(uint8_t);

/**
 * @brief Read a byte from the UART
 * @return Data read
 */
uint8_t uart_read(void);

/**
 * Initialize timer with interrupts for turn indicators
 */
void initialize_timer(void);

/**
 * Initialize the EXTI for the buttons (SW1, SW2, SW3 and SW4)
 */
void initialize_exti_buttons(void);

/**
 * Initialize the ADC for the fuel indicator
 */
void initialize_adc(void);

/**
 * @brief Handles the ignition key
 */
void ignition_handler(void);

/**
 * @brief Handles the left turn switch
 */
void left_turn_handler(void);

/**
 * @brief Handles the right turn switch
 */
void right_turn_handler(void);

/**
 * @brief Handles the head light switch
 */
void head_light_handler(void);

void set_mode(enum ECU_MODE new_mode)
{
    mode = new_mode;
}

void initialize_ecu(void)
{
    if (mode == LCD_ON)
    {
        /**
         * Initialize the LCD
         */
        lcd_init(BIT_4_MODE);
        lcd_print(0, 0, "Initializing");
        lcd_print(0, 1, "Please Wait!");
    }

    /**
     * Enable the clock for GPIOA, GPIOB and GPIOC
     */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;

    /**
     * Configure the modes for the GPIO ports (Switches, LEDs, Buzzer and Potentiometer)
     */
    set_input(IGNITION_KEY_PORT, IGNITION_KEY_PIN);           // Ignition Key
    set_input(LEFT_TURN_SWITCH_PORT, LEFT_TURN_SWITCH_PIN);   // Left Turn Switch
    set_input(RIGHT_TURN_SWITCH_PORT, RIGHT_TURN_SWITCH_PIN); // Right Turn Switch
    set_input(HEAD_LIGHT_SWITCH_PORT, HEAD_LIGHT_SWITCH_PIN); // Head Light Switch
    set_analog(FUEL_INDICATOR_PORT, FUEL_INDICATOR_PIN);      // Fuel Indicator

    if (mode == LCD_OFF)
    {
        set_output(IGNITION_LED_PORT, IGNITION_LED_PIN);       // Ignition LED
        set_output(LEFT_TURN_LAMP_PORT, LEFT_TURN_LAMP_PIN);   // Left Turn Lamp
        set_output(RIGHT_TURN_LAMP_PORT, RIGHT_TURN_LAMP_PIN); // Right Turn Lamp
        set_alternate(HEAD_LIGHT_PORT, HEAD_LIGHT_PIN);        // Head Light
        set_output(BUZZER_PORT, BUZZER_PIN);                   // Buzzer

        set_bit(IGNITION_LED_PORT, IGNITION_LED_PIN);       // Turn OFF the Ignition LED
        set_bit(LEFT_TURN_LAMP_PORT, LEFT_TURN_LAMP_PIN);   // Turn OFF the Left Turn Lamp
        set_bit(RIGHT_TURN_LAMP_PORT, RIGHT_TURN_LAMP_PIN); // Turn OFF the Right Turn Lamp
        clr_bit(BUZZER_PORT, BUZZER_PIN);                   // Turn OFF the Buzzer

        initialize_pwm();
        initialize_timer();
    }
    initialize_uart();
    initialize_exti_buttons();
    initialize_adc();

    if (mode == LCD_ON)
    {
        set_lcd_mode(CLEAR_SCREEN);
        lcd_print(0, 0, "C:OFF L:OFF U:OF");
        lcd_print(0, 1, "F:000% T:OFF");
    }
}

void initialize_uart(void)
{
    /**
     * Configure UART4_TX (PC10 - AF8), UART4_RX (PC11 - AF8)
     */
    GPIOC->AFR[1] |= (0x8 << 8) | (0x8 << 12); // Set AF8 for PC10 and PC11
    set_alternate(UART_TX_PORT, UART_TX_PIN);  // Set PA0 to alternate function mode
    set_alternate(UART_RX_PORT, UART_RX_PIN);  // Set PA1 to alternate function mode

    RCC->APB1ENR |= RCC_APB1ENR_UART4EN;                      // Enable the clock for UART4
    UART4->BRR = 0x683;                                       // Set the baud rate to 9600
    UART4->CR3 = 0x0;                                         // Disable the hardware flow control
    UART4->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE; // Enable the UART, Transmitter and Receiver
}

enum UART_STATUS uart_write(uint8_t data)
{
    uint32_t counter = 0;
    UART4->DR = data;                  // Write the data to the transmit buffer
    while (!(UART4->SR & USART_SR_TC)) // Wait for the transmission to be complete
    {
        if (counter >= 10000)
        {
            UART4->DR = 0;
            return UART_NOT_OK;
        }
        counter++;
    };
    return UART_OK;
}

uint8_t uart_read(void)
{
    uint32_t counter = 0;
    while (!(UART4->SR & USART_SR_RXNE))
    {
        if (counter >= 10000)
        {
            return 0x0;
        }
        counter++;
    };                // Wait for the receive buffer to be empty
    return UART4->DR; // Read the data from the receive buffer
}

void uart_signal_check(void)
{
    if (uart_status == UART_OFF || engine_status == ENGINE_OFF)
    {
        return;
    }

    enum UART_STATUS tx_status;
    tx_status = uart_write((uint8_t)UART_TRANSMIT_DATA);
    if (tx_status == UART_OK)
    {
        uart_data = uart_read();
    }
    else
    {
        uart_data = 0;
    }

    if ((uart_data == (uint8_t)UART_TRANSMIT_DATA))
    {
        set_uart_status(UART_OK);
    }
    else
    {
        set_uart_status(UART_NOT_OK);
    }
}

void set_uart_status(enum UART_STATUS status)
{
    if (engine_status == ENGINE_OFF)
    {
        return;
    }
    enum UART_STATUS prev_value = uart_status;
    uart_status = status;
    if (mode == LCD_ON && prev_value != status)
    {
        switch (status)
        {
        case UART_OFF:
            lcd_print(UART_STATUS_POS, UART_STATUS_LINE, "OF");
            break;

        case UART_OK:
            lcd_print(UART_STATUS_POS, UART_STATUS_LINE, "OK");
            break;

        case UART_NOT_OK:
            lcd_print(UART_STATUS_POS, UART_STATUS_LINE, "ER");
            break;

        default:
            lcd_print(UART_STATUS_POS, UART_STATUS_LINE, "??");
            break;
        }
    }
}

void initialize_pwm(void)
{
    GPIOC->AFR[0] |= (0x1 << 25); // Set AF2 for PC6 (TIM3_CH1)

    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;                 // Enable the clock for TIM3
    TIM3->PSC = 0x0;                                    // Set the prescaler to 0
    TIM3->CNT = 0x0;                                    // Set the counter to 0
    TIM3->ARR = 0x3E8;                                  // Set the auto-reload register to 1000
    TIM3->CCR1 = 0x0;                                   // Set the duty cycle to 0
    TIM3->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; // Set the PWM mode to PWM mode 1
    TIM3->CCMR1 |= TIM_CCMR1_OC1PE;                     // Enable the preload register (Output Compare 1)
    TIM3->CCER |= (3 << 0);                             // Enable the output for channel 1
    TIM3->CR1 |= TIM_CR1_CEN;                           // Enable the counterr
}

void start_pwm(uint16_t duty_cycle, uint16_t frequency)
{
    TIM3->CCR1 = (duty_cycle * ((TIM3->ARR) + 1)) / 100; // Set the duty cycle
    TIM3->ARR = (TIM_FREQ / frequency) - 1;              // Set the auto-reload register
}

void stop_pwm()
{
    TIM3->ARR = 0x3E8; // Set the auto-reload register to 1000
    TIM3->CCR1 = 0x0;  // Set the duty cycle to 0
    TIM3->CNT = 0;
}

void initialize_timer(void)
{
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; // Enable the clock for TIM2
    TIM2->PSC = 16000 - 1;              // Set the prescaler to 0
    TIM2->CNT = 0x0;                    // Set the counter to 0
    TIM2->ARR = 1000 - 1;               // Set the auto-reload register to 1000
    TIM2->DIER |= TIM_DIER_UIE;         // Enable the update interrupt

    uint32_t volatile *NVIC_ISER0 = (uint32_t *)0xE000E100; // Address of the NVIC ISER0 register
    *NVIC_ISER0 |= (1 << 28);                               // Enable the TIM2 global interrupt
}

void start_timer(uint16_t autoreload)
{
    TIM2->ARR = autoreload - 1; // Set the auto-reload register
    TIM2->CR1 |= TIM_CR1_CEN;   // Enable the counter
}

void stop_timer(void)
{
    TIM2->CR1 &= ~TIM_CR1_CEN; // Disable the counter
    TIM2->CNT = 0;
}

void initialize_adc(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; // Enable the clock for ADC1
    ADC1->CR2 = 0;                      // Disable the ADC
    ADC1->SQR3 |= (0xC << 0);           // Set the 13th channel as the first conversion in the regular sequence
    ADC1->SQR1 = 0;                     // Set the length of the regular sequence to 1 conversion
    ADC1->CR2 = 1;                      // Enable the ADC
}

void check_fuel_status()
{
    uint32_t counter = 0;
    if (engine_status == ENGINE_OFF)
    {
        if (fuel_level != 0)
        {
            fuel_level = 0;
            if (mode == LCD_ON)
            {
                lcd_print_int(FUEL_LEVEL_POS, FUEL_LEVEL_LINE, fuel_level, 1);
            }
        }
        return;
    }
    ADC1->CR2 |= ADC_CR2_SWSTART;    // Start the conversion
    while (!(ADC1->SR & ADC_SR_EOC)) // Wait for the conversion to finish
    {
        if (counter >= 10000)
        {
            return;
            counter = 0;
        }
        counter++;
    };
    uint8_t fuel_range_changed = 0;                       // Flag to check if the fuel range has changed
    uint8_t curr_level = ((ADC1->DR) / 10) * 100 / 409.5; // Read the converted value
    fuel_range_changed = (curr_level != fuel_level) ? 1 : 0;
    fuel_level = curr_level; // Read the converted value
    if (mode == LCD_ON && fuel_range_changed == 1)
    {
        lcd_print_int(FUEL_LEVEL_POS, FUEL_LEVEL_LINE, fuel_level, 1);
    }
}

void TIM2_IRQHandler()
{
    if (TIM2->SR & TIM_SR_UIF)
    {
        if (turn_indicator_status == TURN_INDICATOR_LEFT)
        {
            cpl_bit(LEFT_TURN_LAMP_PORT, LEFT_TURN_LAMP_PIN);
            cpl_bit(BUZZER_PORT, BUZZER_PIN);
        }
        else if (turn_indicator_status == TURN_INDICATOR_RIGHT)
        {
            cpl_bit(RIGHT_TURN_LAMP_PORT, RIGHT_TURN_LAMP_PIN);
            cpl_bit(BUZZER_PORT, BUZZER_PIN);
        }
        else if (turn_indicator_status == PARKING_LIGHT_ON)
        {
            cpl_bit(LEFT_TURN_LAMP_PORT, LEFT_TURN_LAMP_PIN);
            cpl_bit(RIGHT_TURN_LAMP_PORT, RIGHT_TURN_LAMP_PIN);
            cpl_bit(BUZZER_PORT, BUZZER_PIN);
        }

        TIM2->SR &= ~TIM_SR_UIF;
    }
}

void initialize_exti_buttons(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN; // Enable the clock for SYSCFG

    /**
     * Set EXTI3 (PB3 (SW2) - Ignition)
     * Set EXTI4 (PB4 (SW3) - Left Turn)
     * Set EXTI7 (PB7 (SW1) - Right Turn)
     * Set EXTI15 (PA15 (SW4) - Headlight)
     */
    SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI3_PB;  // Set EXTI3 to PB3
    SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI4_PB;  // Set EXTI4 to PB4
    SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI7_PB;  // Set EXTI5 to PB7
    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI15_PA; // Set EXTI15 to PA15

    EXTI->IMR |= EXTI_IMR_IM3;  // Unmask EXTI3
    EXTI->IMR |= EXTI_IMR_IM4;  // Unmask EXTI4
    EXTI->IMR |= EXTI_IMR_IM7;  // Unmask EXTI7
    EXTI->IMR |= EXTI_IMR_IM15; // Unmask EXTI15

    // EXTI->RTSR |= EXTI_RTSR_TR3;  // Set EXTI3 to rising edge
    // EXTI->RTSR |= EXTI_RTSR_TR4;  // Set EXTI4 to rising edge
    // EXTI->RTSR |= EXTI_RTSR_TR7;  // Set EXTI7 to rising edge
    // EXTI->RTSR |= EXTI_RTSR_TR15; // Set EXTI15 to rising edge

    EXTI->FTSR |= EXTI_FTSR_TR3;  // Set falling edge for EXTI3
    EXTI->FTSR |= EXTI_FTSR_TR4;  // Set falling edge for EXTI4
    EXTI->FTSR |= EXTI_FTSR_TR7;  // Set falling edge for EXTI7
    EXTI->FTSR |= EXTI_FTSR_TR15; // Set falling edge for EXTI15

    // uint32_t volatile *NVIC_ISER0 = (uint32_t *)0xE000E100; // Address of the NVIC ISER0 register
    // *NVIC_ISER0 |= (1 << 9);                                // Enable the EXTI3 global interrupt
    // *NVIC_ISER0 |= (1 << 10);                               // Enable the EXTI4 global interrupt
    // *NVIC_ISER0 |= (1 << 23);                               // Enable the EXTI9_5 global interrupt

    NVIC_EnableIRQ(EXTI3_IRQn);      // Enable the EXTI3 global interrupt
    NVIC_SetPriority(EXTI3_IRQn, 0); // Set the priority of the EXTI3 interrupt to 0 (highest priority)

    NVIC_EnableIRQ(EXTI4_IRQn);      // Enable the EXTI4 global interrupt
    NVIC_SetPriority(EXTI4_IRQn, 2); // Set the priority of the EXTI4 interrupt to 2 (third highest priority)

    NVIC_EnableIRQ(EXTI9_5_IRQn);      // Enable the EXTI9_5 global interrupt
    NVIC_SetPriority(EXTI9_5_IRQn, 3); // Set the priority of the EXTI9_5 interrupt to 3 (fourth highest priority)

    NVIC_EnableIRQ(EXTI15_10_IRQn);      // Enable the EXTI15_10 global interrupt
    NVIC_SetPriority(EXTI15_10_IRQn, 1); // Set the priority of the EXTI15_10 interrupt to 1 (second highest priority)
}

void EXTI3_IRQHandler(void)
{
    ignition_handler();
}

void EXTI4_IRQHandler(void)
{
    left_turn_handler();
}

void EXTI9_5_IRQHandler(void)
{
    right_turn_handler();
}

void EXTI15_10_IRQHandler(void)
{
    head_light_handler();
}

void ignition_handler(void)
{
    if (EXTI->PR & EXTI_PR_PR3)
    {
        if (engine_status == ENGINE_OFF)
        {
            set_ignition(ENGINE_ON);
            set_uart_status(UART_OK);
        }
        else if (engine_status == ENGINE_ON)
        {
            set_uart_status(UART_OFF);
            set_turn_indicator(TURN_INDICATOR_OFF);
            set_head_light(HEAD_LIGHT_OFF);
            set_ignition(ENGINE_OFF);
        }

        EXTI->PR |= EXTI_PR_PR3; // Clear the pending bit
    }
}

void left_turn_handler(void)
{
    if (EXTI->PR & EXTI_PR_PR4)
    {
        if (engine_status == ENGINE_OFF)
        {
            EXTI->PR |= EXTI_PR_PR4; // Clear the pending bit
            return;
        }

        if (turn_indicator_status == TURN_INDICATOR_LEFT)
        {
            set_turn_indicator(TURN_INDICATOR_OFF);
        }
        else
        {
            set_turn_indicator(TURN_INDICATOR_LEFT);
        }

        EXTI->PR |= EXTI_PR_PR4; // Clear the pending bit
    }
}
void right_turn_handler(void)
{
    if (EXTI->PR & EXTI_PR_PR7)
    {
        if (engine_status == ENGINE_OFF)
        {
            EXTI->PR |= EXTI_PR_PR7; // Clear the pending bit
            return;
        }

        if (turn_indicator_status == TURN_INDICATOR_RIGHT)
        {
            set_turn_indicator(TURN_INDICATOR_OFF);
        }
        else
        {
            set_turn_indicator(TURN_INDICATOR_RIGHT);
        }

        EXTI->PR |= EXTI_PR_PR7; // Clear the pending bit
    }
}

void head_light_handler(void)
{
    if (EXTI->PR & EXTI_PR_PR15)
    {
        if (engine_status == ENGINE_OFF)
        {
            EXTI->PR |= EXTI_PR_PR15; // Clear the pending bit
            return;
        }
        if (headlight_status == HEAD_LIGHT_OFF)
        {
            set_head_light(HEAD_LIGHT_LOW_BEAM);
        }
        else if (headlight_status == HEAD_LIGHT_LOW_BEAM)
        {
            set_head_light(HEAD_LIGHT_HIGH_BEAM);
        }
        else if (headlight_status == HEAD_LIGHT_HIGH_BEAM)
        {
            if (turn_indicator_status == TURN_INDICATOR_OFF)
            {
                set_turn_indicator(PARKING_LIGHT_ON);
            }
            else if (turn_indicator_status == PARKING_LIGHT_ON)
            {
                set_head_light(HEAD_LIGHT_OFF);
                set_turn_indicator(TURN_INDICATOR_OFF);
            }
            else
            {
                set_head_light(HEAD_LIGHT_OFF);
            }
        }

        EXTI->PR |= EXTI_PR_PR15; // Clear the pending bit
    }
}

void set_ignition(enum ENGINE_STATUS status)
{
    if (status == ENGINE_ON)
    {
        engine_status = ENGINE_ON;
        if (mode == LCD_ON)
        {
            lcd_print(ENGINE_STATUS_POS, ENGINE_STATUS_LINE, "ON ");
        }
        else
        {
            clr_bit(IGNITION_LED_PORT, IGNITION_LED_PIN);
        }
    }
    else if (status == ENGINE_OFF)
    {
        engine_status = ENGINE_OFF;
        if (mode == LCD_ON)
        {
            lcd_print(ENGINE_STATUS_POS, ENGINE_STATUS_LINE, "OFF");
        }
        else
        {
            set_bit(IGNITION_LED_PORT, IGNITION_LED_PIN);
        }
    }
}

void set_turn_indicator(enum TURN_INDICATOR_STATUS status)
{
    if (status == TURN_INDICATOR_OFF)
    {
        turn_indicator_status = TURN_INDICATOR_OFF;
        if (mode == LCD_OFF)
        {
            stop_timer();
            set_bit(LEFT_TURN_LAMP_PORT, LEFT_TURN_LAMP_PIN);
            set_bit(RIGHT_TURN_LAMP_PORT, RIGHT_TURN_LAMP_PIN);
            clr_bit(BUZZER_PORT, BUZZER_PIN);
        }
        else
        {
            lcd_print(TURN_STATUS_POS, TURN_STATUS_LINE, "OFF  ");
        }
    }
    else if (status == TURN_INDICATOR_LEFT)
    {
        turn_indicator_status = TURN_INDICATOR_LEFT;
        if (mode == LCD_OFF)
        {
            set_bit(LEFT_TURN_LAMP_PORT, LEFT_TURN_LAMP_PIN);
            set_bit(RIGHT_TURN_LAMP_PORT, RIGHT_TURN_LAMP_PIN);
            clr_bit(BUZZER_PORT, BUZZER_PIN);
            start_timer(1000);
        }
        else
        {
            lcd_print(TURN_STATUS_POS, TURN_STATUS_LINE, "LEFT ");
        }
    }
    else if (status == TURN_INDICATOR_RIGHT)
    {
        turn_indicator_status = TURN_INDICATOR_RIGHT;
        if (mode == LCD_OFF)
        {
            set_bit(LEFT_TURN_LAMP_PORT, LEFT_TURN_LAMP_PIN);
            set_bit(RIGHT_TURN_LAMP_PORT, RIGHT_TURN_LAMP_PIN);
            clr_bit(BUZZER_PORT, BUZZER_PIN);
            start_timer(1000);
        }
        else
        {
            lcd_print(TURN_STATUS_POS, TURN_STATUS_LINE, "RIGHT");
        }
    }
    else if (status == PARKING_LIGHT_ON)
    {
        turn_indicator_status = PARKING_LIGHT_ON;
        if (mode == LCD_OFF)
        {
            set_bit(LEFT_TURN_LAMP_PORT, LEFT_TURN_LAMP_PIN);
            set_bit(RIGHT_TURN_LAMP_PORT, RIGHT_TURN_LAMP_PIN);
            clr_bit(BUZZER_PORT, BUZZER_PIN);
            start_timer(250);
        }
        else
        {
            lcd_print(TURN_STATUS_POS, TURN_STATUS_LINE, "PARK ");
        }
    }
}

void set_head_light(enum HEAD_LIGHT_STATUS status)
{
    if (status == HEAD_LIGHT_OFF)
    {
        if (mode == LCD_OFF)
        {
            stop_pwm();
        }
        else
        {
            lcd_print(LIGHT_STATUS_POS, LIGHT_STATUS_LINE, "OFF");
        }
        headlight_status = HEAD_LIGHT_OFF;
    }
    else if (status == HEAD_LIGHT_LOW_BEAM)
    {
        headlight_status = HEAD_LIGHT_LOW_BEAM;
        if (mode == LCD_ON)
        {
            lcd_print(LIGHT_STATUS_POS, LIGHT_STATUS_LINE, "LOW");
        }
        else
        {
            start_pwm(10, 10000); // PWM with 10% duty cycle
        }
    }
    else if (status == HEAD_LIGHT_HIGH_BEAM)
    {
        headlight_status = HEAD_LIGHT_HIGH_BEAM;
        if (mode == LCD_ON)
        {
            lcd_print(LIGHT_STATUS_POS, LIGHT_STATUS_LINE, "HI ");
        }
        else
        {
            stop_pwm();
            start_pwm(90, 10000); // PWM with 90% duty cycle
        }
    }
}
