/*
 * smarHomeAppl.c
 *
 *  Created on: Sep 30, 2025
 *      Author: Rowaida Emad Khalaf
 */
#include "LCD.h"
#include "LED.h"
#include "BUZZER.h"
#include "DC_MOTOR.h"
#include "FlameSensor.h"
#include "lm35_sensor.h"
#include "LDR.h"
#include "adc.h"

void Automatic_Lighting_Control(uint16 Light_intensity);
void Automatic_Fan_Speed_Control(uint8 room_temp);
void LCD_Display_Real_time_feedback(uint16 Light_intensity,uint8 room_temp);
int main(void){
	//initialize all drivers
	ADC_init();
	Buzzer_init();
	DcMotor_Init();
	FlameSensor_init();
	LCD_init();
	LEDS_init();
while(1){

	uint16 Light_intensity = LDR_getLightIntensity();
	uint8 room_temp = LM35_getTemperature();
	uint8 flame_flag = FlameSensor_getValue();

	if(flame_flag){
		LCD_clearScreen();
		Buzzer_on();
		 DcMotor_Rotate(stop, 0);
		LCD_displayString("Critical alert!");
		while(flame_flag){//polling while flag = 1
			flame_flag = FlameSensor_getValue();
		}
		Buzzer_off();
		LCD_clearScreen();
	}

	LCD_Display_Real_time_feedback( Light_intensity, room_temp);
	Automatic_Lighting_Control(Light_intensity);
	Automatic_Fan_Speed_Control(room_temp);
}


}
void LCD_Display_Real_time_feedback(uint16 Light_intensity,uint8 room_temp){
	//temp
		LCD_displayStringRowColumn(1,0,"TEMP=");
		if(room_temp >= 100)
		{
			LCD_intgerToString(room_temp);
		}
		else
		{
			LCD_intgerToString(room_temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
//ldr
		LCD_displayStringRowColumn(1,8,"LDR=");
		if(Light_intensity < 100)
		{
			LCD_intgerToString(Light_intensity);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		else
		{
			LCD_intgerToString(Light_intensity);

		}
		LCD_displayCharacter('%');
}
void Automatic_Lighting_Control(uint16 Light_intensity){
	if(Light_intensity <= 15){
		LED_on(RED);
		LED_on(GREEN);
		LED_on(BLUE);
	}
	else if((Light_intensity >= 16) &&(Light_intensity <= 50)){
		LED_on(RED);
		LED_on(GREEN);

		LED_off(RED);
	}
	else if((Light_intensity >= 51) &&(Light_intensity <= 70)){
		LED_on(RED);

		LED_off(GREEN);
		LED_off(BLUE);
	}
	else if(Light_intensity > 70){
		LED_off(RED);
		LED_off(GREEN);
		LED_off(BLUE);
	}
}
void Automatic_Fan_Speed_Control(uint8 room_temp){
	if(room_temp >= 40){
		DcMotor_Rotate(cw,100);
		LCD_displayStringRowColumn(0,4,"FAN IS ON ");
	}
	else if((room_temp >=35) && (room_temp<40)){
		DcMotor_Rotate(cw,75);
		LCD_displayStringRowColumn(0,4,"FAN IS ON ");
	}
	else if ((room_temp >=30) && (room_temp<35)){
		DcMotor_Rotate(cw,50);
		LCD_displayStringRowColumn(0,4,"FAN IS ON ");
	}
	else if((room_temp >=25) && (room_temp<30)){
		DcMotor_Rotate(cw,25);
		LCD_displayStringRowColumn(0,4,"FAN IS ON ");
	}
	else{
		DcMotor_Rotate(stop,0);
		LCD_displayStringRowColumn(0,4,"FAN IS OFF");
	}
}


