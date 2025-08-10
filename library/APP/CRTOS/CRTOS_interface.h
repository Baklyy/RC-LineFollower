/*
 * RTOS_interface.h
 *
 *  Created on: Aug 5, 2025
 *      Author: George Essmat
 */

#ifndef APP_CRTOS_CRTOS_INTERFACE_H_
#define APP_CRTOS_CRTOS_INTERFACE_H_

typedef enum{
	state_Dormint,
	state_Ready,
	state_Running,
	state_Waiting,
	state_Suspending,
	Max_States_Num,
}CRTOS_State_t;

typedef struct{
	u16 period;
	u16 delay;
	CRTOS_State_t state;
	void (*pf)(void);
}CRTOS_TCP_t;





void CRTOS_voidInit();

void CRTOS_voidMSDelay();

void CRTOS_voidCreateTask(u16 period, u16 firstDelay, void (*pf)(void));

void CRTOS_voidSH();

void CRTOS_voidSuspendTask(u8 taskIndex);

void CRTOS_voidMakeTaskReady(u8 taskIndex);

void CRTOS_voidDeleteTask(void (*pf)(void));

#endif /* APP_CRTOS_CRTOS_INTERFACE_H_ */
