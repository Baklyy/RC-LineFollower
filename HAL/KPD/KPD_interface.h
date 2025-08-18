/*
 * KPD_interface.h
 *
 *  Created on: Jul 21, 2025
 *      Author: George Essmat
 */

#ifndef HAL_KPD_KPD_INTERFACE_H_
#define HAL_KPD_KPD_INTERFACE_H_

#define KPD_u8_NUMBERS_LAYOUT		0
#define KPD_u8_ALPHABETS_LAYOUT 	1

void KPD_voidINIT();

u8 KPD_u8ReadKey();

u8 KPD_u8WaitAndReadKey();

void KPD_u8SetLayout(u8 KPD_u8_Layout);

void KPD_u8ToggleLayout();

#endif /* HAL_KPD_KPD_INTERFACE_H_ */
