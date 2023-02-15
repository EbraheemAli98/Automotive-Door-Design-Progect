#include "Bcm.h"
#include "Gpt.h"
#include "Port.h"
#include "Os.h"
#include "LightSwitch.h"
#include "SensorM.h"

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

void DoorTask(void *pvParameters)
{
    for(;;)
    {
    /* 1.Get the new value of door_state  from D_Sensor Module.
     * 2.Put door_state into the CAN bus.
     * 3.Enter the Delay list for 10ms.
     * */
        SensorM_GetState(DOOR_SENSOR_ID,&Door_state);.
        (*Bcm_PduObj.PduInfoConfig[1].sdu) = Door_state;
        Bcm_SendMessage(CAN0,&Bcm_PduObj.PduInfoConfig[1]);
        Os_Delay(10);
    }
}

void SpeedTask(void *pvParameters)
{
    for(;;)
    {
    /* 1.Get the new value of car_state  from S_Sensor Module.
     * 2.Put car_state into into the CAN bus.
     * 3.Enter the Delay list for 5ms. 
     * */
        SensorM_GetState(SPEED_SENSOR_ID,&Car_state);
        (*Bcm_PduObj.PduInfoConfig[0].sdu) = Car_state;
        Bcm_SendMessage(CAN0,&Bcm_PduObj.PduInfoConfig[0]);
        Os_Delay(5);
    }
}

void LightSwitchTask(void *pvParameters)
{
   
    for(;;)
    {
    /* 1.Get the new value of L_switch_state  from LightSwitch Module.
     * 2.Put L_switch_state into into the CAN bus.
     * 3.Enter the Delay list for 20ms.
     * */
        LightSwitch_state = LightSwitch_GetState();
        (*Bcm_PduObj.PduInfoConfig[2].sdu) = LightSwitch_state;
        Bcm_SendMessage(CAN0,&Bcm_PduObj.PduInfoConfig[2]);
        Os_Delay(20);
    }    
}

int main(void)
{
    /* Os_Init():
     * Initialize Hardware Componants...
     *  Initialize Port driver.
     *  Initialize Gpt driver.
     *  Initialize Can driver.
     *  Initialize ADC driver.
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
