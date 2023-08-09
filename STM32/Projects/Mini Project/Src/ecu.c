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

enum UART_STATUS uart_status = UART_OK;
enum HEAD_LIGHT_STATUS headlight_status = HEAD_LIGHT_OFF;
enum TURN_INDICATOR_STATUS turn_indicator_status = TURN_INDICATOR_OFF;
enum ENGINE_STATUS engine_status = ENGINE_OFF;

/**
 * @brief Initialize the UART
 */
void initialize_uart(void);

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
 */
void uart_write(uint8_t);

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

void initialize_ecu(void)
{
    /**
     * Initialize the LCD
     */
    lcd_init(BIT_4_MODE);
    lcd_print(0, 0, "Initializing");
    lcd_print(0, 1, "Please Wait!");

    /**
     * Enable the clock for GPIOA, GPIOB and GPIOC
     */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN;

    /**
     * Configure the modes for the GPIO ports (Switches, LEDs, Buzzer and Potentiometer)
     */
    set_input(IGNITION_KEY_PORT, IGNITION_KEY_PIN); // Ignition Key

    set_output(LEFT_TURN_LAMP_PORT, LEFT_TURN_LAMP_PIN);    // Left Turn Lamp
    set_input(LEFT_TURN_SWITCH_PORT, LEFT_TURN_SWITCH_PIN); // Left Turn Switch

    set_output(RIGHT_TURN_LAMP_PORT, RIGHT_TURN_LAMP_PIN);    // Right Turn Lamp
    set_input(RIGHT_TURN_SWITCH_PORT, RIGHT_TURN_SWITCH_PIN); // Right Turn Switch

    set_alternate(HEAD_LIGHT_PORT, HEAD_LIGHT_PIN);           // Head Light
    set_input(HEAD_LIGHT_SWITCH_PORT, HEAD_LIGHT_SWITCH_PIN); // Head Light Switch

    set_output(BUZZER_PORT, BUZZER_PIN); // Buzzer

    set_analog(FUEL_INDICATOR_PORT, FUEL_INDICATOR_PIN); // Fuel Indicator

    initialize_pwm();
    initialize_uart();
    initialize_timer();
    initialize_exti_buttons();

    set_lcd_mode(CLEAR_SCREEN);
    lcd_print(0, 0, "CAR:OFF");
    lcd_print(0, 1, "U:OK");
}

void initialize_uart(void)
{
    /**
     * Configure UART4_TX (PA0 - AF8), UART4_RX (PA1 - AF8)
     */
    GPIOA->AFR[0] |= (0x8 << 0) | (0x8 << 4); // Set AF8 for PA0 and PA1
    set_alternate(GPIOA, 0);                  // Set PA0 to alternate function mode
    set_alternate(GPIOA, 1);                  // Set PA1 to alternate function mode

    RCC->APB1ENR |= RCC_APB1ENR_UART4EN;                      // Enable the clock for UART4
    UART4->BRR = 0x683;                                       // Set the baud rate to 9600
    UART4->CR3 = 0x0;                                         // Disable the hardware flow control
    UART4->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE; // Enable the UART, Transmitter and Receiver
}

void uart_write(uint8_t data)
{
    while (!(UART4->SR & USART_SR_TXE))
        ;             // Wait for the transmit buffer to be empty
    UART4->DR = data; // Write the data to the transmit buffer
}

uint8_t uart_read(void)
{
    while (!(UART4->SR & USART_SR_RXNE))
        ;             // Wait for the receive buffer to be empty
    return UART4->DR; // Read the data from the receive buffer
}

void uart_signal_check(void)
{
    uart_write((uint8_t)UART_TRANSMIT_DATA);
    uint8_t data = uart_read();

    if ((data == (uint8_t)UART_TRANSMIT_DATA) && (uart_status != UART_OK))
    {
        lcd_print(2, 1, "OK   ");
    }
    else
    {
        if (uart_status != UART_NOT_OK)
        {
            lcd_print(2, 1, "ERROR");
        }
    }
}

void initialize_pwm(void)
{
    GPIOC->AFR[0] |= (0x2 << 24); // Set AF2 for PC6 (TIM3_CH1)

    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; // Enable the clock for TIM3
    TIM3->PSC = 0x0;                    // Set the prescaler to 0
    TIM3->CNT = 0x0;                    // Set the counter to 0
    // TIM3->ARR = 0x3E8;                                  // Set the auto-reload register to 1000
    TIM3->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; // Set the PWM mode to PWM mode 1
    TIM3->CCMR1 |= TIM_CCMR1_OC1PE;                     // Enable the preload register (Output Compare 1)
    TIM3->CCER |= TIM_CCER_CC1E;                        // Enable the Capture/Compare 1 output for channel 1
    // TIM3->CR1 |= TIM_CR1_ARPE;                          // Enable the auto-reload preload register
    TIM3->CR1 |= TIM_CR1_CEN; // Enable the counter and enable the auto-reload preload register
}

void start_pwm(uint16_t duty_cycle, uint16_t frequency)
{
    TIM3->CCR1 = duty_cycle;                // Set the duty cycle
    TIM3->ARR = (TIM_FREQ / frequency) - 1; // Set the auto-reload register
    TIM3->CR1 |= TIM_CR1_CEN;               // Enable the counter and enable the auto-reload preload register
}

