#include "Buzzer.h"
#include "Dio.h"

void Buzzer_ON(void)
{
    Dio_WritePin(BUZZER_PIN_ID,STD_HIGH);
}

void Bzzer_OFF(void)
{
    Dio_WritePin(BUZZER_PIN_ID,STD_LOW);
}