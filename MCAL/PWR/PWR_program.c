/*
 * PWR_program.c
 *
 *  Created on: Aug 5, 2025
 *      Author: George Essmat
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "PWR_interface.h"
#include "PWR_private.h"
#include "PWR_config.h"


void PWR_voidInit()
{
	PWR_voidSetPowerMode(PWR_u8_INITIAL_MODE);

	SET_BIT(PWR_u8_MCUCR_REG,PWR_u8_MCUCR_SE);
}


void PWR_voidSetPowerMode(u8 PWR_u8_Power_Mode)
{
	PWR_u8_MCUCR_REG = (PWR_u8_MCUCR_REG & PWR_u8_POWER_MODE_MASK) | (PWR_u8_Power_Mode << PWR_u8_MCUCR_SM0);
}

void PWR_voidSleep()
{
	asm("SLEEP");
}
