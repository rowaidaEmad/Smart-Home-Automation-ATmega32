/*
 * led.h
 *
 *  Created on: Sep 30, 2025
 *      Author: HP
 */

#ifndef LED_H_
#define LED_H_
#define GREEN_LED_PORT_ID PORTB_ID
#define RED_LED_PORT_ID PORTB_ID
#define BLUE_LED_PORT_ID PORTB_ID

#define GREEN_LED_PIN_ID PIN6_ID
#define RED_LED_PIN_ID PIN5_ID
#define BLUE_LED_PIN_ID PIN7_ID

#define LED_CONNECTION POS_LOGIC
#include "std_types.h"

typedef enum{NEG_LOGIC=0,POS_LOGIC=1}led_logic;
typedef enum{RED=0,GREEN=1,BLUE=2}LED_ID;
//functions
void LEDS_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);
#endif /* LED_H_ */
