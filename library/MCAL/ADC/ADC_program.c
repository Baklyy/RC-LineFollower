/*
 * ADC_program.h
 *
 *  Created on: Jul 24, 2025
 *      Author: George Essmat
 */


#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"


static void (*ADC_pu8_Interrupt_function)(void) = NULL;


void ADC_voidInit()
{
	//set the ADC port as input
	DIO_u8SetPortDirection(ADC_u8_PORT,DIO_u8_INPUT);
	DIO_u8SetPortValue(ADC_u8_PORT,DIO_u8_LOW);

	//select the ADC clock(Prescalar)
	ADC_u8_ADCSRA_REG = ((ADC_u8_ADCSRA_REG & ADC_u8_PRESCALAR_MASK) | ADC_u8_INITIAL_PRESCALAR);
	//select the ADC Reference voltage
	ADC_u8_ADMUX_REG = ((ADC_u8_ADMUX_REG & ADC_u8_REF_VOLT_MASK) | (ADC_u8_INITIAL_REF_VOLT<<6));

	//enable ADC
	SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADEN);

}

void ADC_voidSetPrescalar(u8 ADC_u8_PRESCALAR)
{
	//select the ADC clock(Prescalar)
	ADC_u8_ADCSRA_REG = ((ADC_u8_ADCSRA_REG & ADC_u8_PRESCALAR_MASK) | ADC_u8_PRESCALAR);
}

void ADC_voidSetReferenceVoltage(u8 ADC_u8_REF_VOLT)
{
	//select the ADC Reference voltage
	ADC_u8_ADMUX_REG = ((ADC_u8_ADMUX_REG & ADC_u8_REF_VOLT_MASK) | (ADC_u8_REF_VOLT<<6));
}

s16 ADC_u16StartConvWaitRead(u8 ADC_u8_ADCx)
{
	//select the initial ADC input Channel
	ADC_u8_ADMUX_REG = ((ADC_u8_ADMUX_REG & ADC_u8_MUX_MASK) | ADC_u8_ADCx);
	//start conversion
	SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC);

	//wait till the conversion is completes
	while(GET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC) != 0)
	{}


	return ADC_u16Read();
}


void ADC_voidStartConversion(u8 ADC_u8_ADCx)
{
	//check if there is an ongoing converstion
	if(GET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC) != 0)
	{
		return;
	}

	//select the initial ADC input Channel
	ADC_u8_ADMUX_REG = ((ADC_u8_ADMUX_REG & ADC_u8_MUX_MASK) | ADC_u8_ADCx);
	//start conversion
	SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADSC);
}

s16 ADC_u16Read()
{
	u8 ADC_ADCL = ADC_u8_ADCL_REG;
	u8 ADC_ADCH = ADC_u8_ADCH_REG;

	return ((((u16)ADC_ADCH)<<8)|ADC_ADCL);
}

void ADC_voidSetAutoTriggerSource(u8 ADC_u8_TRIGGER_SOURCE)
{
	//select the Auto Trigger Source
	ADC_u8_SFIOR_REG = ((ADC_u8_SFIOR_REG & ADC_u8_TRIGGER_SOURCE_MASK) | (ADC_u8_TRIGGER_SOURCE<<5));
}

void ADC_voidEnableTriggerSource()
{
	SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADATE);
}

void ADC_voidDisableTriggerSource()
{
	CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADATE);
}

void ADC_voidSetCallBack(void (*pf)(void))
{
	ADC_pu8_Interrupt_function = pf;
}

void ADC_voidEnableInterrupt()
{
	SET_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIE);
}

void ADC_voidDisableInterrupt()
{
	CLR_BIT(ADC_u8_ADCSRA_REG,ADC_u8_ADIE);
}

void __vector_16(void)	__attribute__((signal));

void __vector_16(void)
{
	if(ADC_pu8_Interrupt_function == NULL){return;}
	(*ADC_pu8_Interrupt_function)();
}
