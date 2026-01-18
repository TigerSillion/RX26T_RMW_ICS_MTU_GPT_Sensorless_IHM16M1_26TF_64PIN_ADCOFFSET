################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_MTU3_MTU4/Config_MTU3_MTU4.c \
../src/smc_gen/Config_MTU3_MTU4/Config_MTU3_MTU4_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_MTU3_MTU4/Config_MTU3_MTU4.obj \
src/smc_gen/Config_MTU3_MTU4/Config_MTU3_MTU4_user.obj 

C_DEPS += \
src/smc_gen/Config_MTU3_MTU4/Config_MTU3_MTU4.d \
src/smc_gen/Config_MTU3_MTU4/Config_MTU3_MTU4_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_MTU3_MTU4/%.obj: ../src/smc_gen/Config_MTU3_MTU4/%.c 
	@echo 'Scanning and building file: $<'
	@echo src\smc_gen\Config_MTU3_MTU4\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_MTU3_MTU4\cDepSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\Config_MTU3_MTU4\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo src\smc_gen\Config_MTU3_MTU4\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_MTU3_MTU4\cSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\Config_MTU3_MTU4\cSubCommand.tmp" "$<"


