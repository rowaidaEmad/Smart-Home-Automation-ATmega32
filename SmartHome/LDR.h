/*
 * LDR.h
 *
 *  Created on: Sep 30, 2025
 *      Author: HP
 */

#ifndef LDR_H_
#define LDR_H_

#define LDR_SENSOR_CHANNEL_ID 0
#define LDR_SENSOR_MAX_VOLT_VALUE 2.56
/* this represents the max voltage output of LDR sensor when exposed to the
 * lowest possible light intensity (darkness).
 * In a voltage divider circuit , the ldr's resistance dec with increasing light ,
 * resulting in a maximum voltage in darkness.
 * this value vary based on the circuit configuration
 * */
#define LDR_SENSOR_MAX_LIGHT_INTENSITY 100
/* represents the maximum light intensity the sensor can measure (0% → 100%)*/

#include "std_types.h"

uint16 LDR_getLightIntensity(void);
//Reads the LDR sensor value and returns the light intensity

#endif /* LDR_H_ */