void stop_pwm()
{
    TIM3->CR1 &= ~TIM_CR1_CEN; // Disable the counter
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

void TIM2_IRQHandler()
{
    if (TIM2->SR & TIM_SR_UIF)
    {
        TIM2->SR &= ~TIM_SR_UIF;
    }

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
    else if (headlight_status == PARKING_LIGHT_ON)
    {
        set_duty_cycle(TIM3, 0);
        cpl_bit(BUZZER_PORT, BUZZER_PIN);
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

    EXTI->RTSR |= EXTI_RTSR_TR3;  // Set EXTI3 to rising edge
    EXTI->RTSR |= EXTI_RTSR_TR4;  // Set EXTI4 to rising edge
    EXTI->RTSR |= EXTI_RTSR_TR7;  // Set EXTI7 to rising edge
    EXTI->RTSR |= EXTI_RTSR_TR15; // Set EXTI15 to rising edge

    // EXTI->FTSR |= EXTI_FTSR_TR3;  // Set EXTI3 to falling edge

    uint32_t volatile *NVIC_ISER0 = (uint32_t *)0xE000E100; // Address of the NVIC ISER0 register
    *NVIC_ISER0 |= (1 << 3);                                // Enable the EXTI3 global interrupt
    *NVIC_ISER0 |= (1 << 4);                                // Enable the EXTI4 global interrupt
    *NVIC_ISER0 |= (1 << 7);                                // Enable the EXTI7 global interrupt
    *NVIC_ISER0 |= (1 << 15);                               // Enable the EXTI15_10 global interrupt
    *NVIC_ISER0 |= (1 << 23);                               // Enable the EXTI3 global interrupt
}

void EXTI3_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR3)
    {
        EXTI->PR |= EXTI_PR_PR3; // Clear the pending bit

        if (engine_status == ENGINE_OFF)
        {
            set_ignition(ENGINE_ON);
        }
        else if (engine_status == ENGINE_ON)
        {
            set_ignition(ENGINE_OFF);
            set_turn_indicator(TURN_INDICATOR_OFF);
            set_head_light(HEAD_LIGHT_OFF);
        }
    }
}

void EXTI4_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR4)
    {
        EXTI->PR |= EXTI_PR_PR4; // Clear the pending bit

        if (engine_status == ENGINE_OFF || headlight_status == PARKING_LIGHT_ON)
        {
            return;
        }

        if (turn_indicator_status == TURN_INDICATOR_OFF)
        {
            set_turn_indicator(TURN_INDICATOR_LEFT);
        }
        else if (turn_indicator_status == TURN_INDICATOR_LEFT)
        {
            set_turn_indicator(TURN_INDICATOR_OFF);
        }
    }
}

void EXTI9_5_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR7)
    {
        EXTI->PR |= EXTI_PR_PR7; // Clear the pending bit

        if (engine_status == ENGINE_OFF || headlight_status == PARKING_LIGHT_ON)
        {
            return;
        }

        if (turn_indicator_status == TURN_INDICATOR_OFF)
        {
            set_turn_indicator(TURN_INDICATOR_RIGHT);
        }
        else if (turn_indicator_status == TURN_INDICATOR_RIGHT)
        {
            set_turn_indicator(TURN_INDICATOR_OFF);
        }
    }
}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI->PR & EXTI_PR_PR15)
    {
        EXTI->PR |= EXTI_PR_PR15; // Clear the pending bit

        if (engine_status == ENGINE_OFF)
        {
            return;
        }

        if (headlight_status == HEAD_LIGHT_OFF)
        {
            set_head_light(HEAD_LIGHT_LOW_BEAM);
            lcd_print(9, 0, "LOW  ");
        }
        else if (headlight_status == HEAD_LIGHT_LOW_BEAM)
        {
            set_head_light(HEAD_LIGHT_HIGH_BEAM);
            lcd_print(9, 0, "HIGH ");
        }
        else if (headlight_status == HEAD_LIGHT_HIGH_BEAM)
        {
            if (turn_indicator_status == TURN_INDICATOR_OFF)
            {
                set_head_light(PARKING_LIGHT_ON);
                lcd_print(9, 0, "PARK ");
            }
            else
            {
                set_head_light(HEAD_LIGHT_OFF);
                lcd_print(9, 0, "OFF ");
            }
        }
    }
}

void set_ignition(enum ENGINE_STATUS status)
{
    if (status == ENGINE_ON)
    {
        engine_status = ENGINE_ON;
        lcd_print(4, 0, "ON ");
    }
    else if (status == ENGINE_OFF)
    {
        engine_status = ENGINE_OFF;
        lcd_print(4, 0, "OFF");
    }
}

void set_turn_indicator(enum TURN_INDICATOR_STATUS status)
{
    if (status == TURN_INDICATOR_OFF)
    {
        turn_indicator_status = TURN_INDICATOR_OFF;
        stop_timer();
        lcd_print(9, 1, "OFF  ");
    }
    else if (status == TURN_INDICATOR_LEFT)
    {
        turn_indicator_status = TURN_INDICATOR_LEFT;
        start_timer(1000);
        lcd_print(9, 1, "LEFT ");
    }
    else if (status == TURN_INDICATOR_RIGHT)
    {
        turn_indicator_status = TURN_INDICATOR_RIGHT;
        start_timer(1000);
        lcd_print(9, 1, "RIGHT");
    }
}

void set_head_light(enum HEAD_LIGHT_STATUS status)
{
    if (status == HEAD_LIGHT_OFF)
    {
        headlight_status = HEAD_LIGHT_OFF;
        lcd_print(9, 0, "OFF ");
    }
    else if (status == HEAD_LIGHT_LOW_BEAM)
    {
        headlight_status = HEAD_LIGHT_LOW_BEAM;
        lcd_print(9, 0, "LOW ");
    }
    else if (status == HEAD_LIGHT_HIGH_BEAM)
    {
        headlight_status = HEAD_LIGHT_HIGH_BEAM;
        lcd_print(9, 0, "HIGH");
    }
    else if (status == PARKING_LIGHT_ON)
    {
        headlight_status = PARKING_LIGHT_ON;
        lcd_print(9, 0, "PARK");
    }
}