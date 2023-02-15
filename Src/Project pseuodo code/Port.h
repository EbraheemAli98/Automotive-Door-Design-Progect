#include "Std_Types.h"
#define NUMBER_OF_PINS     1
/****************************************************************************************************************************
 *                                          PORT DATA TYPES DESCRIPTION 
 ****************************************************************************************************************************/
/*---------------------------------------------------------------------------------
  Name: Port_PinModeType
  Type: uint8 
  
  Description: type contains describe pin Id.
  ---------------------------------------------------------------------------------*/
typedef uint8 PinIdType;
/*---------------------------------------------------------------------------------
  Name: Port_PinModeType
  Type: uint8 
  
  Description: type contains describe port Id.
  ---------------------------------------------------------------------------------*/
typedef uint8 PortIdType;
/*---------------------------------------------------------------------------------
  Name: Port_PinModeType
  Type: Enumeration
  
  Description: Enumeration type contains the port-pin mode.
  ---------------------------------------------------------------------------------*/
typedef enum
{
    DIO,
    ADC,
}Port_PinModeType;
/*---------------------------------------------------------------------------------
  Name: Port_SignalType
  Type: Enumeration
  
  Description: Enumeration type contains the port-pin signal type.
  ---------------------------------------------------------------------------------*/
typedef enum
{
    DIGITAL,
    ANALOG
}Port_SignalType;
/*---------------------------------------------------------------------------------
  Name: Port_DirectionType
  Type: Enumeration
  
  Description: Enumeration type contains the port-pin direction.
  ---------------------------------------------------------------------------------*/
typedef enum
{
    INPUT,
    OUTPUT
}Port_DirectionType;
/*---------------------------------------------------------------------------------
  Name: Port_ParameterType
  Type: Structure
  
  Description: the data structure contains all the Port-Pin Parameters data.
  ---------------------------------------------------------------------------------*/
typedef struct 
{
   PinIdType PinId;
   PortIdType PortId;
   Port_DirectionType Direction;
   Port_PinModeType Mode;
   Port_SignalType Signal;
   uint8 init_value;
}Port_ParameterType;
/*---------------------------------------------------------------------------------
  Name: Port_ConfigType
  Type: Structure
  
  Description: It's the external data structure contains all the intialization data for
              PORT driver.
  ---------------------------------------------------------------------------------*/
typedef struct 
{
    Port_ParameterType Port_Config[NUMBER_OF_PINS];
}Port_ConfigType;

/*---------------------------------------------------------------------------------
  Name: Port_ConfigObj
  Type: Port_ConfigType
  
  Description: It's an object to an external data structure contains all the intialization 
              data for PORT driver.
  ---------------------------------------------------------------------------------*/
extern const Port_ConfigType Port_ConfigObj;

/****************************************************************************************************************************
 *                                          PORT FUNCTION DESCRIPTION AND DECLARATION
 ****************************************************************************************************************************/
/*--------------------------------------------------------------------------------------------
Interface Name: Port_Init
Syntax: void Port_Init(const Port_ConfigType* const ConfigPtr)
Sync/Async: Synchronous
Reentrancy: Non-Reentrant
Parameters[in]: None
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : This interface Initialize the port module and all DIO port pins used in other modules .
----------------------------------------------------------------------------------------------*/
void Port_Init(const Port_ConfigType* const ConfigPtr);
/*--------------------------------------------------------------------------------------------
Interface Name: Port_DeInit
Syntax: void Port_DeInit(void)
Sync/Async: Synchronous
Reentrancy: Non-Reentrant
Parameters[in]: None
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : This interface de-initialize the port module and all DIO port pins used in other modules .
----------------------------------------------------------------------------------------------*/
void Port_DeInit(void);




