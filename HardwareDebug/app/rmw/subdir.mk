################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../app/rmw/r_app_rmw.c \
../app/rmw/r_app_rmw_interrupt.c 

COMPILER_OBJS += \
app/rmw/r_app_rmw.obj \
app/rmw/r_app_rmw_interrupt.obj 

C_DEPS += \
app/rmw/r_app_rmw.d \
app/rmw/r_app_rmw_interrupt.d 

# Each subdirectory must supply rules for building sources it contributes
app/rmw/%.obj: ../app/rmw/%.c 
	@echo 'Scanning and building file: $<'
	@echo app\rmw\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "app\rmw\cDepSubCommand.tmp"
	ccrx -subcommand="app\rmw\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo app\rmw\cSubCommand.tmp=
	@sed -e "s/^/ /" "app\rmw\cSubCommand.tmp"
	ccrx -subcommand="app\rmw\cSubCommand.tmp" "$<"


