#ifndef CANIF_H_
#define CANIF_H_

#include "Std_Types.h"
#include "Can.h"


/*------------------------------------------------------------------------------------
  Name: CanIf_TxPduCanIdType
  Type: Enumeration
  
  Description: It contains ther type of CAN Identifier used by the CAN Driver module
              for CAN L-PDU transmission.
              - EXTENDED_CAN   : CAN frame with extended identifier (29 bits).
              - STANDARD_CAN   : CAN data frame with standard identifier (11 bits).
 -------------------------------------------------------------------------------------*/
typedef enum
{
    EXTENDED_CAN,
    STANDARD_CAN
}CanIf_TxPduCanIdType;
/*------------------------------------------------------------------------------------
  Name: PduInfoType
  Type: Structture
  
  Description: It contains the Link data information.
              - identefier Message
              - DLC (Data Length Code)
              - pointer to the transimetted data.
              - CAN ID
 -------------------------------------------------------------------------------------*/
typedef struct 
{
  Pdu_IdType swPduHandle;
  uint8 length;
  uint8* sdu;
  Can_IdType id;
}PduInfoType;
/*------------------------------------------------------------------------------------
  Name: CanIf_ConfigType
  Type: Structture
  
  Description: This type defines a data structure for the CAN interface for all
              underlying CAN drivers. At initialization the CanIf gets a pointer to 
              a structure of this type to get access to its configuration data, which 
              is necessary for initialization
 -------------------------------------------------------------------------------------*/
 typedef struct 
 {
  uint8 ContorllerId;
  uint16 Baudrate;
  Can_ControllerStateType mode;
 }CanIf_ConfigType;

/*------------------------------------------------------------------------------------
  Name: CanIf_PduConfigType
  Type: Structture
  
  Description: This type defines an array of data structures for all the messages send or
  received by the specific CAN node.
 -------------------------------------------------------------------------------------*/
typedef struct 
{
    PduInfoType PduInfoConfig[NUM_OF_MESSAGES];
}CanIf_PduConfigType;

 extern const CanIf_ConfigType Can_ConfigObj;
/*************************************************************************************************************
 *                                    CAN INTERFACE FUNCTIONS DESCRIPTION
 *************************************************************************************************************/
/*--------------------------------------------------------------------------------------------
Name  : CanIf_Init
Syntax: void CanIf_Init(const CanIf_ConfigType* ConfigPtr)
Sync/Async: Synchronous
Reentrancy: Non-Reentrant
Parameters[in]: ConfigPtr -> Pointer to the CAN Interface driver Configuration Structure.
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : Function to initialize the CAN Interface module.
----------------------------------------------------------------------------------------------*/
void CanIf_Init(const CanIf_ConfigType* ConfigPtr);
/*--------------------------------------------------------------------------------------------
Name  : CanIf_DeInit
Syntax: void CanIf_DeInit(void)
Sync/Async: Synchronous
Reentrancy: Non-Reentrant
Parameters[in]: None
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : Function to de-initialize the CAN Interface module.
----------------------------------------------------------------------------------------------*/
void CanIf_DeInit(void);
/*--------------------------------------------------------------------------------------------
Name  : CanIf_SetControllerMode
Syntax: Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId,Can_ControllerStateType Mode)
Sync/Async: Asynchronous
Reentrancy: Reentrant
Parameters[in]: None
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : Function that makes the CAN Module changes the CAN controller mode.
----------------------------------------------------------------------------------------------*/
void CanIf_SetControllerMode(uint8 ControllerId,Can_ControllerStateType Mode);
/*--------------------------------------------------------------------------------------------
Name  : CanIf_Transmit
Syntax: void CanIf_Transmit(uint8 ControllerId,const PduInfoType* PduInfoPtr)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  [ControllerId]: Can Controller Id.
                 [PduInfoPtr]: Pointer to the PDU data.
Parameters[in/out]: None
Parameters[out]: None
Return value:  None
Description : Function that Present Transmission of PDU.
----------------------------------------------------------------------------------------------*/
void CanIf_Transmit(uint8 Controllerd, const PduInfoType* PduInfoPtr);
/*--------------------------------------------------------------------------------------------
Name  : CanIf_ReadRxPduData
Syntax: uibt8 CanIf_ReadRxPduData(uint8 CanIfRxId,PduInfoType* CanIfRxInfoPtr)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  
  [CanIfRxId]: Receive handle specifying the corresponding CAN controller device.
  [CanIfRxInfoPtr]: Contains the length (SduLength) of the received PDU, a pointer to a buffer 
(SduDataPtr) containing the PDU, and the MetaData related to this PDU.

Parameters[in/out]: None
Parameters[out]: None
Return value:  the message data.
Description : This Interface provides the Data Length and the received data of the requested 
             CanIfRxSduId to the calling upper layer..
----------------------------------------------------------------------------------------------*/
uint8 CanIf_ReadRxPduData(uint8 CanIfRxId,const PduInfoType* CanIfRxInfoPtr);
/*--------------------------------------------------------------------------------------------
Name  : CanIf_TxConfirmation
Syntax: void CanIf_TxConfirmation(Pdu_IdType CanTxPduId)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  [CanTxPduId]: Id specifies the corresponding CAN controller.
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : This Interface confirms a previously successfully processed transmission.
----------------------------------------------------------------------------------------------*/
void CanIf_TxConfirmation(Pdu_IdType CanTxPduId);
/*--------------------------------------------------------------------------------------------
Name  : CanIf_RxIndication
Syntax: void CanIf_RxIndication(const Can_HwType* Mailbox,const PduInfoType* PduInfoPtr)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  [ControllerId]: Identifies the corresponding CAN Controller
                 [InfoPtr]: Pointer to the received PDU
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : This Interface indicates a successful reception of a received CAN Rx PDU to the CanIf after
passing all filters and validation checks.
Note: This interface is implemented in CanIf and called by CanDrv after a CAN PDU has been received.
----------------------------------------------------------------------------------------------*/
void CanIf_RxIndication(uint8 ControllerId,const CanIf_PduConfigType* InfoPtr);
/*--------------------------------------------------------------------------------------------
Name  : CanIf_ControllerBusOff
Syntax: void CanIf_ControllerBusOff(uint8 ControllerId)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]:  [ControllerId]: Abstract CanIf ControllerId which is assigned to a CAN controller,
                                 where a BusOff occured.
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : This Interface indicates a Controller BusOff event referring to the corresponding CAN Controller
              with the abstract CanIf ControllerId. 
----------------------------------------------------------------------------------------------*/
void CanIf_ControllerBusOff(uint8 ControllerId);
/*--------------------------------------------------------------------------------------------
Name  : CanIf_SetRxNotification
Syntax: void CanIf_SetRxNotification(uint8 ControllerId,const PduInfoType* DataPtr)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]: 
 [ControllerId]: Abstract CanIf ControllerId which is assigned to a CAN controller,where a BusOff occured.
 [DataPtr]  : Pointer to the CAN Pdu message (Identifier,Length,data,Identifier Type)
                
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : This Interface sets the CAN RX call back function parameters. 
----------------------------------------------------------------------------------------------*/
void CanIf_SetRxNotification(uint8 ControllerId,const CanIf_PduConfigType* DataPtr);

#endif