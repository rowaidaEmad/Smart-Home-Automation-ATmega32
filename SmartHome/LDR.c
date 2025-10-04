/*
 * LDR.c
 *
 *  Created on: Sep 30, 2025
 *      Author: HP
 */

#include "LDR.h"
#include "adc.h"
uint16 LDR_getLightIntensity(void){

 uint16 adc_LightIntensity_value =0;//init
 uint16 intensity = 0;

 adc_LightIntensity_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);
 intensity = (uint16)(((uint32)adc_LightIntensity_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(LDR_SENSOR_MAX_VOLT_VALUE*ADC_MAXIMUM_VALUE));
 return intensity;
}
