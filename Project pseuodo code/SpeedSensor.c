#include "SpeedSensor.h"
#include "ADC.h"

uint8 SpeedSensor_GetSpeed()
{
    return (ADC_ReadChannel(SPEED_SENSOR_ADC_CHANNEL));
}