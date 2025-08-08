/*
 * UART_interface.h
 *
 *  Created on: Jul 30, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#define UART_u8_ASYNC_MODE		0
#define UART_u8_SYNC_MODE		1

#define UART_u8_PARITY_DISABLED		0
#define UART_u8_PARITY_EVEN			2
#define UART_u8_PARITY_ODD			3

#define UART_u8_ONE_STOP_BIT		0
#define UART_u8_TWO_STOP_BIT		1

#define UART_u8_FIVE_BIT_WORD		0
#define UART_u8_SIX_BIT_WORD		1
#define UART_u8_SEVEN_BIT_WORD		2
#define UART_u8_EIGHT_BIT_WORD		3
#define UART_u8_NINE_BIT_WORD		7

#define UART_u8_RISING_XCK_EDGE		0
#define UART_u8_FALLING_XCK_EDGE	1

#define UART_u8_RECEIVE_CORRECT		0
#define UART_u8_FRAME_ERROR			1
#define UART_u8_DATA_OVERRUN		2
#define UART_u8_PARITY_ERROR		3

#define UART_u8_MAX_FRACTION_DIGITS 			3
#define UART_u8_MAX_FRACTION_DIGITS_FACTOR	1000
#define UART_u8_MINMUM_FRACTION				0.001


void UART_voidInit();

void UART_voidMode(u8 UART_u8_Mode);

void UART_voidSetParityMode(u8 UART_u8_Parity_Mode);

void UART_voidSetStopBits(u8 UART_u8_Num_Of_Stop_Bits);

void UART_voidSetWordSize(u8 UART_u8_Word_Size);

void UART_voidSetClockPolarity(u8 UART_u8_Polarity);

void UART_voidSetBaudRate(u16 UART_u16_Baud_Rate);

void UART_voidTransmitterEnable();

void UART_voidReceiverEnable();

void UART_voidTransmitterDisable();

void UART_voidReceiverDisable();

void UART_voidTransmit(u8 UART_u8_Data);

void UART_voidTransmitInteger(u32 integer);

void UART_voidTransmitFraction(u32 frac);

void UART_voidTransmitNumber(f32 num);

void UART_voidTransmitStr(u8* str);

u16 UART_u16Receive(u8* errorState);

u8 UART_u16Read();

void UART_voidEnableReceiveInterrupt();

void UART_voidDisableReceiveInterrupt();

void UART_voidEnableTransmissionInterrupt();

void UART_voidDisableTransmissionInterrupt();

void UART_voidEnableDataRegisterEmptyInterrupt();

void UART_voidDisableDataRegisterEmptyInterrupt();

void UART_voidSetReceiveCallBack(void (*pf)(void));

void UART_voidSetTransmissionCallBack(void (*pf)(void));

void UART_voidSetDataRegisterEmptyCallBack(void (*pf)(void));

#endif /* MCAL_UART_UART_INTERFACE_H_ */
