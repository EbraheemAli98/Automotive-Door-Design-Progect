#include "Gpt.h"

/* Create an Object from Gpt_ConfigType configuration structure to define all the parameters in Gpt paramter sturcture
 * for each timer channel
 */
const Gpt_ConfigType Gpt_ConfigObj = {{/*Timer_ID, perscaler_value, mode, initial_value, time_period*/}};

void  Gpt_T0_SetCallBack( void(*Fun_Ptr)(void) )
{
    /* g_T0_callBack_Ptr = Fun_Ptr; */
}
void  Gpt_T1_SetCallBack( void(*Fun_Ptr)(void) )
{
    /* g_T1_callBack_Ptr = Fun_Ptr; */
}
void  Gpt_T0_Handler (void)
{
    /* (*g_T0_callBack_Ptr)(); */
}
void  Gpt_T1_Handler (void)
{
    /* (*g_T1_callBack_Ptr)(); */
}
