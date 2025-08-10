/*
 * EXTI_interface.h
 *
 *  Created on: Jul 23, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#define EXTI_u8_EXTI0 0
#define EXTI_u8_EXTI1 1
#define EXTI_u8_EXTI2 2

#define EXTI_u8_LOW_LEVEL 			0
#define EXTI_u8_ANY_LOGICAL_CHANGE 	1
#define EXTI_u8_FALLING_EDGE 		2
#define EXTI_u8_RISING_EDGE 		3

void EXTI_voidEXTIEnable(u8 Copy_u8EXTINo, u8 Copy_u8EXTISense);

void EXTI_voidEXTIDisable(u8 Copy_u8EXTINo);

void EXTI_voidSetCallBack( void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTIIndex);

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
