/*
 * DC_MOTOR.h
 *
 *  Created on: Sep 30, 2025
 *      Author: HP
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#define DC_MOTOR_PORT PORTB_ID
#define DC_MOTOR_INPUT1_PIN_ID PIN0_ID
#define DC_MOTOR_INPUT2_PIN_ID PIN1_ID
#define DC_MOTOR_ENABLE_PIN_ID PIN3_ID

#include "std_types.h"

typedef enum{cw=1,acw=2,stop=3}DcMotor_State;
//DC Motor Driver Functions prototypes
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);
#endif /* DC_MOTOR_H_ */
