#include "LightSwitch.h"
#include "Dio.h"

uint8 LightSwitch_GetState(void)
{
    return (Dio_ReadPin(LIGHT_SWITCH_PIN_ID));
}