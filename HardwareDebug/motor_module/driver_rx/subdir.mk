################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../motor_module/driver_rx/r_motor_driver.c 

COMPILER_OBJS += \
motor_module/driver_rx/r_motor_driver.obj 

C_DEPS += \
motor_module/driver_rx/r_motor_driver.d 

# Each subdirectory must supply rules for building sources it contributes
motor_module/driver_rx/%.obj: ../motor_module/driver_rx/%.c 
	@echo 'Scanning and building file: $<'
	@echo motor_module\driver_rx\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\driver_rx\cDepSubCommand.tmp"
	ccrx -subcommand="motor_module\driver_rx\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo motor_module\driver_rx\cSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\driver_rx\cSubCommand.tmp"
	ccrx -subcommand="motor_module\driver_rx\cSubCommand.tmp" "$<"


