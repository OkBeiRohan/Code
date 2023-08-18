/**
 ******************************************************************************
 * @file           : main.c
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

#include <stdint.h>
#include <ecu.h>

int main(void)
{
  initialize_ecu(LCD_ON); // Initialize ECU with LCD ON

  while (1)
  {
    uart_signal_check(); // Check for UART signal
    check_fuel_status(); // Check for fuel status
  }
}