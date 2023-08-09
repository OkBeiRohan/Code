/**
 ******************************************************************************
 * @file           : ecu.h
 * @author         : Rohan K
 * @brief          : ECU Controls
 ******************************************************************************
 * @details
 * Main ECU functions are wrapped here
 ******************************************************************************
 */

#include <stm32f405xx.h>

#ifndef ECU_H_
#define ECU_H_

#define IGNITION_KEY_PORT GPIOC
#define IGNITION_KEY_PIN 0

#define LEFT_TURN_LAMP_PORT GPIOC
#define LEFT_TURN_LAMP_PIN 0

#define RIGHT_TURN_LAMP_PORT GPIOC
#define RIGHT_TURN_LAMP_PIN 0

#define HEAD_LIGHT_PORT GPIOC
#define HEAD_LIGHT_PIN 0

#define FUEL_INDICATOR_PORT GPIOC
#define FUEL_INDICATOR_PORT 0

/**
 * The statuses available for the engine (ignition)
 * OFF: The engine is turned OFF
 * ON: The engine is turned ON
 */
enum ENGINE_STATUS
{
    ENGINE_OFF,
    ENGINE_ON
};

/**
 * Statuses available for the turn indicator
 * OFF: No turn indicator is working or is turned OFF
 * LEFT: Left turn indicator is turned ON
 * RIGHT: Right turn indicator is turned ON
 */
enum TURN_INDICATOR_STATUS
{
    TURN_INDICATOR_OFF,
    TURN_INDICATOR_LEFT,
    TURN_INDICATOR_RIGHT
};

/**
 * Statuses available for the headlight
 * OFF: Headlights are turned OFF
 * LOW: Headlights are dimmed (Low intensity)
 * HIGH: Headlights are bright (High intensity)
 * PARKING: Parking lights are ON
 */
enum HEAD_LIGHT_STATUS
{
    HEAD_LIGHT_OFF,
    HEAD_LIGHT_LOW_BEAM,
    HEAD_LIGHT_HIGH_BEAM,
    PARKING_LIGHT_ON
};

/**
 * Status of the UART transmission
 * OK: The transferred data is successfully received
 * NOTOK: The transferred data is corrupted or lost
 */
enum UART_STATUS
{
    UART_OK,
    UART_NOT_OK
};

void initialize_ecu(void);
void set_turn_indicator(enum TURN_INDICATOR_STATUS);
void set_head_light(enum HEAD_LIGHT_STATUS);
void set_ignition(enum ENGINE_STATUS);

#endif /* ECU_H_ */