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
 * @param timx TIMx (x = 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 17)
 * @param duty_cycle Duty Cycle (0 - 1000)
 */
void set_duty_cycle(TIM_TypeDef *, uint16_t);

/**
 * @brief Set the frequency for the PWM
 * @param timx TIMx (x = 1, 2, 3, 4, 5, 6, 7, 8, 15, 16, 17)
 * @param frequency Frequency (Hz)
 */
void set_frequency(TIM_TypeDef *, uint16_t);

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
    if ((data == (uint8_t)UART_TRANSMIT_DATA))
    {
        if (uart_status != UART_OK)
        {
            lcd_print(2, 1, "OK   ");
        }
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

void set_duty_cycle(TIM_TypeDef *timx, uint16_t duty_cycle)
{
    timx->CCR1 = duty_cycle; // Set the duty cycle
}

void set_frequency(TIM_TypeDef *timx, uint16_t frequency)
{
    timx->ARR = (TIM_FREQ / frequency) - 1; // Set the auto-reload register
}