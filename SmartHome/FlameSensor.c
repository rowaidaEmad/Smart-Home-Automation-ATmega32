/*
 * FlameSensor.c
 *
 *  Created on: Sep 30, 2025
 *      Author: HP
 */

#include "FlameSensor.h"
#include "GPIO.h"
//The system stays in alert mode until the flame sensor no longer detects fire

void FlameSensor_init(void){
	GPIO_setupPinDirection(FlameSensor_PORT_ID,FlameSensor_PIN_ID,PIN_INPUT);
}
uint8 FlameSensor_getValue(void){
	return GPIO_readPin(FlameSensor_PORT_ID,FlameSensor_PIN_ID);
}
