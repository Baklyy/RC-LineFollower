/*
 * UART_private.h
 *
 *  Created on: Jul 30, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_


#define UART_u8_UCSRA_REG		*((volatile u8*) 0x2B)

#define UART_u8_RXC_BIT			7
#define UART_u8_TXC_BIT			6
#define UART_u8_UDRE_BIT		5
#define UART_u8_FE_BIT			4
#define UART_u8_DOR_BIT			3
#define UART_u8_PE_BIT			2
#define UART_u8_U2X_BIT			1
#define UART_u8_MPCM_BIT		0


#define UART_u8_UCSRB_REG		*((volatile u8*) 0x2A)

#define UART_u8_RXCIE_BIT		7
#define UART_u8_TXCIE_BIT		6
#define UART_u8_UDRIE_BIT		5
#define UART_u8_RXEN_BIT		4
#define UART_u8_TXEN_BIT		3
#define UART_u8_UCSZ2_BIT		2
#define UART_u8_RXB8_BIT		1
#define UART_u8_TXB8_BIT		0

#define UART_u8_UCSRC_UBRRH_REG	*((volatile u8*) 0x40)

#define UART_u8_URSEL_BIT		7
#define UART_u8_UMSEL_BIT		6
#define UART_u8_UPM1_BIT		5
#define UART_u8_UPM0_BIT		4
#define UART_u8_USBS_BIT		3
#define UART_u8_UCSZ1_BIT		2
#define UART_u8_UCSZ0_BIT		1
#define UART_u8_UCPOL_BIT		0

#define UART_u8_UBRRH_MASK		0b01110000
#define UART_u8_PARITY_MASK		0b11001111
#define UART_u8_WORD_SIZE_MASK	0b11111001


#define UART_u8_UBRRL_REG		*((volatile u8*) 0x29)

#define UART_u8_UDR_REG			*((volatile u8*) 0x2C)

#endif /* MCAL_UART_UART_PRIVATE_H_ */
