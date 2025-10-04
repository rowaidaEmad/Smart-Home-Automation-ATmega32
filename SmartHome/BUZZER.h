/*
 * BUZZER.h
 *
 *  Created on: Sep 30, 2025
 *      Author: HP
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#define BUZZER_PORT_ID PORTD_ID
#define BUZZER_PIN_ID PIN3_ID

#include "std_types.h"

void Buzzer_init(void);
void Buzzer_on(void);
void Buzzer_off(void);

#endif /* BUZZER_H_ */
