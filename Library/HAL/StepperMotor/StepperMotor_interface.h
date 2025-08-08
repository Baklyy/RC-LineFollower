/*
 * StepperMotor_interface.h
 *
 *  Created on: Jul 22, 2025
 *      Author: George Essmat
 */

#ifndef HAL_STEPPERMOTOR_STEPPERMOTOR_INTERFACE_H_
#define HAL_STEPPERMOTOR_STEPPERMOTOR_INTERFACE_H_

#define StepperMotor_u8_CW  1
#define StepperMotor_u8_CCW 0

#define StepperMotor_u8_Error 	1
#define StepperMotor_u8_Correct 0


void StepperMotor_voidInit();

u8 StepperMotor_u8MoveMotor(u8 direction, u16 angle);

u8 StepperMotor_u8MoveMotorSteps(u8 direction, u32 steps);

#endif /* HAL_STEPPERMOTOR_STEPPERMOTOR_INTERFACE_H_ */
