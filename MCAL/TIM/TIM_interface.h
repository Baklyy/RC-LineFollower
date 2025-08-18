/*
 * TIM_interface.h
 *
 *  Created on: Aug 2, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_TIM_TIM_INTERFACE_H_
#define MCAL_TIM_TIM_INTERFACE_H_

//Timer0 interface
#define TIM0_u8_PORT		DIO_u8_PORTB

#define TIM0_u8_T0_PIN		DIO_u8_PIN0
#define TIM0_u8_OC0_PIN		DIO_u8_PIN3

#define TIM0_u8_NO_CLK_SOURCE					0
#define TIM0_u8_NO_PRESCALER					1
#define TIM0_u8_PRESCALER_8						2
#define TIM0_u8_PRESCALER_64					3
#define TIM0_u8_PRESCALER_256					4
#define TIM0_u8_PRESCALER_1024					5
#define TIM0_u8_EXTERNAL_CLK_FALLING_EDGE 		6
#define TIM0_u8_EXTERNAL_CLK_RISING_EDGE		7

#define TIM0_u8_NORMAL				0
#define TIM0_u8_PWM_PHASE_CORRECT	1
#define TIM0_u8_CTC					2
#define TIM0_u8_FAST_PWM			3

#define TIM0_u8_OC0_disconnected	0
#define TIM0_u8_OC0_TOGGLE			1
#define TIM0_u8_OC0_CLEAR			2
#define TIM0_u8_OC0_SET				3

void TIM0_voidInit();

void TIM0_voidPWMInit();

void TIM0_voidSetPrescaler(u8 TIM0_u8_Clk_Source);

void TIM0_voidSetWaveFormGenMode(u8 TIM0_u8_Mode);

void TIM0_voidSetOCR0(u8 TIM0_u8_OCR_Value);

void TIM0_voidSetOutputCompareMode(u8 TIM0_u8_OC_Mode);

void TIM0_voidSetTCNT0Val(u8 TCNT0_Val);

u8 TIM0_u8GetTCNT0Val();

void TIM0_voidEnableOverFlowInterrupt();

void TIM0_voidDisableOverFlowInterrupt();

void TIM0_voidEnableCompareMatchInterrupt();

void TIM0_voidDisableCompareMatchInterrupt();

void TIM0_voidSetOverFlowCallBack(void (*pf)(void));

void TIM0_voidSetCompareMatchCallBack(void (*pf)(void));
//

//Timer1 interface
#define TIM1_u8_PORT			DIO_u8_PORTD

#define TIM1_u8_ICP1_PIN		DIO_u8_PIN6
#define TIM1_u8_OC1A_PIN		DIO_u8_PIN5
#define TIM1_u8_OC1B_PIN		DIO_u8_PIN4

#define TIM1_u8_T1_PORT			DIO_u8_PORTB
#define TIM1_u8_T1_PIN			DIO_u8_PIN1

#define TIM1_u8_TIM1A				0
#define TIM1_u8_TIM1B				1

#define TIM1_u8_OC1_disconnected	0
#define TIM1_u8_OC1_TOGGLE			1
#define TIM1_u8_OC1_CLEAR			2
#define TIM1_u8_OC1_SET				3

#define TIM1_u8_MODE_NORMAL								0
#define TIM1_u8_MODE_PWM_PHASE_CORRECT_8_BIT			1
#define TIM1_u8_MODE_PWM_PHASE_CORRECT_9_BIT			2
#define TIM1_u8_MODE_PWM_PHASE_CORRECT_10_BIT			3
#define TIM1_u8_MODE_CTC_OCR1A							4
#define TIM1_u8_MODE_PWM_FAST_8_BIT						5
#define TIM1_u8_MODE_PWM_FAST_9_BIT 					6
#define TIM1_u8_MODE_PWM_FAST_10_BIT					7
#define TIM1_u8_MODE_PWM_PHASE_FREQUENCY_CORRECT_ICR1	8
#define TIM1_u8_MODE_PWM_PHASE_FREQUENCY_CORRECT_OCR1A	9
#define TIM1_u8_MODE_PWM_PHASE_CORRECT_ICR1				10
#define TIM1_u8_MODE_PWM_PHASE_CORRECT_OCR1A			11
#define TIM1_u8_MODE_CTC_ICR1							12
#define TIM1_u8_MODE_PWM_FAST_ICR1						14
#define TIM1_u8_MODE_PWM_FAST_OCR1A						15

#define TIM1_u8_NO_CLK_SOURCE					0
#define TIM1_u8_NO_PRESCALER					1
#define TIM1_u8_PRESCALER_8						2
#define TIM1_u8_PRESCALER_64					3
#define TIM1_u8_PRESCALER_256					4
#define TIM1_u8_PRESCALER_1024					5
#define TIM1_u8_EXTERNAL_CLK_FALLING_EDGE 		6
#define TIM1_u8_EXTERNAL_CLK_RISING_EDGE		7

#define TIM1_u8_INPUT_CAPTURE_FALLING_EDGE		0
#define TIM1_u8_INPUT_CAPTURE_RISING_EDGE		1

void TIM1_voidInit();

void TIM1_voidPWMInit();

void TIM1_voidSetOutputCompareMode(u8 TIM1x, u8 TIM1_u8_OC_Mode);

void TIM1_voidSetWaveFormGenMode(u8 TIM1_u8_Mode);

void TIM1_voidSetPrescaler(u8 TIM1_u8_Clk_Source);

void TIM1_voidSetOCR1A(u16 TIM1_u16_OCR_VAL);

void TIM1_voidSetOCR1B(u16 TIM1_u16_OCR_VAL);

void TIM1_voidSetTCNT1Val(u16 TCNT1_Val);

u16 TIM1_u16GetTCNT1Val();

void TIM1_voidSetICR1(u16 TIM1_u16_ICR_VAL);

u16 TIM1_u16GetICR1Val();

void TIM1_voidEnableInputCaptureNoiseCanceler();

void TIM1_voidDisableInputCaptureNoiseCanceler();

void TIM1_voidSetInputCaptureCEdge(u8 TIM1_u8_IC_Edge_select);

void TIM1_voidEnableInputCaptureInterrupt();

void TIM1_voidDisableInputCaptureInterrupt();

void TIM1_voidEnableOCMatchAInterrupt();

void TIM1_voidDisableOCMatchAInterrupt();

void TIM1_voidEnableOCMatchBInterrupt();

void TIM1_voidDisableOCMatchBInterrupt();

void TIM1_voidEnableOverFlowInterrupt();

void TIM1_voidDisableOverFlowInterrupt();

void TIM1_voidSetInputCaptureCallBack(void (*pf)(void));

void TIM1_voidSetOCMatchACallBack(void (*pf)(void));

void TIM1_voidSetOCMatchBCallBack(void (*pf)(void));

void TIM1_voidSetOverFlowCallBack(void (*pf)(void));

//

//Timer2 interface
#define TIM2_u8_PORT	DIO_u8_PORTD

#define TIM2_u8_OC2_PIN		DIO_u8_PIN7


#define TIM2_u8_NO_CLK_SOURCE					0
#define TIM2_u8_NO_PRESCALER					1
#define TIM2_u8_PRESCALER_8						2
#define TIM2_u8_PRESCALER_32					3
#define TIM2_u8_PRESCALER_64					4
#define TIM2_u8_PRESCALER_128					5
#define TIM2_u8_PRESCALER_256					6
#define TIM2_u8_PRESCALER_1024					7


#define TIM2_u8_NORMAL				0
#define TIM2_u8_PWM_PHASE_CORRECT	1
#define TIM2_u8_CTC					2
#define TIM2_u8_FAST_PWM			3

#define TIM2_u8_OC2_disconnected	0
#define TIM2_u8_OC2_TOGGLE			1
#define TIM2_u8_OC2_CLEAR			2
#define TIM2_u8_OC2_SET				3

void TIM2_voidInit();

void TIM2_voidPWMInit();

void TIM2_voidSetPrescaler(u8 TIM2_u8_Clk_Source);

void TIM2_voidSetWaveFormGenMode(u8 TIM2_u8_Mode);

void TIM2_voidSetOCR2(u8 TIM2_u8_OCR_Value);

void TIM2_voidSetOutputCompareMode(u8 TIM2_u8_OC_Mode);

void TIM2_voidSetTCNT2Val(u8 TCNT2_Val);

u8 TIM2_u8GetTCNT2Val();

void TIM2_voidEnableOverFlowInterrupt();

void TIM2_voidDisableOverFlowInterrupt();

void TIM2_voidEnableCompareMatchInterrupt();

void TIM2_voidDisableCompareMatchInterrupt();

void TIM2_voidSetOverFlowCallBack(void (*pf)(void));

void TIM2_voidSetCompareMatchCallBack(void (*pf)(void));

//

#endif /* MCAL_TIM_TIM_INTERFACE_H_ */
