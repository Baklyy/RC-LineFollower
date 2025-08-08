/*
 * IR_program.c
 *
 *  Created on: Aug 5, 2025
 *      Author: Mohamed Atif
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"


void IR_voidInit(u8 Copy_u8EXTINo)
{

}
void IR_voidEnable(u8 Copy_u8EXTINo)
{
	EXTI_voidEXTIEnable(Copy_u8EXTINo, EXTI_u8_FALLING_EDGE);
}
void IR_voidDisable(u8 Copy_u8EXTINo)
{
	EXTI_voidEXTIDisable(Copy_u8EXTINo);
}
void IR_voidSetCallBack(void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTINo )
{
	EXTI_voidSetCallBack(Copy_PtrToFunc,Copy_u8EXTINo);
}
