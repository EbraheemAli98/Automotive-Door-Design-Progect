#ifndef DOOR_SENSOR_H_
#define DOOR_SENSOR_H_

#include "Std_Types.h"

#define DOOR_PIN_ID PIN1

 /*-----------------------------------------------------------------------------------
 Interface Name   : DoorSensor_GetState
 Syntax           : uint8 DoorSensor_GetState()
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : None
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : Door state
 Description      : Function responsible for read Door state.
 -----------------------------------------------------------------------------------*/
uint8 DoorSensor_GetState();

#endif