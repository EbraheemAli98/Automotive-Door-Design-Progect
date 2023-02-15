#include "ADC.h"

void ADC_Init(const ADC_ConfigType* ConfigPtr)
{
    /*
     * 1. Enable ADC 
     * 2. Enable/Disable ADC Interrupt.
     * 3. set the reference voltage.
     * 4. choose the channel. 
     * 5. set the fequency.
     */
}

ADC_ReturnType ADC_ReadChannel(uint8 ChannelId)
{
    /*
     * 1. Start conversion. 
     * 2. Wait for the conversion to complete.
     * 3. read the value
     *
     */
}