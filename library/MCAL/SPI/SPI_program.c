/*
 * SPI_program.c
 *
 *  Created on: Jul 31, 2025
 *      Author: Mohamed Atif
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/delay.h"
#include "MCAL/DIO/DIO_interface.h"


#include "SPI_config.h"
#include "SPI_private.h"
#include "SPI_interface.h"


void SPI_VOID_INIT(mode_t COPY_MODE)
{
	// Master or slave selection
		if (COPY_MODE == MASTER)
		{
			SET_BIT(SPCR,SPCR_MSTR);
			DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_OUTPUT);
			DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_OUTPUT);
			DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN7,DIO_u8_OUTPUT);
			DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_INPUT);

//			DIO_PIN_INIT(DIO_PORTB,4,DIO_PIN_MODE_OUTPUT);
//			DIO_PIN_INIT(DIO_PORTB,5,DIO_PIN_MODE_OUTPUT);
//			DIO_PIN_INIT(DIO_PORTB,7,DIO_PIN_MODE_OUTPUT);
//			DIO_PIN_INIT(DIO_PORTB,6,DIO_PIN_MODE_INPUT_PU);
		}
		else
		{
			DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN5,DIO_u8_INPUT);
			DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN6,DIO_u8_OUTPUT);
			DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN7,DIO_u8_INPUT);
			DIO_u8SetPinDirection(DIO_u8_PORTB,DIO_u8_PIN4,DIO_u8_INPUT);

//			DIO_PIN_INIT(DIO_PORTB,5,DIO_PIN_MODE_INPUT_PU);
//			DIO_PIN_INIT(DIO_PORTB,6,DIO_PIN_MODE_OUTPUT);
//			DIO_PIN_INIT(DIO_PORTB,7,DIO_PIN_MODE_INPUT_PU);
//			DIO_PIN_INIT(DIO_PORTB,4,DIO_PIN_MODE_INPUT_PU);
			CLR_BIT(SPCR,SPCR_MSTR);

		}
	//ENABLE SPLI
	SET_BIT(SPCR,SPCR_SPE);
	//DATA ORDER (LSB Transmitted first)
	SET_BIT(SPCR,SPCR_DORD);


	// MODE 1

	CLR_BIT(SPCR,SPCR_CPOL);
	SET_BIT(SPCR,SPCR_CPHA);

	// SET THE PRESCALLER (f/4)
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);




}
u8 SPI_TransRecieve(u8 COPY_U8_DATA)
{
	SPDR = COPY_U8_DATA;
	while(!GET_BIT(SPSR,7));
	return SPDR;
}
u8 SPI_u8IsTransferComplete(void)
{
    return (SPSR & (1 << SPSR_SPIF)) ? 1 : 0;
}
