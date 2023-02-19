#include "Lights.h"
#include "Dio.h"

void Lights_ON(void)
{
    Dio_WritePin(R_LIGHT_PIN_ID,STD_HIGH);
    Dio_WritePin(L_LIGHT_PIN_ID,STD_HIGH);
}

void Lights_OFF(void)
{
    Dio_WritePin(R_LIGHT_PIN_ID,STD_LOW);
    Dio_WritePin(L_LIGHT_PIN_ID,STD_LOW);
}