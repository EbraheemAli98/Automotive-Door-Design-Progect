#include "Can.h"

/* addresses of the CAN0 and CAN1 status registers */
#define CAN0_CANSTS (*(volatile uint32 *)0x40040004)
#define CAN1_CANSTS (*(volatile uint32 *)0x40041004)
#define TXOK 3
#define RXOK 4
#define BOFF 7

static void (*g_CAN_TxCallBack_Ptr)(uint8) = NULL_PTR;
static void (*g_CAN_RxCallBack_Ptr)(uint8) = NULL_PTR;
static void (*g_CAN_BusOffCallBack_Ptr)(uint8) = NULL_PTR;


Can_ConfigType *Can_Config = NULL_PTR;

void Can_Init(const Can_ConfigType *ConfigPtr)
{
    if (Can_Config->Mode == CAN_UNINT && ConfigPtr != NULL_PTR)
    {
        Can_Config = ConfigPtr;
    switch (ConfigPtr->ControllerId)
    {
    case CAN0:
       /* 1.Access the CAN CONTROL REGISTER to set the can initializations
         * 2.Access the CAN BIT TIMING REGISTER to set the Bbaudrate in the BRP bit field.
        * */
        CAN0_CTRL_REG = INIT_CONFIG_VAL;
        CAN0_BIT_REG.BRP = ConfigPtr->Baudrate;
        break;
    case CAN1:
       /* 1.Access the CAN CONTROL REGISTER to set the can initializations
        * 2.Access the CAN BIT TIMING REGISTER to set the Bbaudrate in the BRP bit field.
        * */
        CAN1_CTRL_REG = INIT_CONFIG_VAL;
        CAN1_BIT_REG.BRP = ConfigPtr->Baudrate;    
    default:
        break;
    }
        ConfigPtr->Mode = CAN_STOPPED;
    }
    else
    {
    }
}

void Can_DeInit(void)
{
    Can_Config->Mode = CAN_UNINT;
    /* Stop all configuratioins and operations */
}

void Can_SetBaudRate(uint8 ControllerId, uint16 BaudRate)
{
    Can_Config->Baudrate = BaudRate;
    Can_Config->Mode = CAN_STOPPED;
    switch (Can_Config->ControllerId)
    {
    case CAN0:
        CAN0_BIT_REG.BRP = BaudRate; 
        break;
    case CAN1:
        CAN1_BIT_REG.BRP = BaudRate;
        break;
    default:
        break;
    }
}

void Can_SetControllerMode(uint8 ControllerId, Can_ControllerStateType Mode)
{
    switch (Can_Config->ControllerId)
    {
    case CAN0:
        Can_Config->Mode = Mode;
        break;
    case CAN1:
        Can_Config->Mode = Mode;
        break;
    default:
        break;
    }
}

void Can_Write(const Can_PduType *PduInfo)
{
    /*Cheak the that the state of Can Bus is STARTED */
    if (Can_Config->Mode == CAN_STARTED && PduInfo != NULL_PTR)
    {
        switch (Can_Config->ControllerId)
        {
        case CAN0:
            /* Set the CAN ID message in the CAN Arbitration Register ID-Bits*/
            CAN0_ARB_REG.ID = PduInfo->swPduHandle;
            /* Set the data length in the CAN Message Control Register*/
            CAN0_MCTRL_REG.DLC = PduInfo->length;
            /* Set the transmited data in the CAN Data Register*/
            CAN0_DATA_REG = *(PduInfo->sdu);
            /* Set the Identifier Type in the CAN Arbitration Register XTD bit*/
            CAN0_ARB_REG.XTD = PduInfo->id;
            /*Send the Message*/
            break;
        case CAN1:
            /* Set the CAN ID message in the CAN Arbitration Register ID-Bits*/
            CAN1_ARB_REG.ID = PduInfo->swPduHandle;
            /* Set the data length in the CAN Message Control Register*/
            CAN1_MCTRL_REG.DLC = PduInfo->length;
            /* Set the transmited data in the CAN Data Register*/
            CAN1_DATA_REG = *(PduInfo->sdu);
            /* Set the Identifier Type in the CAN Arbitration Register XTD bit*/
            CAN1_ARB_REG.XTD = PduInfo->id;
            /*Send the Message*/
            break;
        default:
            break;
        }
    }
    else
    {
    }
}
/**********************************************************************************************
 *                      CAN CONTROLLERS CALL BACK FUNCTIONS
`**********************************************************************************************/
void Can_TxSetCallBack(void (*FunPtr)(uint8))
{
    if (g_CAN_TxCallBack_Ptr == NULL_PTR)
    {
        switch (Can_Config->ControllerId)
        {
        case CAN0:
            g_CAN_TxCallBack_Ptr = FunPtr;
            break;
        case CAN1:
            g_CAN0_TxCallBack_Ptr = FunPtr;
            break;
        default:
            break;
        }
    }
    else
    {

    }

}
/*--------------------------------------------------------------------*/
void Can_RxSetCallBack(void (*FunPtr)(uint8 ControllerId, const Can_PduConfigType *))
{
    if (g_CAN_RxCallBack_Ptr == NULL_PTR)
    {
        switch (Can_Config->ControllerId)
        {
        case CAN0:
            g_CAN_RxCallBack_Ptr = FunPtr;
            break;
        case CAN1:
            g_CAN0_RxCallBack_Ptr = FunPtr;
            break;
        default:
            break;
        }
    }
    else
    {

    }
}
/*-------------------------------------------------------------------*/
void Can_BusOffSetCallBack(void (*FunPtr)(uint8))
{
    if (g_CAN_BusOffCallBack_Ptr == NULL_PTR)
    {
        switch (Can_Config->ControllerId)
        {
        case CAN0:
            g_CAN_BusOffCallBack_Ptr = FunPtr;
            break;
        case CAN1:
            g_CAN_BusOffCallBack_Ptr = FunPtr;
            break;
        default:
            break;
        }
    }
    else
    {

    }
}

/**********************************************************************************************
 *                      CAN CONTROLLERS ISRs
`**********************************************************************************************/
void CAN0_Handler(void)
{

    if ((CAN0_CANSTS & TXOK) == 1)
    {
        /* Call CanIf_TxConfirmation(CAN0) */
    }
    else if ((CAN0_CANSTS & RXOK) == 1)
    {
        /* Call CanIf_RxIndication(CAN0*, Can_PduType*) */
    }
    else if ((CAN0_CANSTS & BOFF) == 1)
    {
        /* Call CanIf_ControllerBusOff(CAN0) */
    }
    else
    {
        /*Do nothing*/
    }
}

void CAN1_Handler(void)
{
    if ((CAN1_CANSTS & TXOK) == 1)
    {
        /* Call CanIf_TxConfirmation(CAN1) */
    }
    else if ((CAN1_CANSTS & RXOK) == 1)
    {
        /* Call CanIf_RxIndication(CAN1, Can_PduType*) */
    }
    else if ((CAN1_CANSTS & BOFF) == 1)
    {
        /* Call CanIf_ControllerBusOff(CAN1) */
    }
    else
    {
        /*Do nothing*/
    }
}