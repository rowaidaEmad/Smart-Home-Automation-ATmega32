/*
 * LED.c
 *
 *  Created on: Sep 30, 2025
 *      Author: HP
 */

#include "LED.h"
#include "GPIO.h"

void LEDS_init(void){
	//Initializes all Leds (red, green, blue) pins direction.
	GPIO_setupPinDirection(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,PORT_OUTPUT);
	GPIO_setupPinDirection(RED_LED_PORT_ID,RED_LED_PIN_ID,PORT_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,PORT_OUTPUT);
	//Turn off all the Leds
	LED_off(RED);
	LED_off(GREEN);
	LED_off(BLUE);

}

void LED_on(LED_ID id){//Turns on the specified LED.
#if(LED_CONNECTION == POS_LOGIC)

	switch(id){
	case RED:
		 GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LOGIC_HIGH);
		 break;
	case GREEN:
		 GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LOGIC_HIGH);
		 break;
	case BLUE:
		 GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LOGIC_HIGH);
		 break;
	}

#elif(LED_CONNECTION == NEG_LOGIC)
	switch(id){
	case RED:
	 	 GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LOGIC_LOW);
	 	 break;
	case GREEN:
	 	 GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LOGIC_LOW);
	 	 break;
	case BLUE:
	 	 GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LOGIC_LOW);
	 	 break;
	}
#endif

}
void LED_off(LED_ID id){//Turns off the specified LED.
#if(LED_CONNECTION == POS_LOGIC)

	switch(id){
	case RED:
	 	 GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LOGIC_LOW);
	 	 break;
	case GREEN:
	 	 GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LOGIC_LOW);
	 	 break;
	case BLUE:
	 	 GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LOGIC_LOW);
	 	 break;
	}

#elif(LED_CONNECTION == NEG_LOGIC)
	 	switch(id){
	 	case RED:
	 			 GPIO_writePin(RED_LED_PORT_ID,RED_LED_PIN_ID,LOGIC_HIGH);
	 			 break;
	 	case GREEN:
	 			 GPIO_writePin(GREEN_LED_PORT_ID,GREEN_LED_PIN_ID,LOGIC_HIGH);
	 			 break;
	 	case BLUE:
	 			 GPIO_writePin(BLUE_LED_PORT_ID,BLUE_LED_PIN_ID,LOGIC_HIGH);
	 			 break;
	 		}
#endif

}
