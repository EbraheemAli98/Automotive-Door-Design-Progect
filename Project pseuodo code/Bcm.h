#ifndef BCM_H_
#define BCM_H_

#include "CanIf.h"

#define SPEED_MESSAGE_ID    0x10
#define DOOR_MESSAGE_ID     0x11
#define SWITCH_MESSAGE_ID   0x12



extern const CanIf_PduConfigType Bcm_PduObj;

/*****************************************************************************************************
 *                          BCM FUNCTIONS DESCRIPTION AND DECLARATION
 *****************************************************************************************************/
/*--------------------------------------------------------------------------------------------
Name  : Bcm_Init
Syntax: void Bcm_Init(void)
Sync/Async: Synchronous
Reentrancy: Non-Reentrant
Parameters[in]: None             
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : This Interface initialize the CAN module. 
----------------------------------------------------------------------------------------------*/
void Bcm_Init(void);
/*--------------------------------------------------------------------------------------------
Name  : Bcm_SendMessage
Syntax: void Bcm_SendMessage(uint8 ControllerId,const PduInfoType* DataPtr)
Sync/Async: Synchronous
Reentrancy: Non-Reentrant
Parameters[in]:
    [ControllerId]: the id of the CAN controller.
    [DataPtr]:  pointer to the CAN PDU (Protocol Data Uint)          
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : This Interface used to send the message via CAN Module. 
----------------------------------------------------------------------------------------------*/
void Bcm_SendMessage(uint8 ControllerId,const PduInfoType* DataPtr);
/*--------------------------------------------------------------------------------------------
Name  : Bcm_ReceiveMessage
Syntax: uint8 Bcm_ReceiveMessage(uint8 ControllerId,const PduInfoType* DataPtr)
Sync/Async: Synchronous
Reentrancy: Non-Reentrant
Parameters[in]:
    [ControllerId]: the id of the CAN controller.
    [DataPtr]:  pointer to the CAN PDU (Protocol Data Uint)          
Parameters[in/out]: None
Parameters[out]: None
Return value: data message
Description : This Interface used to Read the message received via CAN Module. 
----------------------------------------------------------------------------------------------*/
uint8 Bcm_ReceiveMessage(uint8 ControllerId,const PduInfoType* DataPtr);

#endif