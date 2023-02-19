#ifndef LIGHTS_H_
#define LIGHTS_H_

#define R_LIGHT_PIN_ID  PIN2
#define L_LIGHT_PIN_ID  PIN3

/*-----------------------------------------------------------------------------------
 Service Name     : Lights_ON
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : None
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : None
 Description      : Function to turn on the lights.
 -----------------------------------------------------------------------------------*/
void Lights_ON(void);
/*-----------------------------------------------------------------------------------
 Service Name     : Lights_OFF
 Sync/Async       : Synchronous
 Reentrnacy       : Reentrant
 Parameter(in)    : None
 Parameter(in/out): None
 Parameter(out)   : None
 Return Value     : None
 Description      : Function to turn off the lights.
 -----------------------------------------------------------------------------------*/
void Lights_OFF(void)

#endif