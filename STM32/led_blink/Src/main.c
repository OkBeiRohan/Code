/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Blink LED
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
 ******************************************************************************
 * Program to blink the on-board LED on PC6 (LED1).
 */

#include <stdint.h>

void blink_led(uint32_t *);
void delay(uint32_t);

int main(void)
{
    /**
     * To blink LED, enable the clock for the General Purpose I/O (GPIO) port C.
     * Base address of the clock enable register (RCC_AHB1ENR) = 0x4002 3800
     * Offset address = 0x30
     * Address = 0x4002 3830
     * For LED1, Port PC6 have to be enabled. For that enable GPIOCEN bit. (At 2nd position)
     */
    uint32_t *ptr_RCC_AHB1ENR = (uint32_t *)0x40023830;
    *ptr_RCC_AHB1ENR |= (1 << 2); // Set bit 2

    /**
     * Set the mode of the pin PC6 to output mode.
     * Base address of the GPIO port C = 0x4002 0800
     * Offset address of the mode register = 0x00
     * Address = 0x4002 0800
     * For LED1, Pin PC6 have to be set to output mode. For that set GPIOC6 bit. (At 12th position)
     * Output Mode = 01
     */
    uint32_t *ptr_GPIOC_MODER = (uint32_t *)0x40020800;
    *ptr_GPIOC_MODER |= (1 << 12);  // Set bit 12
    *ptr_GPIOC_MODER &= ~(1 << 13); // Clear bit 13

    /**
     * Change the output bit through the port PC6 using the Output Data Register (ODR)
     * Base address of the GPIO port C = 0x4002 0800
     * Offset address of the mode register = 0x14
     * Address = 0x4002 0814
     * For turning the LED ON, reset the ODR6 bit. For turning it OFF, set the ODR6 bit
     */
    uint32_t *ptr_GPIOC_ODR = (uint32_t *)0x40020814;

    blink_led(ptr_GPIOC_ODR);
}

/**
 * Function to blink the LED
 * @param ptr_GPIOC_ODR Pointer to the GPIOC_ODR register
 * @return None
 */
void blink_led(uint32_t *ptr_GPIOC_ODR)
{

    /**
     * Blink LEDs indefinitely
     */
    while (1)
    {
        /**
         * Set the OD6 bit to turn off the LED
         */
        *ptr_GPIOC_ODR |= (1 << 6);

        /**
         * Wait for 1 second
         */

        delay(1000);

        /**
         * Reset the OD6 bit to turn on the LED
         */
        *ptr_GPIOC_ODR &= ~(1 << 6);

        /**
         * Wait for 1 second
         */
        delay(1000);
    }
}

/**
 * Function to generate delay
 * @param delay_ms Delay in milliseconds
 * @return None
 */
void delay(uint32_t delay_ms)
{
    uint32_t counter;
    for (counter = 0; counter < (delay_ms * 1000); counter++)
        ;
}