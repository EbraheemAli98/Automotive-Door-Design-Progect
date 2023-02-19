#ifndef GPT_H_
#define GPT_H_

#include "Std_Types.h"

#define NUM_OF_TIMER_CHANNELS   1

typedef uint8 Gpt_IdType;   /** Indicates the timer channel Id */
typedef uint8 Gpt_InitValType; /** Indicates the timer initial value */
typedef uint8 Gpt_TimePeriodType;   /** Indicates the number of ticks after the notification shall occur */

/*---------------------------------------------------------------------------------
  Name: Port_DirectionType
  Type: Enumeration
  
  Description: Enumeration type to define the different modes in time.
  ---------------------------------------------------------------------------------*/
typedef enum
{
    NORMAL_MODE,
    OUPUT_COMPARE_MODE
}Gpt_ModeType;

/*---------------------------------------------------------------------------------
  Name: Port_DirectionType
  Type: Enumeration
  
  Description: Enumeration type to define all possible prescaler value.
  ---------------------------------------------------------------------------------*/
typedef enum
{
    STOP,
    F_CPU_FREQ,
    SCALER_8,
    SCALER_64,
    SCALER_256,
    SCALER_1024
}Gpt_PrescalerType;
/*---------------------------------------------------------------------------------
  Name: Port_DirectionType
  Type: Structure
  
  Description: Structure type contains the GPT parameters.
  ---------------------------------------------------------------------------------*/
typedef struct 
{
    Gpt_IdType Timer_ID;        /* Indicates the timer channel */
    Gpt_PrescalerType prescaler_value; /* Indicates the tmer freq */
    Gpt_ModeType mode;         /* Indicates the timer mode */
    Gpt_InitValType  initial_value;
    Gpt_TimePeriodType time_period;   /* number of ticks after the notification shall occur */
}Gpt_ConfigParamType;
/*---------------------------------------------------------------------------------
  Name: Port_DirectionType
  Type: Structure
  
  Description: sturcture type for Gpt initializations.
  ---------------------------------------------------------------------------------*/
typedef struct 
{
    /* Create an array of configuration parameter structure for each Timer channel. */
    Gpt_ConfigParamType Gpt_Config[NUM_OF_TIMER_CHANNELS];
}Gpt_ConfigType;


/* Configuration object used to configure Gpt_module in other modules */
extern const Gpt_ConfigType Gpt_ConfigObj; 

/*-----------------------------------------------------------------------------------
 Service Name     : Gpt_Init
 Sync/Async       : Synchronous
 Reentrnacy       : Non-Reentrant
 Parameter(in)    : [ConfigPtr] : Pointer to a selected configuration structure.
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : None
 Description      : Function to Initialize the GPT driver
 -----------------------------------------------------------------------------------*/
void  Gpt_Init(const  Gpt_ConfigType* Config_Ptr);
 /*-----------------------------------------------------------------------------------
 Service Name     : Gpt_DeInit
 Sync/Async       : Synchronous
 Reentrnacy       : Non-Reentrant
 Parameter(in)    : None
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : None
 Description      : Function to Deinitialize the GPT driver
 -----------------------------------------------------------------------------------*/
void  Gpt_DeInit(void);
 /*-------------------------------------------------------------------------------------
 Service Name     : Gpt_StartTimer
 Sync/Async       : Asynchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : [Channel] : Numeric identifier of the GPT channel.
                    [Value]   : Target time in number of ticks.
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : [Gpt_ValueType]  : Remaining timer value(in number of ticks).
 Description      : Function Starts a timer channel.
 ----------------------------------------------------------------------------------------*/
void  Gpt_StartTimer(Gpt_IdType Channel, Gpt_TimePeriodType timePeriod);
 /*-------------------------------------------------------------------------------------
 Service Name     : Gpt_StopTimer
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : [Channel] : Numeric identifier of the GPT channel.
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : None
 Description      : Function Stops a timer channel.
 ----------------------------------------------------------------------------------------*/
void  Gpt_StopTimer(Gpt_IdType Channel);
 /*-------------------------------------------------------------------------------------
 Service Name     : Gpt_GetTimerValue
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : [Channel] : Numeric identifier of the GPT channel.
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : Remaining timer value(in number of ticks).
 Description      : Function Gets a timer value.
 ----------------------------------------------------------------------------------------*/
uint8  Gpt_GetTimerValue(Gpt_IdType Channel);
 /*-----------------------------------------------------------------------------------
 Service Name     : Gpt_EnableNotification
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : [Channel] : Numeric identifier of the GPT channel.
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : None
 Description      : Function enables the interrupt notification for a channel (relevant in normal mode).
 -----------------------------------------------------------------------------------*/
void  Gpt_EnableNotification(Gpt_IdType Channel, Gpt_ModeType mode);
 /*-----------------------------------------------------------------------------------
 Service Name     : Gpt_DisableNotification
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : [Channel] : Numeric identifier of the GPT channel.
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : None
 Description      : Function disnables the interrupt notification for a channel (relevant in normal mode).
 -----------------------------------------------------------------------------------*/
void  Gpt_DisableNotification(Gpt_IdType Channel, Gpt_ModeType mode);
 /*-------------------------------------------------------------------------------------
 Service Name     : Gpt_T0_SetCallBack
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : None
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : void
 Description      : Function callback.
 ----------------------------------------------------------------------------------------*/
void  Gpt_T0_SetCallBack( void(*Fun_Ptr)(void) );
 /*-------------------------------------------------------------------------------------
 Service Name     : Gpt_T1_SetCallBack
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : None
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : void
 Description      : Function callback.
 ----------------------------------------------------------------------------------------*/
void  Gpt_T1_SetCallBack( void(*Fun_Ptr)(void) );

#endif