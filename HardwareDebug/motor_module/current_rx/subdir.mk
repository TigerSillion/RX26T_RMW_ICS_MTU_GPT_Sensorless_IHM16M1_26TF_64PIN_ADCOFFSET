################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../motor_module/current_rx/r_motor_current.c \
../motor_module/current_rx/r_motor_current_api.c \
../motor_module/current_rx/r_motor_current_modulation.c \
../motor_module/current_rx/r_motor_current_pi_gain_calc.c 

COMPILER_OBJS += \
motor_module/current_rx/r_motor_current.obj \
motor_module/current_rx/r_motor_current_api.obj \
motor_module/current_rx/r_motor_current_modulation.obj \
motor_module/current_rx/r_motor_current_pi_gain_calc.obj 

C_DEPS += \
motor_module/current_rx/r_motor_current.d \
motor_module/current_rx/r_motor_current_api.d \
motor_module/current_rx/r_motor_current_modulation.d \
motor_module/current_rx/r_motor_current_pi_gain_calc.d 

# Each subdirectory must supply rules for building sources it contributes
motor_module/current_rx/%.obj: ../motor_module/current_rx/%.c 
	@echo 'Scanning and building file: $<'
	@echo motor_module\current_rx\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\current_rx\cDepSubCommand.tmp"
	ccrx -subcommand="motor_module\current_rx\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo motor_module\current_rx\cSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\current_rx\cSubCommand.tmp"
	ccrx -subcommand="motor_module\current_rx\cSubCommand.tmp" "$<"


