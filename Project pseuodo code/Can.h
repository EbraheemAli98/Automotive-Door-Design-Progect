#ifndef CAN_H_
#define CAN_H_

#include "Std_Types.h"

#define CAN0  0
#define CAN1  1
 
/* DLC Macros */
#define _BYTE   1
#define _2BYTES 2
#define _3BYTES 3
#define _4BYTES 4
#define _5BYTES 5
#define _6BYTES 6
#define _7BYTES 7
#define _8BYTES 8

#define NUM_OF_MESSAGES 3
/******************************************************************************************
 *                                      DATA TYPE DEFINITIONS
 ******************************************************************************************/

/*--------------------------------------------------------------------------------------
  Name: Can_IdType
  Type: uint32

  Description:  Represent the identifier of the Protocol Data Unit.
                - 00 = CAN data message with Standard CAN_ID.
                - 01 = CAN Full Data (64 Bytes) frame with Standard CAN_ID.
                - 10 = CAN message with Extended CAN_ID.
                - 11 = CAN Full Data (64 Bytes) frame with Extended CAN-ID.
 ---------------------------------------------------------------------------------------*/
typedef uint32 Can_IdType;
 /*--------------------------------------------------------------------------------------
  Name: Pdu_IdType
  Type: uint8

  Description:  Represents the Controller identifier of the PDU to be transmitted
 -----------------------------------------------------------------------------------------*/
typedef uint8 Pdu_IdType;
 /*--------------------------------------------------------------------------------------
  Name: Can_ReturnType
  Type: uint8
  Range: CAN_BUSY

  Description:  Overlayed return value of Std_ReturnType for CAN.
 -----------------------------------------------------------------------------------------*/
typedef uint8 Can_ReturnType;
 /*----------------------------------------------------------------------------------------
  Name: Can_BaudrateType
  Type: Enumeration
  Range: - BR_40KB
         - BR_125KB
         - BR_1MB
  
  Description: Contains the Baudrates of CAN Bus.
  -----------------------------------------------------------------------------------------*/
  typedef enum
  {
    BR_40KB,
    BR_125KB,
    BR_1MB
  }Can_BaudrateType;
  
 /*----------------------------------------------------------------------------------------
  Name: Can_ControllerStateType
  Type: Enumeration
  Range: - CAN_UNINIT
         - CAN_STARTED
         - CAN_STOPPED
  
  Description: Contains the states of CAN used by ControllerMode APIs.
  -----------------------------------------------------------------------------------------*/
typedef enum
{
  CAN_UNINT,
  CAN_STARTED,
  CAN_STOPPED
}Can_ControllerStateType;
/*------------------------------------------------------------------------------------
  Name: Can_PduType
  Type: Structure
  
  Description: It contains the Link data information.
              - identefier Message
              - DLC (Data Length Code)
              - pointer to the transimetted data.
              - CAN ID Type
 -------------------------------------------------------------------------------------*/
typedef struct 
{
  Pdu_IdType swPduHandle;
  uint8 length;
  uint8* sdu;
  Can_IdType id;
}Can_PduType;
/*---------------------------------------------------------------------------------
  Name: Can_ConfigType
  Type: Structure
  
  Description: It's the external data structure contains all the intialization data for
              CAN driver and its special function registers values that affecting all
              controllers.
  ---------------------------------------------------------------------------------*/
typedef struct 
{
  uint8 ControllerId;
  uint16 Baudrate;
  Can_ControllerStateType Mode;
}Can_ConfigType;

/*------------------------------------------------------------------------------------
  Name: Can_PduConfigType
  Type: Structture
  
  Description: This type defines an array of data structures for all the messages send or
  received by the specific CAN node.
 -------------------------------------------------------------------------------------*/
typedef struct 
{
    Can_PduType PduInfoConfig[NUM_OF_MESSAGES];
}Can_PduConfigType;


/*********************************************************************************************
 *                                     FUNCTIONS DESCRIPTION
 *********************************************************************************************/

