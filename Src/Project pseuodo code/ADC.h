#include "Std_Types.h"

typedef uint8 ADC_ReturnType;
/*---------------------------------------------------------------------------------------------
 Name : ADC_ConfigType
 Type : Sturcture

 Description: Sturcture contains the configuration parameters of ADC module for initialization.
 ---------------------------------------------------------------------------------------------*/
typedef struct 
{
    uint8 ChannelId;
    uint8 freq;
}ADC_ConfigType;


/***************************************************************************************
 *                     DIO FUNCTION DESCRIPTION AND DECLARATION
 ***************************************************************************************/
/*-----------------------------------------------------------------------------------
 Interface Name   : ADC_Init
 Syntax           : void ADC_Init(const ADC_ConfigType* ConfigPtr)
 Sync/Async       : Synchronous
 Reentrnacy       : Non-Reentrant
 Parameter(in)    : ConfigPtr -> Pointer to the configuration structure of ADC.
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : None
 Description      : Function responsible for initialize the ADC driver.
 -----------------------------------------------------------------------------------*/
 void ADC_Init(const ADC_ConfigType* ConfigPtr);
 /*-----------------------------------------------------------------------------------
 Interface Name   : ADC_ReadChannel
 Syntax           : void ADC_Init(uint8 ChannelId)
 Sync/Async       : Synchronous
 Reentrnacy       : Non-Reentrant
 Parameter(in)    : ChannelId -> Id of the ADC channel
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : ADC_value -> the Digital value converted by ADC.
 Description      : Function responsible for read analog data from a certain ADC channel
                    and convert it to digital using the ADC driver
 -----------------------------------------------------------------------------------*/
ADC_ReturnType ADC_ReadChannel(uint8 ChannelId);