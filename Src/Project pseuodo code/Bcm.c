#include "Bcm.h"

uint8 DataBuffer_1=0;
uint8 DataBuffer_2=0;
uint8 DataBuffer_3=0;

const CanIf_PduConfigType Bcm_PduObj = 
{
    {SPEED_MESSAGE_ID,_BYTE,&DataBuffer_1,STANDARD_CAN},
    {DOOR_MESSAGE_ID,_BYTE, &DataBuffer_2,STANDARD_CAN},
    {SWITCH_MESSAGE_ID,_BYTE,&DataBuffer_3,STANDARD_CAN}
};


void Bcm_Init(void)
{
    CanIf_Init(&Can_ConfigObj);
    CanIf_SetRxNotification(ControllerId,&Bcm_PduObj);
}

void Bcm_SendMessage(uint8 ControllerId,const PduInfoType* DataPtr)
{
    CanIf_Transmit(ControllerId,DataPtr);
}

uint8 Bcm_ReceiveMessage(uint8 ControllerId,const PduInfoType* DataPtr)
{
   return (CanIf_ReadRxPduData(ControllerId,DataPtr));
}