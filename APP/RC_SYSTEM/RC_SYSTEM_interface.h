/*
 * RC_SYSTEM_interface.h
 *
 *  Created on: Aug 10, 2025
 *      Author: George Essmat
 */

#ifndef APP_RC_SYSTEM_RC_SYSTEM_INTERFACE_H_
#define APP_RC_SYSTEM_RC_SYSTEM_INTERFACE_H_

#define RC_SYSTEM_u8_AUTO_MODE		1
#define RC_SYSTEM_u8_MAN_MODE		0

void RC_SYSTEM_voidStart();

void RC_SYSTEM_voidInit();

void RC_SYSTEM_ReceiveISR(void);



#endif /* APP_RC_SYSTEM_RC_SYSTEM_INTERFACE_H_ */
