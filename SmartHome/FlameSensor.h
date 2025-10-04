/*
 * FlameSensor.h
 *
 *  Created on: Sep 30, 2025
 *      Author: HP
 */

#ifndef FLAMESENSOR_H_
#define FLAMESENSOR_H_

#define FlameSensor_PORT_ID PORTD_ID
#define FlameSensor_PIN_ID PIN2_ID

#include "std_types.h"

void FlameSensor_init(void);
uint8 FlameSensor_getValue(void);

#endif /* FLAMESENSOR_H_ */
