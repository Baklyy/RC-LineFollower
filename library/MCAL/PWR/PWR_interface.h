/*
 * PWR_interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_PWR_PWR_INTERFACE_H_
#define MCAL_PWR_PWR_INTERFACE_H_

#define PWR_u8_MODE_IDLE					0
#define PWR_u8_MODE_ADC_NOISE_REDUCTION		1
#define PWR_u8_MODE_POWER_DOWN				2
#define PWR_u8_MODE_POWER_SAVE				3
#define PWR_u8_MODE_STANDBY					6
#define PWR_u8_MODE_EXTENDED_STANDBY		7

void PWR_voidInit();

void PWR_voidSetPowerMode(u8 PWR_u8_Power_Mode);

void PWR_voidSleep();

#endif /* MCAL_PWR_PWR_INTERFACE_H_ */
