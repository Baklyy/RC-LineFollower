/*
 * delay.c
 *
 *  Created on: Jul 21, 2025
 *      Author: George Essmat
 */

#include "STD_TYPES.h"

void delay_ms(u32 ms)
{
	for(u32 i = 0; i < ms; i++)
	{
		for(u32 j = 0; j < 225; j++)
		{
			asm("NOP");
		}
	}
}
