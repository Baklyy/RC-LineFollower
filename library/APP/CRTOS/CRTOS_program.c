/*
 * RTOS_program.c
 *
 *  Created on: Aug 5, 2025
 *      Author: George Essmat
 */

#include "LIB/STD_TYPES.h"

#include "MCAL/TIM/TIM_interface.h"

#include "CRTOS_interface.h"
#include "CRTOS_private.h"
#include "CRTOS_config.h"

#define MAX_ARR_SIZE 10

CRTOS_TCP_t taskArr[MAX_ARR_SIZE];
u8 taskCounter = 0;

u8 delayCount = 0;
void CRTOS_voidMSDelay()
{
	delayCount++;
	if(delayCount == 4)
	{
		delayCount = 0;
		CRTOS_voidSH();
	}
}

void CRTOS_voidInit()
{
	TIM0_voidInit();
	TIM0_voidSetOverFlowCallBack(CRTOS_voidMSDelay);
	TIM0_voidEnableOverFlowInterrupt();
}



void CRTOS_voidCreateTask(u16 period, u16 firstDelay, void (*pf)(void))
{
	taskArr[taskCounter].period = period;
	taskArr[taskCounter].delay = firstDelay;
	taskArr[taskCounter].state = state_Ready;
	taskArr[taskCounter].pf = pf;
	taskCounter++;
}


void CRTOS_voidSH()
{
	for(u8 taskIndex = 0; taskIndex < taskCounter; taskIndex++)
	{
		if(taskArr[taskIndex].delay == 0)
		{

			taskArr[taskIndex].delay = taskArr[taskIndex].period;
			if(taskArr[taskIndex].state != state_Suspending)
			{
				taskArr[taskIndex].state = state_Running;
				taskArr[taskIndex].pf();
				taskArr[taskIndex].state = state_Ready;
			}

		}
		else
		{
			taskArr[taskIndex].delay--;
		}
	}
}

void CRTOS_voidSuspendTask(u8 taskIndex)
{
	taskArr[taskIndex].state = state_Suspending;
}

void CRTOS_voidMakeTaskReady(u8 taskIndex)
{
	taskArr[taskIndex].state = state_Ready;
}

void CRTOS_voidDeleteTask(void (*pf)(void))
{
	u8 taskIndex = 0;
	for(; taskIndex < taskCounter; taskIndex++)
	{
		if(taskArr[taskIndex].pf == pf)
		{
			break;
		}
	}


	if(taskIndex != (MAX_ARR_SIZE-1))
	{
		for(;taskIndex < taskCounter; taskIndex++)
		{
			CRTOS_TCP_t temp = taskArr[taskIndex];
			taskArr[taskIndex] = taskArr[taskIndex+1];
			taskArr[taskIndex+1] = temp;
		}
	}
	taskCounter--;
}
