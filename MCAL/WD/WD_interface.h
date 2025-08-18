/*
 * WD_interface.h
 *
 *  Created on: Jul 29, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_WD_WD_INTERFACE_H_
#define MCAL_WD_WD_INTERFACE_H_

#define WD_u8_PRESCALER_16K		0
#define WD_u8_PRESCALER_32K		1
#define WD_u8_PRESCALER_64K		2
#define WD_u8_PRESCALER_128K	3
#define WD_u8_PRESCALER_256K	4
#define WD_u8_PRESCALER_512K	5
#define WD_u8_PRESCALER_1024K	6
#define WD_u8_PRESCALER_2048K	7


void WD_voidInit();

void WD_voidEnable();

void WD_voidDisable();

void WD_voidSetPrescalar(u8 WD_u8_Prescaler_xK);

void WD_voidFeed();

#endif /* MCAL_WD_WD_INTERFACE_H_ */
