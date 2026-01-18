################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../motor_module/speed_rx/r_motor_speed.c \
../motor_module/speed_rx/r_motor_speed_api.c \
../motor_module/speed_rx/r_motor_speed_pi_gain_calc.c 

COMPILER_OBJS += \
motor_module/speed_rx/r_motor_speed.obj \
motor_module/speed_rx/r_motor_speed_api.obj \
motor_module/speed_rx/r_motor_speed_pi_gain_calc.obj 

C_DEPS += \
motor_module/speed_rx/r_motor_speed.d \
motor_module/speed_rx/r_motor_speed_api.d \
motor_module/speed_rx/r_motor_speed_pi_gain_calc.d 

# Each subdirectory must supply rules for building sources it contributes
motor_module/speed_rx/%.obj: ../motor_module/speed_rx/%.c 
	@echo 'Scanning and building file: $<'
	@echo motor_module\speed_rx\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\speed_rx\cDepSubCommand.tmp"
	ccrx -subcommand="motor_module\speed_rx\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo motor_module\speed_rx\cSubCommand.tmp=
	@sed -e "s/^/ /" "motor_module\speed_rx\cSubCommand.tmp"
	ccrx -subcommand="motor_module\speed_rx\cSubCommand.tmp" "$<"


