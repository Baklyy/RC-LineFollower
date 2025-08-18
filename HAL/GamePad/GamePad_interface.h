/*
 * GamePad_interface.h
 *
 *  Created on: Aug 4, 2025
 *      Author: Mohamed Atif
 */

#ifndef HAL_GAMEPAD_GAMEPAD_INTERFACE_H_
#define HAL_GAMEPAD_GAMEPAD_INTERFACE_H_

typedef enum
{
	GAMEPAD_DIGITAL,
	GAMEPAD_ANALOG,
	GAMEPAD_ACCL
}func_t;
typedef enum
{
	START,
	SELECT,
	TRIANGLE,
	CIRCLE,
	CROSS,
	SQUARE,
	NO_BUTTON_PRESSED,
	UP,
	DOWN,
	RIGHT,
	LEFT,
	forward,
	forwardRight,
	forwardLeft,
	backward,
	backwardRight,
	backwardLeft,
	BUTTON_ERROR,
}button_t;

button_t GamePad_ButtonPressed(u8 *Frame);

button_t GamePad_JoyStickMoved(u8 *frame);

#endif /* HAL_GAMEPAD_GAMEPAD_INTERFACE_H_ */
