#include "Bcm.h"
#include "Gpt.h"
#include "Port.h"
#include "OS.h"
#include "Buzzer.h"
#include "Lights.h"

typedef enum
{
    DOOR_IS_OPENED, 
    DOOR_IS_CLOSED
}DoorStateType;

typedef enum
{
    CAR_IS_STOPED, 
    CAR_IS_MOVING
}CarStateType;

typedef enum
{
    SWITCH_IS_PRESSED, 
    SWITCH_IS_RELEASED
}LightSwitchStateType;

typedef enum
{
    OFF,
    ON
}LightStateType;

DoorStateType Door_state = DOOR_IS_CLOSED;
CarStateType Car_state = CAR_IS_STOPED;
LightSwitchStateType LightSwitch_state = SWITCH_IS_RELEASED; 
LightStateType Lights_State = OFF;

void SpeedTask(void *pvParameters)
{
    for(;;)
    {
        Car_state = Bcm_ReceiveMessage(CAN0,&Bcm_PduObj.PduInfoConfig[0]);
        if(Door_state == DOOR_IS_OPENED && Car_state == CAR_IS_MOVING)
        {
            Buzzer_ON();
            Lights_OFF();
            Lights_State = OFF;
        }
        else if(Door_state == DOOR_IS_OPENED && Car_state == CAR_IS_STOPED)
        {
            Buzzer_OFF();
            Lights_ON();
            Lights_State = ON;
        }
        else if(Car_state == CAR_IS_MOVING && LightSwitch_state == SWITCH_IS_PRESSED)
        {
            Buzzer_OFF();
            Lights_ON();
            Lights_State = ON;
        }
        else if(Car_state == CAR_IS_STOPED && LightSwitch_state == SWITCH_IS_PRESSED)
        {
            Buzzer_ON();
            Lights_ON();
            Lights_State = ON;
        }
        else
        {
            Buzzer_OFF();
            Lights_OFF();
            Lights_State = OFF;
        }
        Os_Delay(5);
    }
}

void DoorTask(void *pvParameters)
{
    for(;;)
    {
        Door_state = Bcm_ReceiveMessage(CAN0,&Bcm_PduObj.PduInfoConfig[1]);
        if(Door_state == DOOR_IS_OPENED && Car_state == CAR_IS_MOVING)
        {
            Buzzer_ON();
            Lights_OFF();
            Lights_State = OFF;
        }
        else if(Door_state == DOOR_IS_OPENED && Car_state == CAR_IS_STOPED)
        {
            Buzzer_OFF();
            Lights_ON();
            Lights_State = ON;
        }
        else if(Door_state == DOOR_IS_CLOSED && Lights_State == ON)
        {
            Gpt_StartTimer(T1,THREE_SEC);
            Gpt_T1_setCallBack(Lights_OFF);
            Lights_State = OFF;
        }
        else
        {
            Buzzer_OFF();
            Lights_OFF();
            Lights_State = OFF;
        }
        Os_Delay(10);
    }
}

void LightSwitchTask(void *pvParameters)
{
    for(;;)
    {
        LightSwitch_state = Bcm_ReceiveMessage(CAN0,&Bcm_PduObj.PduInfoConfig[2]);
        if(Car_state == CAR_IS_MOVING && LightSwitch_state == SWITCH_IS_PRESSED)
        {
            Buzzer_OFF();
            Lights_ON();
            Lights_State = ON;
        }
        else if(Car_state == CAR_IS_STOPED && LightSwitch_state == SWITCH_IS_PRESSED)
        {
            Buzzer_ON();
            Lights_ON();
            Lights_State = ON;
        }
        else
        {
            Buzzer_OFF();
            Lights_OFF();
            Lights_State = OFF;
        }
        Os_Delay(20);
    }    
}

int main(void)
{
    /* Initialize Hardware Componants : 
     *  Initialize Port driver.
     *  Initialize Gpt driver.
     *  Initialize Can driver.
     * */
    Os_Init();
    /* 1.Create DoorTask with priority 2
     * 2.Create SpeedTask with priority 3
     * 3.Create LightSwitchTask with priority 1.
     * */

    /* Start Scheduler */
    Os_Start();
    for(;;);
}