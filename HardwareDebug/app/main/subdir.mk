################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../app/main/r_app_main.c 

COMPILER_OBJS += \
app/main/r_app_main.obj 

C_DEPS += \
app/main/r_app_main.d 

# Each subdirectory must supply rules for building sources it contributes
app/main/%.obj: ../app/main/%.c 
	@echo 'Scanning and building file: $<'
	@echo app\main\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "app\main\cDepSubCommand.tmp"
	ccrx -subcommand="app\main\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo app\main\cSubCommand.tmp=
	@sed -e "s/^/ /" "app\main\cSubCommand.tmp"
	ccrx -subcommand="app\main\cSubCommand.tmp" "$<"


