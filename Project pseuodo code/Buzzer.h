#ifndef BUZZER_H_
#define BUZZER_H_

#include "Std_Types.h"

#define BUZZER_PIN_ID   PIN7

/*--------------------------------------------------------------------------------------------
Interface Name: Buzzer_ON
Syntax: void Buzzer_ON(void)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]: None
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : This interface turn on the buzzer.
----------------------------------------------------------------------------------------------*/
void Buzzer_ON(void);
/*--------------------------------------------------------------------------------------------
Interface Name: Buzzer_OFF
Syntax: void Buzzer_OFF(void)
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters[in]: None
Parameters[in/out]: None
Parameters[out]: None
Return value: None
Description : This interface turn off the buzzer.
----------------------------------------------------------------------------------------------*/
void Buzzer_OFF(void);

#endif