/*
 * EXTI_private.h
 *
 *  Created on: Jul 23, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define EXTI_u8_GICR_REG  		*((volatile u8 *)0x5B)

#define EXTI_u8_GICR_INT0 6
#define EXTI_u8_GICR_INT1 7
#define EXTI_u8_GICR_INT2 5


#define EXTI_u8_MCUCR_REG	 	*((volatile u8 *)0x55) //first two bits for int0, the second two bits are for int1

#define EXTI_u8_MCUCR_ISC00 0
#define EXTI_u8_MCUCR_ISC01 1
#define EXTI_u8_MCUCR_ISC10 2
#define EXTI_u8_MCUCR_ISC11 3


#define EXTI_u8_MCUCSR_REG  	*((volatile u8*)0x54)
#define EXTI_u8_MCUCSR_ISC2 6


#define EXTI_u8_GIFR_REG             *((volatile u8*)0x5A)

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
