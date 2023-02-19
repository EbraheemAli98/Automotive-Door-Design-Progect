#include "DoorSensor.h"
#include "Dio.h"

uint8 DoorSensor_GetState()
{
    return (Dio_ReadPin(DOOR_PIN_ID));
}