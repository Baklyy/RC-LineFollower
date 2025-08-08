/*
 * StepperMotor_program.c
 *
 *  Created on: Jul 22, 2025
 *      Author: George Essmat
 */

#include "LIB/STD_TYPES.h"
#include "LIB/delay.h"

#include "MCAL/DIO/DIO_interface.h"

#include "StepperMotor_interface.h"
#include "StepperMotor_private.h"
#include "StepperMotor_config.h"

void StepperMotor_voidInit()
{
	DIO_u8SetPinDirection(StepperMotor_u8_PORT,StepperMotor_u8_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(StepperMotor_u8_PORT,StepperMotor_u8_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(StepperMotor_u8_PORT,StepperMotor_u8_PIN2,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(StepperMotor_u8_PORT,StepperMotor_u8_PIN3,DIO_u8_OUTPUT);

	DIO_u8SetPinValue(StepperMotor_u8_PORT,StepperMotor_u8_PIN0,DIO_u8_LOW);
	DIO_u8SetPinValue(StepperMotor_u8_PORT,StepperMotor_u8_PIN1,DIO_u8_LOW);
	DIO_u8SetPinValue(StepperMotor_u8_PORT,StepperMotor_u8_PIN2,DIO_u8_LOW);
	DIO_u8SetPinValue(StepperMotor_u8_PORT,StepperMotor_u8_PIN3,DIO_u8_LOW);

}



u8 StepperMotor_u8MoveMotor(u8 direction, u16 angle)
{
	if((direction != 0) &&(direction != 1))
	{
		return StepperMotor_u8_Error;
	}

	u32 maxIter = (((2048ul*angle)/360)/4);
	for(u32 iter = 0; iter < maxIter; iter++)
	{
		DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN0:StepperMotor_u8_PIN3,DIO_u8_HIGH);
		delay_ms(10);
		DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN0:StepperMotor_u8_PIN3,DIO_u8_LOW);
		DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN1:StepperMotor_u8_PIN2,DIO_u8_HIGH);
		delay_ms(10);
		DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN1:StepperMotor_u8_PIN2,DIO_u8_LOW);
		DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN2:StepperMotor_u8_PIN1,DIO_u8_HIGH);
		delay_ms(10);
		DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN2:StepperMotor_u8_PIN1,DIO_u8_LOW);
		DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN3:StepperMotor_u8_PIN0,DIO_u8_HIGH);
		delay_ms(10);
		DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN3:StepperMotor_u8_PIN0,DIO_u8_LOW);
	}

	return StepperMotor_u8_Correct;
}

u8 StepperMotor_u8MoveMotorSteps(u8 direction, u32 steps)
{
	if((direction != 0) &&(direction != 1))
		{
			return StepperMotor_u8_Error;
		}

		u32 maxIter = steps/4;
		for(u32 iter = 0; iter < maxIter; iter++)
		{
			DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN0:StepperMotor_u8_PIN3,DIO_u8_HIGH);
			delay_ms(10);
			DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN0:StepperMotor_u8_PIN3,DIO_u8_LOW);
			DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN1:StepperMotor_u8_PIN2,DIO_u8_HIGH);
			delay_ms(10);
			DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN1:StepperMotor_u8_PIN2,DIO_u8_LOW);
			DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN2:StepperMotor_u8_PIN1,DIO_u8_HIGH);
			delay_ms(10);
			DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN2:StepperMotor_u8_PIN1,DIO_u8_LOW);
			DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN3:StepperMotor_u8_PIN0,DIO_u8_HIGH);
			delay_ms(10);
			DIO_u8SetPinValue(StepperMotor_u8_PORT,(direction)?StepperMotor_u8_PIN3:StepperMotor_u8_PIN0,DIO_u8_LOW);
		}

		return StepperMotor_u8_Correct;
}

