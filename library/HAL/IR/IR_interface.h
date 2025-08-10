/*
 * IR_interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: Mohamed Atif
 */

#ifndef HAL_IR_IR_INTERFACE_H_
#define HAL_IR_IR_INTERFACE_H_
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/EXTI/EXTI_private.h"
void IR_voidInit(u8 Copy_u8EXTINo);
void IR_voidEnable(u8 Copy_u8EXTINo);
void IR_voidDisable(u8 Copy_u8EXTINo);
void IR_voidSetCallBack(void(*Copy_PtrToFunc)(void), u8 Copy_u8EXTINo );


#endif /* HAL_IR_IR_INTERFACE_H_ */
