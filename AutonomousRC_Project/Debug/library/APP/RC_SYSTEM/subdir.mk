################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/ITI\ -\ Embedded\ Systems/myEmbeddedFiles/library/APP/RC_SYSTEM/RC_SYSTEM_program.c 

OBJS += \
./library/APP/RC_SYSTEM/RC_SYSTEM_program.o 

C_DEPS += \
./library/APP/RC_SYSTEM/RC_SYSTEM_program.d 


# Each subdirectory must supply rules for building sources it contributes
library/APP/RC_SYSTEM/RC_SYSTEM_program.o: E:/ITI\ -\ Embedded\ Systems/myEmbeddedFiles/library/APP/RC_SYSTEM/RC_SYSTEM_program.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\ITI - Embedded Systems\myEmbeddedFiles\library" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


