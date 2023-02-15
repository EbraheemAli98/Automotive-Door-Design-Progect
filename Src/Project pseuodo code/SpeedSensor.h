#ifndef SPEED_SENSOR_H_
#define SPEED_SENSOR_H_

#include "Std_Types.h"

#define SPEED_SENSOR_ADC_CHANNEL    ADC0
 /*-----------------------------------------------------------------------------------
 Interface Name   : SpeedSensor_GetSpeed
 Syntax           : uint8 SpeedSensor_GetSpeed()
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : None.
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : Speed of the car
 Description      : Function responsible for read speed of the car.
 -----------------------------------------------------------------------------------*/
uint8 SpeedSensor_GetSpeed();

#endif