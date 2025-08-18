/*
 * PWR_private.h
 *
 *  Created on: Aug 5, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_PWR_PWR_PRIVATE_H_
#define MCAL_PWR_PWR_PRIVATE_H_

#define PWR_u8_MCUCR_REG	*((volatile u8*) 0x55)

#define PWR_u8_MCUCR_SE			7
#define PWR_u8_MCUCR_SM2		6
#define PWR_u8_MCUCR_SM1		5
#define PWR_u8_MCUCR_SM0		4

#define PWR_u8_POWER_MODE_MASK	0b10001111

#endif /* MCAL_PWR_PWR_PRIVATE_H_ */
