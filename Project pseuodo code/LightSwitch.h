#ifndef LIGHT_SWITCH_H_
#define LIGHT_SWITCH_H_

#include "Std_Types.h"

#define LIGHT_SWITCH_PIN_ID PIN0


/*-----------------------------------------------------------------------------------
 Service Name     : LightSwitch_GetState
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : None
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : Switch state
 Description      : Function to get the light switch state.
 -----------------------------------------------------------------------------------*/
uint8 LightSwitch_GetState(void);

#endif