#include "Std_Types.h"

/***************************************************************************************
 *                     DIO FUNCTION DESCRIPTION AND DECLARATION
 ***************************************************************************************/
/*-----------------------------------------------------------------------------------
 Interface Name   : DioWriteChannel
 Syntax           : void Dio_WritePin(uint8 PinId,uint8 value)
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : PinId -> Id of the Dio channel(pin).
                    value -> Dio pin level.
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : None
 Description      : Function to set the pin level.
 -----------------------------------------------------------------------------------*/
void Dio_WritePin(uint8 PinId,uint8 value);
/*-----------------------------------------------------------------------------------
 Interface Name   : Dio_ReadPin
 Syntax           : Std_ReturnType Dio_ReadPin(uint8 PinId)
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : PinId -> Id of the Dio channel(pin).
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : STD_LOW  -> If the pin value is Low('0').
                    STD_HIGH -> If the pin value is High('1').
 Description      : Function to read the pin level and return it.
 -----------------------------------------------------------------------------------*/
Std_ReturnType Dio_ReadPin(uint8 PinId);
/*-----------------------------------------------------------------------------------
 Interface Name   : Dio_WritePort
 Syntax           : void Dio_WritePort(uint8 PortId,uint8 value)
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : PortId -> Id of the Dio port.
                    value  -> Dio port level.
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : None
 Description      : Function to set the port level.
 -----------------------------------------------------------------------------------*/
void Dio_WritePort(uint8 PortId,uint8 value);
/*-----------------------------------------------------------------------------------
 Interface Name   : Dio_ReadPort
 Syntax           : Std_ReturnType Dio_ReadPin(uint8 PortId)
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : PortId -> Id of the Dio channel(pin).
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : STD_LOW  -> If the pin value is Low('0').
                    STD_HIGH -> If the pin value is High('1').
 Description      : Function to read the pin level and return it.
 -----------------------------------------------------------------------------------*/
Std_ReturnType Dio_ReadPort(uint8 PortId);

