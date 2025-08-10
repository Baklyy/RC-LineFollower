/*
 * USS_program.c
 *
 *  Created on: Aug 4, 2025
 *      Author: George Essmat
 */


#include "LIB/STD_TYPES.h"
#include "LIB/delay.h"
#include "avr/delay.h"

#include "MCAL/TIM/TIM_interface.h"
#include "MCAL/DIO/DIO_interface.h"

#include "USS_interface.h"
#include "USS_config.h"


u16 USS_timeLapsed = 0;					//a variable used to measure the time of a pulse
u8 USS_distArr[MAX_ARR_SIZE] = {0.0};	//an array to store 10 measurements
u8 USS_arrCount = 0;					//array index counter
u8 USS_state = 0;						//state for calculating the time of the echo pulse
u16 USS_startCount = 0;					//the start of the echo pulse

void USS_measureDistance()
{
	//measure the echo pulse
	switch(USS_state)
	{
	case 0:
		//start of the pulse
		USS_startCount = TIM1_u16GetICR1Val();
		USS_state = 1;
		TIM1_voidSetInputCaptureCEdge(TIM1_u8_INPUT_CAPTURE_FALLING_EDGE);
		DIO_u8SetPinValue(TIM1_u8_PORT,TIM1_u8_ICP1_PIN,DIO_u8_HIGH);
		break;
	case 1:
		//end of the pulse
		USS_timeLapsed = TIM1_u16GetICR1Val() - USS_startCount;
		USS_state = 0;
		TIM1_voidSetInputCaptureCEdge(TIM1_u8_INPUT_CAPTURE_RISING_EDGE);
		DIO_u8SetPinValue(TIM1_u8_PORT,TIM1_u8_ICP1_PIN,DIO_u8_LOW);
		USS_distArr[USS_arrCount] =(u8)(100*((((f32)((USS_timeLapsed>MAX_ALLOWED_TIME)?MAX_ALLOWED_TIME:USS_timeLapsed)*(0.000032))*343.0)/2.0));
		USS_arrCount++;
		if(USS_arrCount == MAX_ARR_SIZE)
		{
			USS_arrCount = 0;
		}
		break;
	}
}


void USS_triggerSensor()
{
	//send 15us pulse
	DIO_u8SetPinValue(USS_u8_TRIGGER_PORT, USS_u8_TRIGGER_PIN,DIO_u8_HIGH);
	_delay_us(15);
	DIO_u8SetPinValue(USS_u8_TRIGGER_PORT, USS_u8_TRIGGER_PIN,DIO_u8_LOW);
}


void USS_voidInit()
{
	//set-up timer1
	TIM1_voidPWMInit();

	//set-up trigger
	DIO_u8SetPinDirection(USS_u8_TRIGGER_PORT, USS_u8_TRIGGER_PIN, DIO_u8_OUTPUT);
	DIO_u8SetPinValue(USS_u8_TRIGGER_PORT, USS_u8_TRIGGER_PIN,DIO_u8_LOW);
	TIM1_voidSetOverFlowCallBack(USS_triggerSensor);

	//set-up the echo(input capture)
	DIO_u8SetPinDirection(TIM1_u8_PORT,TIM1_u8_ICP1_PIN,DIO_u8_INPUT);
	DIO_u8SetPinValue(TIM1_u8_PORT,TIM1_u8_ICP1_PIN,DIO_u8_LOW);
	TIM1_voidSetInputCaptureCallBack(USS_measureDistance);
	TIM1_voidEnableInputCaptureNoiseCanceler();
	TIM1_voidSetInputCaptureCEdge(TIM1_u8_INPUT_CAPTURE_RISING_EDGE);

	//enable interrrupts
	TIM1_voidEnableOverFlowInterrupt();
	TIM1_voidEnableInputCaptureInterrupt();
}


f32 USS_f32GetDistance()
{

	if(USS_u8_RESULT_CORRECTION_ALGO)
	{
		//alogrithm for getting the average

		u8 max = USS_distArr[0];
		u8 min = USS_distArr[0];
		u8 sum = 0.0;
		for(u8 index = 0; index < MAX_ARR_SIZE;index++)
		{
			if(max < USS_distArr[index])
			{
				max = USS_distArr[index];
			}
			if(min > USS_distArr[index])
			{
				min = USS_distArr[index];
			}
			sum += USS_distArr[index];
		}


			return (sum-(max + min))/8;
	}
	else
	{
		//algorithm for getting the median

		for(u8 i = 0; i < MAX_ARR_SIZE; i++)
		{
			for(u8 j=0; j < (MAX_ARR_SIZE-i-1); j++)
			{
				if(USS_distArr[j] > USS_distArr[j+1])
				{
					u8 temp = USS_distArr[j+1];
					USS_distArr[j+1] = USS_distArr[j];
					USS_distArr[j] = temp;
				}
			}
		}

		return (USS_distArr[(MAX_ARR_SIZE/2)-1]+USS_distArr[MAX_ARR_SIZE/2])/2.0;
	}
}


