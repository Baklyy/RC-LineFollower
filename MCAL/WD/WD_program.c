/*
 * WD_program.c
 *
 *  Created on: Jul 29, 2025
 *      Author: George Essmat
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "WD_interface.h"
#include "WD_private.h"
#include "WD_config.h"

void WD_voidInit()
{
	//enable the watch dog
	WD_voidEnable();

	//set watch dog prescaler
	WD_voidSetPrescalar(WD_u8_INITIAL_PRESCALER);
}


void WD_voidEnable()
{
	SET_BIT(WD_u8_WDTCR_REG,WD_u8_WDE_BIT);
}

void WD_voidDisable()
{
	WD_voidFeed();

	WD_u8_WDTCR_REG |= WD_u8_WATCH_DISABLE_MASK;
	CLR_BIT(WD_u8_WDTCR_REG,WD_u8_WDE_BIT);
}

void WD_voidSetPrescalar(u8 WD_u8_Prescaler_xK)
{
	WD_u8_WDTCR_REG = (WD_u8_WDTCR_REG & WD_u8_PRESCALER_MASK) | WD_u8_Prescaler_xK;
}

void WD_voidFeed()
{
	//reset the watch dog
	asm("wdr");
}
