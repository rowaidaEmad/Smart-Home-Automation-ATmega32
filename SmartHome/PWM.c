/*
 * PWM.c
 *
 *  Created on: Sep 30, 2025
 *      Author: HP
 */

#include "PWM.h"
#include "GPIO.h"
#include <avr/io.h>
void PWM_Timer0_Start(uint8 duty_cycle){ //duty_cycle: Percentage (0 to 100%) representing the PWM duty cycle
	TCNT0 = 0; // Set Timer Initial Value to 0
	DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC
	/* Configure timer control register
		 * 1. Fast PWM mode FOC0=0
		 * 2. Fast PWM Mode WGM01=1 & WGM00=1
		 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
		 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
		 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00)| (1<<CS02);
	//set compare value needed at OCR0
	 OCR0 = (uint8)(((uint16)duty_cycle * 255) / 100); // Map 0-100% to 0-255

}
