/*
 * ADC_interface.h
 *
 *  Created on: Jul 24, 2025
 *      Author: George Essmat
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

#define ADC_f32_AVCC_STEP	5.0/1024.0

#define ADC_u8_ADC0 							0
#define ADC_u8_ADC1 							1
#define ADC_u8_ADC2 							2
#define ADC_u8_ADC3 							3
#define ADC_u8_ADC4 							4
#define ADC_u8_ADC5 							5
#define ADC_u8_ADC6 							6
#define ADC_u8_ADC7 							7
#define ADC_u8_DIFFERENTIAL_10xGAIN_ADC0_ADC0 	8
#define ADC_u8_DIFFERENTIAL_10xGAIN_ADC1_ADC0	9
#define ADC_u8_DIFFERENTIAL_200xGAIN_ADC0_ADC0	10
#define ADC_u8_DIFFERENTIAL_200xGAIN_ADC1_ADC0	11
#define ADC_u8_DIFFERENTIAL_10xGAIN_ADC2_ADC2	12
#define ADC_u8_DIFFERENTIAL_10xGAIN_ADC3_ADC2	13
#define ADC_u8_DIFFERENTIAL_200xGAIN_ADC2_ADC2	14
#define ADC_u8_DIFFERENTIAL_200xGAIN_ADC3_ADC2	15
#define ADC_u8_DIFFERENTIAL_ADC0_ADC1			16
#define ADC_u8_DIFFERENTIAL_ADC1_ADC1			17
#define ADC_u8_DIFFERENTIAL_ADC2_ADC1			18
#define ADC_u8_DIFFERENTIAL_ADC3_ADC1			19
#define ADC_u8_DIFFERENTIAL_ADC4_ADC1			20
#define ADC_u8_DIFFERENTIAL_ADC5_ADC1			21
#define ADC_u8_DIFFERENTIAL_ADC6_ADC1			22
#define ADC_u8_DIFFERENTIAL_ADC7_ADC1			23
#define ADC_u8_DIFFERENTIAL_ADC0_ADC2			24
#define ADC_u8_DIFFERENTIAL_ADC1_ADC2			25
#define ADC_u8_DIFFERENTIAL_ADC2_ADC2			26
#define ADC_u8_DIFFERENTIAL_ADC3_ADC2			27
#define ADC_u8_DIFFERENTIAL_ADC4_ADC2			28
#define ADC_u8_DIFFERENTIAL_ADC5_ADC2			29



#define ADC_u8_EXTERNAL_REF 	0
#define ADC_u8_AVCC_REF 		1
#define ADC_u8_INTERNAL_REF 	3

#define ADC_u8_DIVISION_FACTOR2		0
#define ADC_u8_DIVISION_FACTOR4		2
#define ADC_u8_DIVISION_FACTOR8		3
#define ADC_u8_DIVISION_FACTOR16	4
#define ADC_u8_DIVISION_FACTOR32	5
#define ADC_u8_DIVISION_FACTOR64	6
#define ADC_u8_DIVISION_FACTOR128	7

#define ADC_u8_TRIGGER_SOURCE_FREE_RUNNING				0
#define ADC_u8_TRIGGER_SOURCE_ANALOG_COMPARATOR 		1
#define ADC_u8_TRIGGER_SOURCE_EXTERNAL_INTERRUPT_REQ0 	2
#define ADC_u8_TRIGGER_SOURCE_TIMER0_COMPARE_MATCH 		3
#define ADC_u8_TRIGGER_SOURCE_TIMER0_OVERFLOW 			4
#define ADC_u8_TRIGGER_SOURCE_TIMER1_COMPARE_MACTCH 	5
#define ADC_u8_TRIGGER_SOURCE_TIMER1_OVERFLOW 			6
#define ADC_u8_TRIGGER_SOURCE_TIMER1_CAPTURE_EVENT 		7


void ADC_voidInit();

s16 ADC_u16StartConvWaitRead(u8 ADC_u8_ADCx);

void ADC_voidStartConversion(u8 ADC_u8_ADCx);

s16 ADC_u16Read();

void ADC_voidSetPrescalar(u8 ADC_u8_PRESCALAR);

void ADC_voidSetReferenceVoltage(u8 ADC_u8_REF_VOLT);

void ADC_voidSetAutoTriggerSource(u8 ADC_u8_TRIGGER_SOURCE);

void ADC_voidEnableTriggerSource();

void ADC_voidDisableTriggerSource();

void ADC_voidEnableInterrupt();

void ADC_voidDisableInterrupt();

void ADC_voidSetCallBack(void (*pf)(void));

#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
