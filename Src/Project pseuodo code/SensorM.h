#ifndef SENSORM_H_
#define SENSORM_H_

#define SPEED_SENSOR_ID     1
#define DOOR_SENSOR_ID      2

/*--------------------------------------------------------------------------------------------
Name  : SensorM_GetState
Syntax: void SensorM_GetState(uint8 SensorId,uint8* value)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  
    [SensorId]: The Id of the sensor.
    [value]: pointer to the value of the sensor
Parameters[in/out]: None
Parameters[out]: None
Return value: None 
Description : Function to read the value of a specific sensor.
----------------------------------------------------------------------------------------------*/
void SensorM_GetState(uint8 SensorId,uint8* value);

#endif 