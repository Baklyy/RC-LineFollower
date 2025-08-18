/*
 * USS_interface.h
 *
 *  Created on: Aug 4, 2025
 *      Author: George Essmat
 */

#ifndef HAL_USS_USS_INTERFACE_H_
#define HAL_USS_USS_INTERFACE_H_

#define USS_u8_GET_AVERAGE 	1
#define USS_u8_GET_MEDIAN 	0

#define MAX_ARR_SIZE	10
#define MAX_ALLOWED_TIME 250

#define USS_u8_TRIGGER_PORT		DIO_u8_PORTC
#define USS_u8_TRIGGER_PIN		DIO_u8_PIN0

#define USS_f32_COLLISION_DIST		20.0

void USS_voidInit();

f32 USS_f32GetDistance();

void USS_triggerSensor();

void USS_measureDistance();

#endif /* HAL_USS_USS_INTERFACE_H_ */
