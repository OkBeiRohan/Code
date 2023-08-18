/*
 * lcd.h
 *
 *  Created on: Jul 27, 2023
 *      Author: WON1COB
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32f4xx.h"

/**
 * Register Select for LCD
 */
#define PORT_RS GPIOA
#define PIN_RS 0

/**
 * LCD Enable Pin
 */
#define PORT_EN GPIOA
#define PIN_EN 1

/**
 * Data Pins for LCD
 */
#define PORT_D0 GPIOC
#define PIN_D0 4

#define PORT_D1 GPIOC
#define PIN_D1 5

#define PORT_D2 GPIOB
#define PIN_D2 0

#define PORT_D3 GPIOB
#define PIN_D3 1

#define PORT_D4 GPIOB
#define PIN_D4 12

#define PORT_D5 GPIOB
#define PIN_D5 13

#define PORT_D6 GPIOB
#define PIN_D6 14

#define PORT_D7 GPIOB
#define PIN_D7 15

#define true 1
#define false 0

/**
 * @brief LCD Modes
 */
enum lcd_modes
{
    CLEAR_SCREEN,
    RETURN_HOME,
    INCREMENT_CURSOR,
    CURSOR_BLINK,
    CURSOR_NOBLINK,
    CURSOR_LINE1_BEGINNING,
    CURSOR_LINE2_BEGINNING,
    DISPLAY_ON,
    DISPLAY_OFF,
    CURSOR_ON,
    CURSOR_OFF,
    BIT_8_MODE,
    BIT_4_MODE,
};

/**
 * @brief Configure a GPIO pin as output
 * @param gpio GPIO port
 * @param pin GPIO pin
 */
void set_output(GPIO_TypeDef *gpio, uint32_t pin);

/**
 * @brief Configure a GPIO pin as input
 * @param gpio GPIO port
 * @param pin GPIO pin
 */
void set_input(GPIO_TypeDef *gpio, uint32_t pin);

/**
 * @brief Configure a GPIO pin as analog
 * @param gpio GPIO port
 * @param pin GPIO pin
 */
void set_analog(GPIO_TypeDef *gpio, uint32_t pin);

/**
 * @brief Configure a GPIO pin as pull-up
 * @param gpio GPIO port
 * @param pin GPIO pin
 */
void set_pull_up(GPIO_TypeDef *gpio, uint32_t pin);

/**
 * @brief Configure a GPIO pin as pull-down
 * @param gpio GPIO port
 * @param pin GPIO pin
 */
void set_alternate(GPIO_TypeDef *gpio, uint32_t pin);

/**
 * @brief Set the value of a GPIO pin as 1
 * @param gpio GPIO port
 * @param pin GPIO pin
 */
void set_bit(GPIO_TypeDef *gpio, uint32_t pin);

/**
 * @brief Reset the value of a GPIO pin (Set as 0)
 * @param gpio GPIO port
 * @param pin GPIO pin
 */
void clr_bit(GPIO_TypeDef *gpio, uint32_t pin);

/**
 * @brief Toggle the value of a GPIO pin
 * @param gpio GPIO port
 * @param pin GPIO pin
 */
void cpl_bit(GPIO_TypeDef *gpio, uint32_t pin);

/**
 * @brief Software delay
 * @param delay_ms Delay in milliseconds
 */
void delay(uint32_t delay_ms);

/**
 * @brief Initialize the LCD
 */
void lcd_init(enum lcd_modes bit_operation);

/**
 * @brief Send a command to the LCD
 * @param is_command 1 if the data is a command, 0 if the data is a character
 * @param value The command to be sent
 */
void lcd_fn(uint8_t is_command, uint8_t value);

/**
 * @brief Print a string to the LCD
 * @param position The position of the cursor
 * @param line The line of the cursor
 * @param str The string to be printed
 */
void lcd_print(uint8_t position, uint8_t line, char *str);

/**
 * @brief Print an integer to the LCD
 * @param position The position of the cursor
 * @param line The line of the cursor
 * @param dval The integer to be printed
 * @param print_leading_zero 1 if leading zeros should be printed, 0 if not
 */
void lcd_print_int(uint8_t position, uint8_t line, uint32_t dval, uint8_t print_leading_zero);

/**
 * @brief Set the mode of the LCD
 * @param mode The mode to be set
 */
void set_lcd_mode(enum lcd_modes mode);

#endif /* LCD_H_ */