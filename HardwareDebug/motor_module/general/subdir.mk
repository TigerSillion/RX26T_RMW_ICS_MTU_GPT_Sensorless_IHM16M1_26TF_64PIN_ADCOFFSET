################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../motor_module/general/r_motor_filter.c \
../motor_module/general/r_motor_pi_control.c 

COMPILER_OBJS += \
motor_module/general/r_motor_filter.obj \
motor_module/general/r_motor_pi_control.obj 

C_DEPS += \
motor_module/general/r_motor_filter.d \
motor_module/general/r_motor_pi_control.d 

# Each subdirectory must supply rules for building sources it contributes
motor_module/general/%.obj: ../motor_module/general/%.c 
	@echo 'Scanning and building file: $<'
	@echo motor_module\general\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\general\cDepSubCommand.tmp"
	ccrx -subcommand="motor_module\general\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo motor_module\general\cSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\general\cSubCommand.tmp"
	ccrx -subcommand="motor_module\general\cSubCommand.tmp" "$<"


