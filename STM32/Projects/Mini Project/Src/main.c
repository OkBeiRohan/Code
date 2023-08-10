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
  set_mode(LCD_ON);
  initialize_ecu();

  while (1)
  {
    uart_signal_check();
    check_fuel_status();
  }
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
