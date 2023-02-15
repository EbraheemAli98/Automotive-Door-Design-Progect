#include "Port.h"

const Port_ConfigType Port_ConfigObj =
{0/*Pin0*/,1/*Port1*/,OUTPUT,DIO,DIGITAL,0/*LOW*/ };

void Port_Init(const Port_ConfigType* const ConfigPtr)
{
    // 1. Set Pin Direction
    // 2. Set pin mode
    // 3. Set pin signal
    // 4. Set pin initial value
}

void Port_DeInit(void){}