#include "Dio.h"

void Dio_WritePin(uint8 PinId,uint8 value)
{
    /*
     * 1. identify the PinId.
     * 2. set the Pin value.
     */
}

Std_ReturnType Dio_ReadPin(uint8 PinId)
{
    /*
     * 1. identify the pinId.
     * 2. read the pin value.
     * 3. return STD_HIGH if pin value is HIGH.
     *    Otherwise, return STD_LOW.
     */
}

void Dio_WritePort(uint8 PortId,uint8 value)
{
    /*
     * 1. identify the PortId.
     * 2. write the port value.
     */
}

Std_ReturnType Dio_ReadPort(uint8 PortId)
{
    /*
     * 1. identify the portId.
     * 2. read the port value.
     * 3. retunn STD_HIGH if port value is HIGH.
     *    Otherwise, return STD_LOW.
     */
}