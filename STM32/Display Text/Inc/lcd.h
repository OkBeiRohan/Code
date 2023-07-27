/*
 * lcd.h
 *
 *  Created on: Jul 27, 2023
 *      Author: WON1COB
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32f405xx.h"

/**
 * Register Select
 */
#define PORT_RS GPIOA
#define PIN_RS 0

/**
 * LCD Enable
 */
#define PORT_EN GPIOA
#define PIN_EN 1

/**
 * Data Pins
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

void set_output(GPIO_TypeDef *, uint32_t); // gpio->MODER
void set_bit(GPIO_TypeDef *, uint32_t);    // gpio->ODR|=(1<<pin)
void clr_bit(GPIO_TypeDef *, uint32_t);
void cpl_bit(GPIO_TypeDef *, uint32_t);
void delay(uint32_t);
void lcd_init(uint8_t);
void lcd_fn(uint8_t, uint8_t);
void lcd_print(uint8_t, uint8_t, char *);
void aprint(uint32_t);

#endif /* LCD_H_ */