/*--------------------------------------------------------------------------------------------
Name  : Can_Init
Syntax: void Can_Init(const Can_ConfigType* ConfigPtr)
Sync/Async: Synchronous
Reentrancy: Non-Reentrant
Parameters[in]: ConfigPtr -> Pointer to the CAN driver Configuration Structure.
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : Function to initialize the CAN module.
----------------------------------------------------------------------------------------------*/
void Can_Init(const Can_ConfigType* ConfigPtr);
/*--------------------------------------------------------------------------------------------
Name  : Can_DeInit
Syntax: void Can_DeInit(void)
Sync/Async: Synchronous
Reentrancy: Non-Reentrant
Parameters[in]: None
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : Function to Deinitialize CAN module.
----------------------------------------------------------------------------------------------*/
void Can_DeInit(void);
/*--------------------------------------------------------------------------------------------
Name  : Can_SetBaudRate
Syntax: void Can_SetBaudRate(uint8 ControllerId, uint16 BaudRate)
Sync/Async: Synchronous
Reentrancy: Reentrant except for the same controller.
Parameters[in]:  ControllerId -> CAN controller whose baud rate shall be set.
                 BaudRate -> refer to the configured Baud-rate.
Parameters[in/out]: None
Parameters[out]: None
Return value: ENone
Description : Function to set the baudrate configuration of the CAN controller.
----------------------------------------------------------------------------------------------*/
void Can_SetBaudRate(uint8 ControllerId, uint16 BaudRate);
/*--------------------------------------------------------------------------------------------
Name  : Can_SetControllerMode
Syntax: void Can_SetControllerMode(uint8 Controller, Can_ControllerStateType Mode)
Sync/Async: Asynchronous
Reentrancy: Non Reentrant.
Parameters[in]: ControllerId -> CAN controller for which the state shall be changed.
                Mode -> Transition value to request new CAN controller state (UNINT,STARTED or STOPED).
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : Function to change the CAN controller State Machine.
----------------------------------------------------------------------------------------------*/
void Can_SetControllerMode(uint8 ControllerId, Can_ControllerStateType Mode);
/*--------------------------------------------------------------------------------------------
Name  : Can_Write
Syntax: void Can_Write(const Can_PduType* PduInfo)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  PduInfo -> Pointer to the Protocol data unit that carries Identifier,Data Length and Data.
Parameters[in/out]: None
Parameters[out]: None
Return value: None 
Description : Function called by upper layer( CanIf ) to pass the CAN message to the CAN Driver 
              to transmit it.
----------------------------------------------------------------------------------------------*/
void Can_Write(const Can_PduType* PduInfo);
/*--------------------------------------------------------------------------------------------
Name  : Can_EnableInterrupts
Syntax: void Can_EnableInterrupts(uint8 Controller_ID)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  Can_ID  -> CAN controller for which interrupts shall be re-enabled
Parameters[in/out]: None
Parameters[out]: None
Return value: None 
Description : Function shall enable all masked interrupts.
----------------------------------------------------------------------------------------------*/
void Can_EnableInterrupts(uint8 Controller_ID);
/*--------------------------------------------------------------------------------------------
Name  : Can_DisableInterrupts
Syntax: void Can_DisableInterrupts(uint8 Controller_ID)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  Can_ID  -> CAN controller for which interrupts shall be re-enabled
Parameters[in/out]: None
Parameters[out]: None
Return value: None 
Description : Function shall disable all masked interrupts.
----------------------------------------------------------------------------------------------*/
void Can_DisableInterrupts(uint8 Controller_ID);
/*--------------------------------------------------------------------------------------------
Name  : CAN_TxSetCallBack
Syntax: void CAN0_TxSetCallBack(void (*FunPtr)(uint8))
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  FunPtr  -> Pointer to the notified function placed in the upper layer.
Parameters[in/out]: None
Parameters[out]: None
Return value: None 
Description : Function to notify the upper layer when a Transmit interrupt happen.
----------------------------------------------------------------------------------------------*/
void CAN_TxSetCallBack(void (*FunPtr)(uint8));
/*--------------------------------------------------------------------------------------------
Name  : CAN0_RxSetCallBack
Syntax: void CAN0_RxSetCallBack(void (*FunPtr)(uint8 ControllerId ,const Can_PduType*))
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  FunPtr  -> Pointer to the notified function placed in the upper layer.
Parameters[in/out]: None
Parameters[out]: None
Return value: None 
Description : Function to notify the upper layer when a Receive interrupt happen.
----------------------------------------------------------------------------------------------*/
void CAN_RxSetCallBack(void (*FunPtr)(uint8 ControllerId ,const Can_PduConfigType* ));
/*--------------------------------------------------------------------------------------------
Name  : CAN0_BusOffSetCallBack
Syntax: void CAN0_BusOffSetCallBack(void (*FunPtr)(uint8))
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  FunPtr  -> Pointer to the notified function placed in the upper layer.
Parameters[in/out]: None
Parameters[out]: None
Return value: None 
Description : Function to notify the upper layer when a Bus-off interrupt happen.
----------------------------------------------------------------------------------------------*/
void CAN_BusOffSetCallBack(void (*FunPtr)(uint8));


#endif