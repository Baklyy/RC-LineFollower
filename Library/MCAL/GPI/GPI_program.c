/*
 * Interrupt_program.c
 *
 *  Created on: Jul 23, 2025
 *      Author: George Essmat
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "GPI_interface.h"
#include "GPI_private.h"
#include "GPI_config.h"

void GPI_voidInit()
{
	switch(GPI_u8_INITIAL_STATE)
	{
	case GPI_u8_ENABLE:
		GPI_voidEnable();
		break;
	case GPI_u8_DISABLE:
		GPI_voidDisable();
		break;
	}
}


void GPI_voidEnable()
{
	SET_BIT(GPI_u8_SREG_REG,GPI_u8_INTERRUPT_ENABLE_BIT);
}


void GPI_voidDisable()
{
	CLR_BIT(GPI_u8_SREG_REG,GPI_u8_INTERRUPT_ENABLE_BIT);
}
