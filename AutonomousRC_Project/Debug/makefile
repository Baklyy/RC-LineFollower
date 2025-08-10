################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include library/MCAL/WD/subdir.mk
-include library/MCAL/UART/subdir.mk
-include library/MCAL/TWI/subdir.mk
-include library/MCAL/TIM/subdir.mk
-include library/MCAL/SPI/subdir.mk
-include library/MCAL/PWR/subdir.mk
-include library/MCAL/GPI/subdir.mk
-include library/MCAL/EXTI/subdir.mk
-include library/MCAL/DIO/subdir.mk
-include library/MCAL/ADC/subdir.mk
-include library/LIB/subdir.mk
-include library/HAL/USS/subdir.mk
-include library/HAL/StepperMotor/subdir.mk
-include library/HAL/SSD/subdir.mk
-include library/HAL/SERVO/subdir.mk
-include library/HAL/LCD/subdir.mk
-include library/HAL/KPD/subdir.mk
-include library/HAL/IR/subdir.mk
-include library/HAL/GamePad/subdir.mk
-include library/HAL/EEPROM/subdir.mk
-include library/HAL/DSC/subdir.mk
-include library/APP/RC_SYSTEM/subdir.mk
-include library/APP/MAN/subdir.mk
-include library/APP/CRTOS/subdir.mk
-include library/APP/AUTO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
AutonomousRC_Project.lss \

FLASH_IMAGE += \
AutonomousRC_Project.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: AutonomousRC_Project.elf secondary-outputs

# Tool invocations
AutonomousRC_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AutonomousRC_Project.map -mmcu=atmega32 -o "AutonomousRC_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AutonomousRC_Project.lss: AutonomousRC_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AutonomousRC_Project.elf  >"AutonomousRC_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

AutonomousRC_Project.hex: AutonomousRC_Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AutonomousRC_Project.elf  "AutonomousRC_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AutonomousRC_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AutonomousRC_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AutonomousRC_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
