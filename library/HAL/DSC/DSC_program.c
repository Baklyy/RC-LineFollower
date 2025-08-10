/*
 * DSC_program.c
 *
 *  Created on: Aug 6, 2025
 *      Author: George Essmat
 */


#include "LIB/STD_TYPES.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/TIM/TIM_interface.h"

#include "DSC_interface.h"
#include "DSC_private.h"
#include "DSC_config.h"


void DSC_voidInit()
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
	DIO_u8SetPinDirection(DSC_u8_DIRECTION_PORT,DSC_u8_IN1_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DSC_u8_DIRECTION_PORT,DSC_u8_IN2_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DSC_u8_DIRECTION_PORT,DSC_u8_IN3_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(DSC_u8_DIRECTION_PORT,DSC_u8_IN4_PIN,DIO_u8_OUTPUT);

	//set all the direction pins to low
	DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN1_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN2_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN3_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN4_PIN,DIO_u8_LOW);
}

void DSC_voidSetDirectionAndRPM(u8 DSC_u8_Direction, u16 DSC_u8_RPM)
{
	switch(DSC_u8_Direction)
	{
	case DSC_u8_FORWARD:
		DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN1_PIN,DIO_u8_HIGH);
		DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN3_PIN,DIO_u8_HIGH);
		DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN2_PIN,DIO_u8_LOW);
		DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN4_PIN,DIO_u8_LOW);
		break;
	case DSC_u8_BACKWORD:
		DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN1_PIN,DIO_u8_LOW);
		DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN3_PIN,DIO_u8_LOW);
		DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN2_PIN,DIO_u8_HIGH);
		DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN4_PIN,DIO_u8_HIGH);
		break;
	}
	TIM0_voidSetOCR0((((f32)DSC_u8_RPM)/DSC_f32_MAX_RPM)*255);
	TIM2_voidSetOCR2((((f32)DSC_u8_RPM)/DSC_f32_MAX_RPM)*255);

}

void DSC_voidStop()
{
	DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN1_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN3_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN2_PIN,DIO_u8_LOW);
	DIO_u8SetPinValue(DSC_u8_DIRECTION_PORT,DSC_u8_IN4_PIN,DIO_u8_LOW);
}
