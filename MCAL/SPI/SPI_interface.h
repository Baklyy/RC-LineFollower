/*
 * SPI_interface.h
 *
 *  Created on: Jul 31, 2025
 *      Author: Mohamed Atif
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

typedef enum
{
	SLAVE=0,
	MASTER
}mode_t;

void SPI_VOID_INIT(mode_t COPY_MODE);
u8 SPI_TransRecieve(u8 COPY_U8_DATA);
u8 SPI_u8IsTransferComplete(void);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
