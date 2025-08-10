/*
 * Interrupt_private.h
 *
 *  Created on: Jul 23, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_GPI_GPI_PRIVATE_H_
#define MCAL_GPI_GPI_PRIVATE_H_

#define GPI_u8_SREG_REG  *((volatile u8 *)0x5f) //bit7: interrupt enable
#define GPI_u8_INTERRUPT_ENABLE_BIT 7

#define GPI_u8_ENABLE 1
#define GPI_u8_DISABLE 0

#endif /* MCAL_GPI_GPI_PRIVATE_H_ */
