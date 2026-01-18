################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../motor_module/Config_MOTOR/Config_MOTOR.c \
../motor_module/Config_MOTOR/Config_MOTOR_user.c 

COMPILER_OBJS += \
motor_module/Config_MOTOR/Config_MOTOR.obj \
motor_module/Config_MOTOR/Config_MOTOR_user.obj 

C_DEPS += \
motor_module/Config_MOTOR/Config_MOTOR.d \
motor_module/Config_MOTOR/Config_MOTOR_user.d 

# Each subdirectory must supply rules for building sources it contributes
motor_module/Config_MOTOR/%.obj: ../motor_module/Config_MOTOR/%.c 
	@echo 'Scanning and building file: $<'
	@echo motor_module\Config_MOTOR\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\Config_MOTOR\cDepSubCommand.tmp"
	ccrx -subcommand="motor_module\Config_MOTOR\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo motor_module\Config_MOTOR\cSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\Config_MOTOR\cSubCommand.tmp"
	ccrx -subcommand="motor_module\Config_MOTOR\cSubCommand.tmp" "$<"


