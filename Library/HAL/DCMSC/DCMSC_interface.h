/*
 * DCMSC_interface.h
 *
 *  Created on: Aug 6, 2025
 *      Author: George Essmat
 */

#ifndef HAL_DCMSC_DCMSC_INTERFACE_H_
#define HAL_DCMSC_DCMSC_INTERFACE_H_

#define DCMSC_f32_MAX_RPM		100.0

#define DCMSC_u8_CW_ROTATION		1
#define DCMSC_u8_CCW_ROTATION		0

#define DCMSC_u8_MOTOR1			1
#define DCMSC_u8_MOTOR2			2


void DCMSC_voidInit();

void DCMSC_voidSetDirectionAndRPM(u8 DCMSC_u8_MOTORx, u8 DCMSC_u8_Direction, u16 DCMSC_u8_RPM);

#endif /* HAL_DCMSC_DCMSC_INTERFACE_H_ */
