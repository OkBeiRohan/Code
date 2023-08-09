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

#ifndef ECU_H_
#define ECU_H_

enum ENGINE_STATUS
{
    ENGINE_OFF,
    ENGINE_ON
};

enum TURN_INDICATOR_STATUS
{
    TURN_INDICATOR_OFF,
    TURN_INDICATOR_LEFT,
    TURN_INDICATOR_RIGHT
};

enum HEAD_LIGHT_STATUS
{
    HEAD_LIGHT_OFF,
    HEAD_LIGHT_LOW_BEAM,
    HEAD_LIGHT_HIGH_BEAM,
    PARKING_LIGHT_ON
};

#endif /* ECU_H_ */