/*
 * DCMSC_program.c
 *
 *  Created on: Aug 6, 2025
 *      Author: George Essmat
 */


#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIM/TIM_interface.h"

#include "DCMSC_interface.h"
#include "DCMSC_private.h"
#include "DCMSC_config.h"


void DCMSC_voidInit()
{
	//set-up timer0 pwm
	TIM0_voidPWMInit();
	TIM0_voidSetOutputCompareMode(TIM0_u8_OC0_CLEAR);
	DIO_u8SetPinDirection(TIM0_u8_PORT,TIM0_u8_OC0_PIN,DIO_u8_OUTPUT);

	//set-up timer2 pwm
	TIM2_voidPWMInit();
	TIM2_voidSetOutputCompareMode(TIM2_u8_OC2_CLEAR);
	DIO_u8SetPinDirection(TIM2_u8_PORT,TIM2_u8_OC2_PIN,DIO_u8_OUTPUT);

	//set-up the direction pins
	DIO_u8SetPinDirection(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN1_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN2_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN3_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN4_PIN,DIO_u8_OUTPUT);

	//set all the direction pins to low
	DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN1_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN2_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN3_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN4_PIN,DIO_u8_LOW);
}

void DCMSC_voidSetDirectionAndRPM(u8 DCMSC_u8_MOTORx, u8 DCMSC_u8_Direction, u16 DCMSC_u8_RPM)
{
	//this function takes the motor number, the direction
	//of rotation and the rpm requeired
	switch(DCMSC_u8_MOTORx)
	{
	case DCMSC_u8_MOTOR1:
		switch(DCMSC_u8_Direction)
		{
		case DCMSC_u8_CW_ROTATION:
			DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN1_PIN,DIO_u8_HIGH);
			DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN2_PIN,DIO_u8_LOW);
			break;
		case DCMSC_u8_CCW_ROTATION:
			DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN1_PIN,DIO_u8_LOW);
			DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN2_PIN,DIO_u8_HIGH);
			break;
		}
		//set the rpm (chat-GPT helped with formula)
		TIM0_voidSetOCR0((((f32)DCMSC_u8_RPM)/DCMSC_f32_MAX_RPM)*255);
		break;
	case DCMSC_u8_MOTOR2:
		switch(DCMSC_u8_Direction)
		{
		case DCMSC_u8_CW_ROTATION:
			DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN3_PIN,DIO_u8_HIGH);
			DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN4_PIN,DIO_u8_LOW);
			break;
		case DCMSC_u8_CCW_ROTATION:
			DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN3_PIN,DIO_u8_LOW);
			DIO_u8SetPinValue(DCMSC_u8_DIRECTION_PORT,DCMSC_u8_IN4_PIN,DIO_u8_HIGH);
			break;
		}
		//set the rpm (chat-GPT helped with formula)
		TIM2_voidSetOCR2((((f32)DCMSC_u8_RPM)/DCMSC_f32_MAX_RPM)*255);
		break;
	}
}
