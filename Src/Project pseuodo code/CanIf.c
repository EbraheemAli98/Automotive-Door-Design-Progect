#include "CanIf.h"

extern DoorStateType Door_state;
extern CarStateType Car_state;
extern LightSwitchStateType L_switch_state;
extern LightStateType Lights_State;

const CanIf_ConfigType Can_ConfigObj = {CAN0,BR_1MB,CAN_UNINT};
/* The HRH is used as a parameter by the CAN Interface Layer for software filtering.*/

void CanIf_Init(const CanIf_ConfigType* ConfigPtr)
{
    Can_Init(&Can_Config);
}

void CanIf_SetRxNotification(uint8 ControllerId,const PduInfoType* DataPtr)
{
    CAN_RxSetCallBack(CanIf_RxIndication(ControllerId,DataPtr));
}

void CanIf_DeInit(void)
{
    Can_DeInit();
}

void CanIf_Transmit(uint8 ControllerId, const PduInfoType* PduInfoPtr)
{
    Can_Write(PduInfoPtr);
}

uint8 CanIf_ReadRxPduData(uint8 CanIfRxId,const PduInfoType* CanIfRxInfoPtr)
{
    uint8 RxData;
    switch (CanIfRxId)
    {
    case CAN0:
        /*  reads the data from CanIf Rx buffer.*/
      RxData = *(CanIfRxInfoPtr->sdu);
        break;
    case CAN1:
        /*  reads the data from CanIf Rx buffer.*/
       RxData= *(CanIfRxInfoPtr->sdu);
        break;
    default:
        break;
    }
    return RxData;
}

void CanIf_RxIndication(uint8 ControllerId,const CanIf_PduConfigType* InfoPtr)
{
    for (uint8 MessageNum = 0; MessageNum < NUM_OF_MESSAGES; MessageNum++)
    {
        switch (ControllerId)
        {
        case CAN0:
            if ((CAN0_ARB_REG.ID == InfoPtr->PduInfoConfig[MessageNum].swPduHandle) && (CAN0_MCTRL_REG.DLC == InfoPtr->PduInfoConfig[MessageNum].length) && (CAN0_ARB_REG.XTD == InfoPtr->PduInfoConfig[MessageNum].id))
            {
                *(InfoPtr->PduInfoConfig[MessageNum].sdu) = CAN0_DATA_REG;
            }
            else
            {
            }
            break;
        case CAN1:
            if ((CAN1_ARB_REG.ID == InfoPtr->PduInfoConfig[MessageNum].swPduHandle) && (CAN1_MCTRL_REG.DLC == InfoPtr->PduInfoConfig[MessageNum].length) && (CAN1_ARB_REG.XTD == InfoPtr->PduInfoConfig[MessageNum].id))
            {
                *(InfoPtr->PduInfoConfig[MessageNum].sdu) = CAN1_DATA_REG;
            }
            else
            {
            }
            break;
        default:
            break;
        }
    }
}