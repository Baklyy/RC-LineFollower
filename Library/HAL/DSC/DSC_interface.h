/*
 * DSC_interface.h
 *
 *  Created on: Aug 6, 2025
 *      Author: George Essmat
 */

#ifndef HAL_DSC_DSC_INTERFACE_H_
#define HAL_DSC_DSC_INTERFACE_H_

#define DSC_f32_MAX_RPM		100.0

#define DSC_u8_FORWARD		1
#define DSC_u8_BACKWORD		0

void DSC_voidInit();

void DSC_voidSetDirectionAndRPM(u8 DSC_u8_Direction, u16 DSC_u8_RPM);

void DSC_voidStop();

#endif /* HAL_DSC_DSC_INTERFACE_H_ */

