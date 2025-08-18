/*
 * EXTI_program.c
 *
 *  Created on: Jul 23, 2025
 *      Author: George Essmat
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

static void (*pf[3])(void) = {NULL,NULL,NULL};



void EXTI_voidEXTIEnable(u8 Copy_u8EXTINo, u8 Copy_u8EXTISense)
{
	switch(Copy_u8EXTINo)
	{
	case EXTI_u8_EXTI0:
		DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_INPUT);
		DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN2,DIO_u8_HIGH);
		switch(Copy_u8EXTISense)
		{
		case EXTI_u8_LOW_LEVEL:
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
			break;
		case EXTI_u8_ANY_LOGICAL_CHANGE:
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
			break;
		case EXTI_u8_FALLING_EDGE:
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
			break;
		case EXTI_u8_RISING_EDGE:
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC00);
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC01);
			break;
		}
		SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT0);
		break;
	case EXTI_u8_EXTI1:
		DIO_u8SetPinDirection(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_INPUT);
		DIO_u8SetPinValue(DIO_u8_PORTD,DIO_u8_PIN3,DIO_u8_HIGH);
		switch(Copy_u8EXTISense)
		{
		case EXTI_u8_LOW_LEVEL:
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
			break;
		case EXTI_u8_ANY_LOGICAL_CHANGE:
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
			break;
		case EXTI_u8_FALLING_EDGE:
			CLR_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
			break;
		case EXTI_u8_RISING_EDGE:
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC10);
			SET_BIT(EXTI_u8_MCUCR_REG,EXTI_u8_MCUCR_ISC11);
			break;
		}
		SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT1);
		break;
	case EXTI_u8_EXTI2:
		DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_INPUT);
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN2,DIO_u8_HIGH);
		switch(Copy_u8EXTISense)
		{
		case EXTI_u8_FALLING_EDGE:
			CLR_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_MCUCSR_ISC2);
			break;
		case EXTI_u8_RISING_EDGE:
			SET_BIT(EXTI_u8_MCUCSR_REG,EXTI_u8_MCUCSR_ISC2);
			break;
		}
		SET_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT2);
		break;
	}
}



void EXTI_voidEXTIDisable(u8 Copy_u8EXTINo)
{
	switch(Copy_u8EXTINo)
		{
		case EXTI_u8_EXTI0:
			CLR_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT0);
			pf[EXTI_u8_EXTI0] = NULL;
			break;
		case EXTI_u8_EXTI1:
			CLR_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT1);
			pf[EXTI_u8_EXTI1] = NULL;
			break;
		case EXTI_u8_EXTI2:
			CLR_BIT(EXTI_u8_GICR_REG,EXTI_u8_GICR_INT2);
			pf[EXTI_u8_EXTI2] = NULL;
			break;
		}
}



void EXTI_voidSetCallBack( void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex)
{
	pf[Copy_u8EXTIIndex] = Copy_PtrToFunc;
}


void __vector_1(void) 	__attribute__((signal));
void __vector_1(void)
{
	if(pf[EXTI_u8_EXTI0] == NULL) {return;}
	pf[EXTI_u8_EXTI0]();
}

void __vector_2(void) 	__attribute__((signal));
void __vector_2(void)
{
	if(pf[EXTI_u8_EXTI1] == NULL) {return;}
	pf[EXTI_u8_EXTI1]();
}


void __vector_3(void) 	__attribute__((signal));
void __vector_3(void)
{
	if(pf[EXTI_u8_EXTI2] == NULL) {return;}
	pf[EXTI_u8_EXTI2]();
}

