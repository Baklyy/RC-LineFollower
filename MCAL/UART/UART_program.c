/*
 * UART_program.c
 *
 *  Created on: Jul 30, 2025
 *      Author: George Essmat
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "LIB/delay.h"

#include "MCAL/DIO/DIO_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

#include "avr/io.h"

//8-bit word size
//no parity bit
//1-bit stop bit
//51 baud rate


void (*RecieveCompleteFuncPointer)(void) = NULL;
void (*TransmissionCompleteFuncPointer)(void) = NULL;
void (*DataRegisterEmptyFuncPointer)(void) = NULL;

void UART_voidInit()
{
	UART_voidTransmitterEnable();
	UART_voidReceiverEnable();

	UART_voidSetBaudRate(51);//for 9600 Baud rate

	UART_voidSetWordSize(UART_u8_INITIAL_WORD_SIZE);

	//these functions doesn't work for some reason
	//UART_voidSetParityMode(UART_u8_INITIAL_PARITY);
	//UART_voidSetStopBits(UART_u8_INITIAL_STOP_BITS);

}

void UART_voidMode(u8 UART_u8_Mode)
{
	if(UART_u8_Mode)
	{
		UART_u8_UCSRC_UBRRH_REG = ( UART_u8_UCSRC_UBRRH_REG | (1<<UART_u8_URSEL_BIT)) | (1<<UART_u8_UMSEL_BIT);
	}
	else
	{
		UART_u8_UCSRC_UBRRH_REG = ( UART_u8_UCSRC_UBRRH_REG | (1<<UART_u8_URSEL_BIT)) & (~(1<<UART_u8_UMSEL_BIT));
	}
}

void UART_voidSetParityMode(u8 UART_u8_Parity_Mode)
{
	UART_u8_UCSRC_UBRRH_REG = (((UART_u8_UCSRC_UBRRH_REG| (1<<UART_u8_URSEL_BIT)) & UART_u8_PARITY_MASK) | (UART_u8_Parity_Mode<<4));
}

void UART_voidSetStopBits(u8 UART_u8_Num_Of_Stop_Bits)
{
	if(UART_u8_Num_Of_Stop_Bits)
	{
		UART_u8_UCSRC_UBRRH_REG = ( UART_u8_UCSRC_UBRRH_REG | (1<<UART_u8_URSEL_BIT)) | (1<<UART_u8_USBS_BIT);
	}
	else
	{
		UART_u8_UCSRC_UBRRH_REG = ( UART_u8_UCSRC_UBRRH_REG | (1<<UART_u8_URSEL_BIT)) & (~(1<<UART_u8_USBS_BIT));
	}

}

void UART_voidSetWordSize(u8 UART_u8_Word_Size)
{
	switch(UART_u8_Word_Size)
	{
	case UART_u8_FIVE_BIT_WORD:
	case UART_u8_SIX_BIT_WORD:
	case UART_u8_SEVEN_BIT_WORD:
	case UART_u8_EIGHT_BIT_WORD:
		UART_u8_UCSRC_UBRRH_REG = (((UART_u8_UCSRC_UBRRH_REG | (1<<UART_u8_URSEL_BIT)) & UART_u8_WORD_SIZE_MASK) | (UART_u8_Word_Size <<1));
		break;
	case UART_u8_NINE_BIT_WORD:
		UART_u8_UCSRC_UBRRH_REG = (((UART_u8_UCSRC_UBRRH_REG | (1<<UART_u8_URSEL_BIT)) & UART_u8_WORD_SIZE_MASK) | (0b00000110));
		SET_BIT(UART_u8_UCSRB_REG, UART_u8_UCSZ2_BIT);
		break;
	default:
		break;
	}
}

void UART_voidSetClockPolarity(u8 UART_u8_Polarity)
{
	if(UART_u8_Polarity)
	{
		UART_u8_UCSRC_UBRRH_REG = ( UART_u8_UCSRC_UBRRH_REG | (1<<UART_u8_URSEL_BIT)) | (1<<UART_u8_UCPOL_BIT);
	}
	else
	{
		UART_u8_UCSRC_UBRRH_REG = ( UART_u8_UCSRC_UBRRH_REG | (1<<UART_u8_URSEL_BIT)) & (~(1<<UART_u8_UCPOL_BIT));
	}
}

void UART_voidSetBaudRate(u16 UART_u16_Baud_Rate)
{
	UART_u8_UBRRL_REG = (u8)UART_u16_Baud_Rate;

	UART_u8_UCSRC_UBRRH_REG = ((UART_u8_UCSRC_UBRRH_REG & UART_u8_UBRRH_MASK) | ((u8)(UART_u16_Baud_Rate >> 8)));
}

void UART_voidTransmitterEnable()
{
	SET_BIT(UART_u8_UCSRB_REG, UART_u8_TXEN_BIT);
}

void UART_voidReceiverEnable()
{
	SET_BIT(UART_u8_UCSRB_REG, UART_u8_RXEN_BIT);
}

void UART_voidTransmitterDisable()
{
	CLR_BIT(UART_u8_UCSRB_REG, UART_u8_TXEN_BIT);
}

void UART_voidReceiverDisable()
{
	CLR_BIT(UART_u8_UCSRB_REG, UART_u8_RXEN_BIT);
}


void UART_voidTransmit(u8 UART_u16_Data)
{

	while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_UDRE_BIT) == 0)
	{}
	UART_u8_UDR_REG = UART_u16_Data;
	while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_TXC_BIT) == 0)
	{}
}

void UART_voidTransmitNewLine()
{
	UART_voidTransmit('\r');
	UART_voidTransmit('\n');
}

void UART_voidTransmitInteger(u32 integer)
{
	if(integer == 0)
		{
			UART_voidTransmit('0');
			return;
		}

		u8 count  = 0;
		u32 invertedInteger = 0;
		while(integer != 0)
		{
			invertedInteger = (integer%10) + invertedInteger*10;
			integer /= 10;
			count++;
		}

		while(count != 0)
		{
			UART_voidTransmit(invertedInteger%10 + 48);
			invertedInteger /=10;
			count--;
		}
}

void UART_voidTransmitFraction(u32 frac)
{
	u8 count  = 0;
	u32 invertedFrac = 0;
	while(frac != 0)
	{
		invertedFrac = (frac%10) + invertedFrac*10;
		frac /= 10;
		count++;
	}

	u8 zerosToPrint = UART_u8_MAX_FRACTION_DIGITS - count;
	while(zerosToPrint)
	{
		UART_voidTransmit('0');
		zerosToPrint--;
	}

	while(count != 0)
	{
		UART_voidTransmit(invertedFrac%10 + 48);
		invertedFrac /=10;
		count--;
	}
}

void UART_voidTransmitNumber(f32 num)
{

	if(num < 0)
	{
		num *= -1;
		UART_voidTransmit('-');
	}

	u32 intNum = (s32)num;
	f32 afterDecimalPoint = num - (f32)intNum;

	UART_voidTransmitInteger(intNum);

	if(afterDecimalPoint > UART_u8_MINMUM_FRACTION)
	{
		UART_voidTransmit('.');
		UART_voidTransmitFraction(afterDecimalPoint*UART_u8_MAX_FRACTION_DIGITS_FACTOR);
	}
}

void UART_voidTransmitStr(u8* str)
{
	while(*str != '\0')
	{
		if(*str == '\n')
		{
			UART_voidTransmitNewLine();
		}
		else
		{
			UART_voidTransmit(*str);
		}
		str++;
	}
}

u16 UART_u16Receive(u8* errorState)
{
		errorState = UART_u8_RECEIVE_CORRECT;
		u16 UART_u16_Received_Data;
		while(GET_BIT(UART_u8_UCSRA_REG,UART_u8_RXC_BIT) == 0)
		{}

		UART_u16_Received_Data = ((u16)GET_BIT(UART_u8_UCSRB_REG,UART_u8_RXB8_BIT)) << 8;
		UART_u16_Received_Data |= UART_u8_UDR_REG;

		if(GET_BIT(UART_u8_UCSRA_REG,UART_u8_DOR_BIT))
		{
			*errorState = UART_u8_DATA_OVERRUN;
		}
		else if(GET_BIT(UART_u8_UCSRA_REG,UART_u8_PE_BIT))
		{
			*errorState = UART_u8_PARITY_ERROR;
		}
		else if(GET_BIT(UART_u8_UCSRA_REG,UART_u8_FE_BIT))
		{
			*errorState = UART_u8_FRAME_ERROR;
		}

		return UART_u16_Received_Data;
}

u8 UART_u16Read()
{
	//this function is used for reading data directly from
	//the data register and should only be used in
	//the interrupt handler
//	u16 UART_u16_Received_Data;
//	UART_u16_Received_Data = ((u16)GET_BIT(UART_u8_UCSRB_REG,UART_u8_RXB8_BIT)) << 8;
//	UART_u16_Received_Data |= UART_u8_UDR_REG;
//	return UART_u16_Received_Data;
	return UART_u8_UDR_REG;
}
void UART_voidEnableReceiveInterrupt()
{
	SET_BIT(UART_u8_UCSRB_REG,UART_u8_RXCIE_BIT);
}

void UART_voidDisableReceiveInterrupt()
{
	CLR_BIT(UART_u8_UCSRB_REG,UART_u8_RXCIE_BIT);
}

void UART_voidEnableTransmissionInterrupt()
{
	SET_BIT(UART_u8_UCSRB_REG,UART_u8_TXCIE_BIT);
}

void UART_voidDisableTransmissionInterrupt()
{
	CLR_BIT(UART_u8_UCSRB_REG,UART_u8_TXCIE_BIT);
}

void UART_voidEnableDataRegisterEmptyInterrupt()
{
	SET_BIT(UART_u8_UCSRB_REG,UART_u8_UDRIE_BIT);
}

void UART_voidDisableDataRegisterEmptyInterrupt()
{
	CLR_BIT(UART_u8_UCSRB_REG,UART_u8_UDRIE_BIT);
}


void UART_voidSetReceiveCallBack(void (*pf)(void))
{
	RecieveCompleteFuncPointer = pf;
}

void UART_voidSetTransmissionCallBack(void (*pf)(void))
{
	TransmissionCompleteFuncPointer = pf;
}

void UART_voidSetDataRegisterEmptyCallBack(void (*pf)(void))
{
	DataRegisterEmptyFuncPointer = pf;
}


void __vector_13(void)	__attribute__((signal));
void __vector_13(void)
{
	if(RecieveCompleteFuncPointer != NULL)
	{
		RecieveCompleteFuncPointer();
	}
}

void __vector_15(void)	__attribute__((signal));
void __vector_15(void)
{
	if(TransmissionCompleteFuncPointer != NULL)
	{
		TransmissionCompleteFuncPointer();
	}
}

void __vector_14(void)	__attribute__((signal));
void __vector_14(void)
{
	if(DataRegisterEmptyFuncPointer != NULL)
	{
		DataRegisterEmptyFuncPointer();
	}
}
