/*
 * TIM_program.c
 *
 *  Created on: Aug 2, 2025
 *      Author: George Essmat
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"

#include "TIM_interface.h"
#include "TIM_private.h"
#include "TIM_config.h"

//Timer0 functions

static void (*TIM0_pu8_OverFlow_Interrupt)(void) = NULL;
static void (*TIM0_pu8_CompareMatch_Interrupt)(void) = NULL;


void TIM0_voidPWMInit()
{
	//set clock(prescalar)
	TIM0_voidSetPrescaler(TIM0_u8_INITIAL_PWM_CLK);
	//set mode
	TIM0_voidSetWaveFormGenMode(TIM0_u8_INTIIAL_PWM_MODE);

	//setting the CO0 pin
	DIO_u8SetPinDirection(TIM0_u8_PORT,TIM0_u8_OC0_PIN,DIO_u8_OUTPUT);

}

void TIM0_voidInit()
{
	//set clock(prescalar)
	TIM0_voidSetPrescaler(TIM0_u8_INITIAL_CLK);
	//set mode
	TIM0_voidSetWaveFormGenMode(TIM0_u8_INITIAL_MODE);

}

void TIM0_voidSetWaveFormGenMode(u8 TIM0_u8_Mode)
{
	switch(TIM0_u8_Mode)
	{
	case TIM0_u8_NORMAL:
		CLR_BIT(TIM0_u8_TCCR0_REG,TIM0_u8_WGM00_BIT);
		CLR_BIT(TIM0_u8_TCCR0_REG,TIM0_u8_WGM01_BIT);
		break;
	case TIM0_u8_PWM_PHASE_CORRECT:
		SET_BIT(TIM0_u8_TCCR0_REG,TIM0_u8_WGM00_BIT);
		CLR_BIT(TIM0_u8_TCCR0_REG,TIM0_u8_WGM01_BIT);
		break;
	case TIM0_u8_CTC:
		CLR_BIT(TIM0_u8_TCCR0_REG,TIM0_u8_WGM00_BIT);
		SET_BIT(TIM0_u8_TCCR0_REG,TIM0_u8_WGM01_BIT);
		break;
	case TIM0_u8_FAST_PWM:
		SET_BIT(TIM0_u8_TCCR0_REG,TIM0_u8_WGM00_BIT);
		SET_BIT(TIM0_u8_TCCR0_REG,TIM0_u8_WGM01_BIT);
		break;
	default:
		break;
	}
}

void TIM0_voidSetOCR0(u8 TIM0_u8_OCR_Value)
{
	TIM0_u8_OCR0_REG = TIM0_u8_OCR_Value;
}

void TIM0_voidSetOutputCompareMode(u8 TIM0_u8_OC_Mode)
{
	TIM0_u8_TCCR0_REG = ((TIM0_u8_TCCR0_REG & TIM0_u8_COM_MASK) | (TIM0_u8_OC_Mode << 4));
}

void TIM0_voidSetPrescaler(u8 TIM0_u8_Clk_Source)
{
	TIM0_u8_TCCR0_REG = ((TIM0_u8_TCCR0_REG & TIM0_u8_CLK_PRESCALER_MASK) | TIM0_u8_Clk_Source);
}

u8 TIM0_u8GetTCNT0Val()
{
	return TIM0_u8_TCNT0_REG;
}

void TIM0_voidEnableOverFlowInterrupt()
{
	SET_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_TOIE_BIT);
}

void TIM0_voidDisableOverFlowInterrupt()
{
	CLR_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_TOIE_BIT);
}

void TIM0_voidEnableCompareMatchInterrupt()
{
	SET_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_OCIE_BIT);
}

void TIM0_voidDisableCompareMatchInterrupt()
{
	CLR_BIT(TIM0_u8_TIMSK_REG,TIM0_u8_OCIE_BIT);
}

void TIM0_voidSetOverFlowCallBack(void (*pf)(void))
{
	TIM0_pu8_OverFlow_Interrupt = pf;
}

void TIM0_voidSetCompareMatchCallBack(void (*pf)(void))
{
	TIM0_pu8_CompareMatch_Interrupt = pf;
}


void __vector_10(void) 	__attribute__((signal));
void __vector_10(void)
{
	if(TIM0_pu8_CompareMatch_Interrupt == NULL){return;}
	TIM0_pu8_CompareMatch_Interrupt();
}

void __vector_11(void)	__attribute__((signal));
void __vector_11(void)
{
	if(TIM0_pu8_OverFlow_Interrupt == NULL){return;}
	TIM0_pu8_OverFlow_Interrupt();
}
//

//Timer1 functions
static void (*TIM1_pu8_OverFlow_Interrupt)(void) = NULL;
static void (*TIM1_pu8_CompareMatchA_Interrupt)(void) = NULL;
static void (*TIM1_pu8_CompareMatchB_Interrupt)(void) = NULL;
static void (*TIM1_pu8_InputCapture_Interrupt)(void) = NULL;

void TIM1_voidInit()
{
	TIM1_voidSetPrescaler(TIM1_u8_INITIAL_CLK);

	TIM1_voidSetWaveFormGenMode(TIM1_u8_INITIAL_MODE);
}
void TIM1_voidSetPrescaler(u8 TIM1_u8_Clk_Source)
{
	TIM1_u8_TCCR1B_REG = (TIM1_u8_TCCR1B_REG & TIM1_u8_CLK_PRESCALER_MASK) | TIM1_u8_Clk_Source;
}

void TIM1_voidPWMInit()
{
	TIM1_voidSetPrescaler(TIM1_u8_INITIAL_PWM_CLK);

	TIM1_voidSetWaveFormGenMode(TIM1_u8_INITIAL_PWM_MODE);

	DIO_u8SetPinDirection(TIM1_u8_PORT,TIM1_u8_OC1A_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(TIM1_u8_PORT,TIM1_u8_OC1B_PIN,DIO_u8_OUTPUT);
}

void TIM1_voidSetOutputCompareMode(u8 TIM1x, u8 TIM1_u8_OC_Mode)
{
	switch(TIM1x)
	{
	case TIM1_u8_TIM1A:
		TIM1_u8_TCCR1A_REG = (TIM1_u8_TCCR1A_REG & TIM1_u8_COM1A_MASK) | (TIM1_u8_OC_Mode << TIM1_u8_COM1A0_BIT);
		break;
	case TIM1_u8_TIM1B:
		TIM1_u8_TCCR1A_REG = (TIM1_u8_TCCR1A_REG & TIM1_u8_COM1B_MASK) | (TIM1_u8_OC_Mode << TIM1_u8_COM1B0_BIT);
		break;
	}
}

void TIM1_voidSetWaveFormGenMode(u8 TIM1_u8_Mode)
{
	TIM1_u8_TCCR1A_REG = (TIM1_u8_TCCR1A_REG & TIM1_u8_WGM11_10_MASK) | (TIM1_u8_Mode & 0b00000011);
	TIM1_u8_TCCR1B_REG = (TIM1_u8_TCCR1B_REG & TIM1_u8_WGM13_12_MASK) | ((TIM1_u8_Mode & 0b00001100) << 1);
}



void TIM1_voidSetOCR1A(u16 TIM1_u16_OCR_VAL)
{
	TIM1_u8_OCR1AH_REG = (u8)(TIM1_u16_OCR_VAL >> 8);
	TIM1_u8_OCR1AL_REG = (u8)(TIM1_u16_OCR_VAL);
}

void TIM1_voidSetOCR1B(u16 TIM1_u16_OCR_VAL)
{
	TIM1_u8_OCR1BH_REG = (u8)(TIM1_u16_OCR_VAL >> 8);
	TIM1_u8_OCR1BL_REG = (u8)(TIM1_u16_OCR_VAL);
}

u16 TIM1_u16GetTCNT1Val()
{
	u16 TCNT1_Val;
	TCNT1_Val = (u16)TIM1_u8_TCNT1L_REG;
	TCNT1_Val |= (((u16)TIM1_u8_TCNT1H_REG) << 8);

	return TCNT1_Val;
}

void TIM1_voidSetICR1(u16 TIM1_u16_ICR_VAL)
{
	TIM1_u8_ICR1H_REG = (u8)(TIM1_u16_ICR_VAL >> 8);
	TIM1_u8_ICR1L_REG = (u8)(TIM1_u16_ICR_VAL);
}

u16 TIM1_u16GetICR1Val()
{
	u16 ICR1_Val;
	ICR1_Val = (u16)TIM1_u8_ICR1L_REG;
	ICR1_Val |= (((u16)TIM1_u8_ICR1H_REG) << 8);

	return ICR1_Val;
}

void TIM1_voidEnableInputCaptureNoiseCanceler()
{
	SET_BIT(TIM1_u8_TCCR1B_REG,TIM1_u8_ICNC1_BIT);
}

void TIM1_voidDisableInputCaptureNoiseCanceler()
{
	CLR_BIT(TIM1_u8_TCCR1B_REG,TIM1_u8_ICNC1_BIT);
}

void TIM1_voidSetInputCaptureCEdge(u8 TIM1_u8_IC_Edge_select)
{
	if(TIM1_u8_IC_Edge_select)
	{
		SET_BIT(TIM1_u8_TCCR1B_REG,TIM1_u8_ICES1_BIT);
	}
	else
	{
		CLR_BIT(TIM1_u8_TCCR1B_REG,TIM1_u8_ICES1_BIT);
	}
}

void TIM1_voidEnableInputCaptureInterrupt()
{
	SET_BIT(TIM1_u8_TIMSK_REG,TIM1_u8_TICIE1_BIT);
}

void TIM1_voidDisableInputCaptureInterrupt()
{
	CLR_BIT(TIM1_u8_TIMSK_REG,TIM1_u8_TICIE1_BIT);
}

void TIM1_voidEnableOCMatchAInterrupt()
{
	SET_BIT(TIM1_u8_TIMSK_REG,TIM1_u8_OCIE1A_BIT);
}

void TIM1_voidDisableOCMatchAInterrupt()
{
	CLR_BIT(TIM1_u8_TIMSK_REG,TIM1_u8_OCIE1A_BIT);
}

void TIM1_voidEnableOCMatchBInterrupt()
{
	SET_BIT(TIM1_u8_TIMSK_REG,TIM1_u8_OCIE1B_BIT);
}

void TIM1_voidDisableOCMatchBInterrupt()
{
	CLR_BIT(TIM1_u8_TIMSK_REG,TIM1_u8_OCIE1B_BIT);
}

void TIM1_voidEnableOverFlowInterrupt()
{
	SET_BIT(TIM1_u8_TIMSK_REG,TIM1_u8_TOIE1_BIT);
}

void TIM1_voidDisableOverFlowInterrupt()
{
	CLR_BIT(TIM1_u8_TIMSK_REG,TIM1_u8_TOIE1_BIT);
}

void TIM1_voidSetInputCaptureCallBack(void (*pf)(void))
{
	TIM1_pu8_InputCapture_Interrupt = pf;
}

void TIM1_voidSetOCMatchACallBack(void (*pf)(void))
{
	TIM1_pu8_CompareMatchA_Interrupt = pf;
}

void TIM1_voidSetOCMatchBCallBack(void (*pf)(void))
{
	TIM1_pu8_CompareMatchB_Interrupt = pf;
}

void TIM1_voidSetOverFlowCallBack(void (*pf)(void))
{
	TIM1_pu8_OverFlow_Interrupt = pf;
}

void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if(TIM1_pu8_InputCapture_Interrupt != NULL)
	{
		TIM1_pu8_InputCapture_Interrupt();
	}
}

void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	if(TIM1_pu8_CompareMatchA_Interrupt != NULL)
	{
		TIM1_pu8_CompareMatchA_Interrupt();
	}
}

void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	if(TIM1_pu8_CompareMatchB_Interrupt != NULL)
	{
		TIM1_pu8_CompareMatchB_Interrupt();
	}
}

void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	if(TIM1_pu8_OverFlow_Interrupt != NULL)
	{
		TIM1_pu8_OverFlow_Interrupt();
	}
}
//

//Timer2 functions
static void (*TIM2_pu8_OverFlow_Interrupt)(void) = NULL;
static void (*TIM2_pu8_CompareMatch_Interrupt)(void) = NULL;


void TIM2_voidPWMInit()
{
	//set clock(prescalar)
	TIM2_voidSetPrescaler(TIM2_u8_INITIAL_PWM_CLK);
	//set mode
	TIM2_voidSetWaveFormGenMode(TIM2_u8_INTIIAL_PWM_MODE);

	//setting the CO2 pin
	DIO_u8SetPinDirection(TIM2_u8_PORT,TIM2_u8_OC2_PIN,DIO_u8_OUTPUT);

}

void TIM2_voidInit()
{
	//set clock(prescalar)
	TIM0_voidSetPrescaler(TIM2_u8_INITIAL_CLK);
	//set mode
	TIM0_voidSetWaveFormGenMode(TIM2_u8_INITIAL_MODE);

}

void TIM2_voidSetWaveFormGenMode(u8 TIM2_u8_Mode)
{
	switch(TIM2_u8_Mode)
	{
	case TIM2_u8_NORMAL:
		CLR_BIT(TIM2_u8_TCCR2_REG,TIM2_u8_WGM20_BIT);
		CLR_BIT(TIM2_u8_TCCR2_REG,TIM2_u8_WGM21_BIT);
		break;
	case TIM2_u8_PWM_PHASE_CORRECT:
		SET_BIT(TIM2_u8_TCCR2_REG,TIM2_u8_WGM20_BIT);
		CLR_BIT(TIM2_u8_TCCR2_REG,TIM2_u8_WGM21_BIT);
		break;
	case TIM2_u8_CTC:
		CLR_BIT(TIM2_u8_TCCR2_REG,TIM2_u8_WGM20_BIT);
		SET_BIT(TIM2_u8_TCCR2_REG,TIM2_u8_WGM21_BIT);
		break;
	case TIM2_u8_FAST_PWM:
		SET_BIT(TIM2_u8_TCCR2_REG,TIM2_u8_WGM20_BIT);
		SET_BIT(TIM2_u8_TCCR2_REG,TIM2_u8_WGM21_BIT);
		break;
	default:
		break;
	}
}

void TIM2_voidSetOCR2(u8 TIM2_u8_OCR_Value)
{
	TIM2_u8_OCR2_REG = TIM2_u8_OCR_Value;
}

void TIM2_voidSetOutputCompareMode(u8 TIM2_u8_OC_Mode)
{
	TIM2_u8_TCCR2_REG = ((TIM2_u8_TCCR2_REG & TIM2_u8_COM_MASK) | (TIM2_u8_OC_Mode << 4));
}

void TIM2_voidSetPrescaler(u8 TIM2_u8_Clk_Source)
{
	TIM2_u8_TCCR2_REG = ((TIM2_u8_TCCR2_REG & TIM2_u8_CLK_PRESCALER_MASK) | TIM2_u8_Clk_Source);
}

u8 TIM2_u8GetTCNT2Val()
{
	return TIM2_u8_TCNT2_REG;
}

void TIM2_voidEnableOverFlowInterrupt()
{
	SET_BIT(TIM2_u8_TIMSK_REG,TIM2_u8_TOIE2_BIT);
}

void TIM2_voidDisableOverFlowInterrupt()
{
	CLR_BIT(TIM2_u8_TIMSK_REG,TIM2_u8_TOIE2_BIT);
}

void TIM2_voidEnableCompareMatchInterrupt()
{
	SET_BIT(TIM2_u8_TIMSK_REG,TIM2_u8_OCIE2_BIT);
}

void TIM2_voidDisableCompareMatchInterrupt()
{
	CLR_BIT(TIM2_u8_TIMSK_REG,TIM2_u8_OCIE2_BIT);
}

void TIM2_voidSetOverFlowCallBack(void (*pf)(void))
{
	TIM2_pu8_OverFlow_Interrupt = pf;
}

void TIM2_voidSetCompareMatchCallBack(void (*pf)(void))
{
	TIM2_pu8_CompareMatch_Interrupt = pf;
}

void __vector_4(void) 	__attribute__((signal));
void __vector_4(void)
{
	if(TIM2_pu8_CompareMatch_Interrupt == NULL){return;}
	TIM2_pu8_CompareMatch_Interrupt();
}

void __vector_5(void)	__attribute__((signal));
void __vector_5(void)
{
	if(TIM2_pu8_OverFlow_Interrupt == NULL){return;}
	TIM2_pu8_OverFlow_Interrupt();
}
//
