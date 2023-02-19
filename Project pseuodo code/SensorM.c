#include "SensorM.h"

void SensorM_GetState(uint8 SensorId,uint8* value)
{
    switch (SensorId)
    {
    case SPEED_SENSOR_ID:
        *value = SpeedSensor_GetSpeed();
        break;
    case DOOR_SENSOR_ID:
        *value = DoorSensor_GetState();
        break;
    default:
        break;
    }
}