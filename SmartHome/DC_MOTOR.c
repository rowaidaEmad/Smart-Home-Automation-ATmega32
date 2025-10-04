/*
 * DC_MOTOR.c
 *
 *  Created on: Sep 30, 2025
 *      Author: HP
 */


#include "DC_MOTOR.h"
#include "GPIO.h"
#include "PWM.h"
void DcMotor_Init(void){
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_INPUT1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_INPUT2_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT,DC_MOTOR_ENABLE_PIN_ID,PIN_OUTPUT);
	//enable h-bridge
	GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_ENABLE_PIN_ID,LOGIC_HIGH);
	//stop
	DcMotor_Rotate(stop, 0);
}
void DcMotor_Rotate(DcMotor_State state, uint8 speed){
	switch(state){
	case cw:
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_INPUT1_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
		PWM_Timer0_Start(speed);
		break;
	case acw:
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_INPUT2_PIN_ID,LOGIC_HIGH);
		PWM_Timer0_Start(speed);
		break;
	case stop:
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_INPUT1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT,DC_MOTOR_INPUT2_PIN_ID,LOGIC_LOW);
		PWM_Timer0_Start(0);
		break;
	}
}
