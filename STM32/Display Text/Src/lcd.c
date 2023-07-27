/*
 * lcd.c
 *
 *  Created on: Jul 27, 2023
 *      Author: WON1COB
 */

#include <lcd.h>

void set_output(GPIO_TypeDef *gpio, uint32_t pin)
{
    gpio->MODER |= (1 << (pin * 2));
    gpio->MODER &= ~(1 << ((pin * 2) + 1));
}

void set_bit(GPIO_TypeDef *gpio, uint32_t pin)
{
    gpio->ODR |= (1 << pin);
}

void clr_bit(GPIO_TypeDef *gpio, uint32_t pin)
{
    gpio->ODR &= ~(1 << pin);
}

void cpl_bit(GPIO_TypeDef *gpio, uint32_t pin)
{
    gpio->ODR ^= (1 << pin);
}

void delay_lcd(uint32_t delay_ms)
{
    uint32_t counter;
    for (counter = 0; counter < delay_ms * 16800; counter++)
        ;
}

void lcd_init(uint8_t enable_8_bit)
{
    /**
     * Enable Ports A and B
     */
    RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN);
    RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOBEN);

    /**
     * Set the pins as output
     */
    set_output(PORT_RS, PIN_RS);
    set_output(PORT_EN, PIN_EN);

    if (enable_8_bit)
    {
        set_output(PORT_D0, PIN_D0);
        set_output(PORT_D1, PIN_D1);
        set_output(PORT_D2, PIN_D2);
        set_output(PORT_D3, PIN_D3);
    }
    set_output(PORT_D4, PIN_D4);
    set_output(PORT_D5, PIN_D5);
    set_output(PORT_D6, PIN_D6);
    set_output(PORT_D7, PIN_D7);

    /**
     * Initialize the LCD
     */
    lcd_fn(0, 0x33);
    lcd_fn(0, 0x32);
    lcd_fn(0, 0x28);
    lcd_fn(0, 0x0c);
    lcd_fn(0, 0x01);
}

void lcd_fn(uint8_t is_command, uint8_t value)
{
}

void lprint(uint8_t position, char *str) {}

void aprint(uint32_t dval) {}