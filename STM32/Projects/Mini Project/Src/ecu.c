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
}