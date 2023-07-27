/*
 * lcd.c
 *
 *  Created on: Jul 27, 2023
 *      Author: WON1COB
 */

#include <lcd.h>

uint8_t enable_8_bit;

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

void delay(uint32_t delay_ms)
{
    uint32_t counter, ms_counter;
    for (ms_counter = 0; ms_counter < delay_ms; ms_counter++)
        for (counter = 0; counter < 16800; counter++)
            ;
}

void lcd_init(uint8_t bit_8)
{
    if (bit_8 == 0)
    {
        enable_8_bit = 0;
    }
    else
    {
        enable_8_bit = 1;
    }

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
    if (value & (1 << 7))
    {
        set_bit(PORT_D7, PIN_D7);
    }
    else
    {
        clr_bit(PORT_D7, PIN_D7);
    }

    if (value & (1 << 6))
    {
        set_bit(PORT_D6, PIN_D6);
    }
    else
    {
        clr_bit(PORT_D6, PIN_D6);
    }

    if (value & (1 << 5))
    {
        set_bit(PORT_D5, PIN_D5);
    }
    else
    {
        clr_bit(PORT_D5, PIN_D5);
    }

    if (value & (1 << 4))
    {
        set_bit(PORT_D4, PIN_D4);
    }
    else
    {
        clr_bit(PORT_D4, PIN_D4);
    }

    if (enable_8_bit)
    {
        if (value & (1 << 3))
        {
            set_bit(PORT_D3, PIN_D3);
        }
        else
        {
            clr_bit(PORT_D3, PIN_D3);
        }

        if (value & (1 << 2))
        {
            set_bit(PORT_D2, PIN_D2);
        }
        else
        {
            clr_bit(PORT_D2, PIN_D2);
        }

        if (value & (1 << 1))
        {
            set_bit(PORT_D1, PIN_D1);
        }
        else
        {
            clr_bit(PORT_D1, PIN_D1);
        }

        if (value & (1 << 0))
        {
            set_bit(PORT_D0, PIN_D0);
        }
        else
        {
            clr_bit(PORT_D0, PIN_D0);
        }
    }

    /**
     * Set the RS pin
     */
    if (is_command)
    {
        set_bit(PORT_RS, PIN_RS);
    }
    else
    {
        clr_bit(PORT_RS, PIN_RS);
    }

    /**
     * Set the EN pin
     */
    set_bit(PORT_EN, PIN_EN);
    delay(1);
    clr_bit(PORT_EN, PIN_EN);
    delay(1);

    if (enable_8_bit == 0)
    {
        if (value & (1 << 3))
        {
            set_bit(PORT_D7, PIN_D7);
        }
        else
        {
            clr_bit(PORT_D7, PIN_D7);
        }

        if (value & (1 << 2))
        {
            set_bit(PORT_D6, PIN_D6);
        }
        else
        {
            clr_bit(PORT_D6, PIN_D6);
        }

        if (value & (1 << 1))
        {
            set_bit(PORT_D5, PIN_D5);
        }
        else
        {
            clr_bit(PORT_D5, PIN_D5);
        }

        if (value & (1 << 0))
        {
            set_bit(PORT_D4, PIN_D4);
        }
        else
        {
            clr_bit(PORT_D4, PIN_D4);
        }

        /**
         * Set the RS pin
         */
        if (is_command)
        {
            set_bit(PORT_RS, PIN_RS);
        }
        else
        {
            clr_bit(PORT_RS, PIN_RS);
        }

        /**
         * Set the EN pin
         */
        set_bit(PORT_EN, PIN_EN);
        delay(1);
        clr_bit(PORT_EN, PIN_EN);
        delay(1);
    }
}

void lcd_print(uint8_t position, uint8_t line, char *str)
{
    uint8_t i = 0;
    lcd_fn(0, 0x80 | (position + (line * 0x40)));

    while (str[i] != '\0')
    {
        lcd_fn(1, str[i]);
        i++;
    }
}

void aprint(uint32_t dval) {}