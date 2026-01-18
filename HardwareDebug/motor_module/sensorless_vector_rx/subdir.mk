################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../motor_module/sensorless_vector_rx/r_motor_sensorless_vector_action.c \
../motor_module/sensorless_vector_rx/r_motor_sensorless_vector_api.c \
../motor_module/sensorless_vector_rx/r_motor_sensorless_vector_manager.c \
../motor_module/sensorless_vector_rx/r_motor_sensorless_vector_protection.c \
../motor_module/sensorless_vector_rx/r_motor_sensorless_vector_statemachine.c 

COMPILER_OBJS += \
motor_module/sensorless_vector_rx/r_motor_sensorless_vector_action.obj \
motor_module/sensorless_vector_rx/r_motor_sensorless_vector_api.obj \
motor_module/sensorless_vector_rx/r_motor_sensorless_vector_manager.obj \
motor_module/sensorless_vector_rx/r_motor_sensorless_vector_protection.obj \
motor_module/sensorless_vector_rx/r_motor_sensorless_vector_statemachine.obj 

C_DEPS += \
motor_module/sensorless_vector_rx/r_motor_sensorless_vector_action.d \
motor_module/sensorless_vector_rx/r_motor_sensorless_vector_api.d \
motor_module/sensorless_vector_rx/r_motor_sensorless_vector_manager.d \
motor_module/sensorless_vector_rx/r_motor_sensorless_vector_protection.d \
motor_module/sensorless_vector_rx/r_motor_sensorless_vector_statemachine.d 

# Each subdirectory must supply rules for building sources it contributes
motor_module/sensorless_vector_rx/%.obj: ../motor_module/sensorless_vector_rx/%.c 
	@echo 'Scanning and building file: $<'
	@echo motor_module\sensorless_vector_rx\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\sensorless_vector_rx\cDepSubCommand.tmp"
	ccrx -subcommand="motor_module\sensorless_vector_rx\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo motor_module\sensorless_vector_rx\cSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\sensorless_vector_rx\cSubCommand.tmp"
	ccrx -subcommand="motor_module\sensorless_vector_rx\cSubCommand.tmp" "$<"


