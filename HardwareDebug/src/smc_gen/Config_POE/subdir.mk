################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_POE/Config_POE.c \
../src/smc_gen/Config_POE/Config_POE_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_POE/Config_POE.obj \
src/smc_gen/Config_POE/Config_POE_user.obj 

C_DEPS += \
src/smc_gen/Config_POE/Config_POE.d \
src/smc_gen/Config_POE/Config_POE_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_POE/%.obj: ../src/smc_gen/Config_POE/%.c 
	@echo 'Scanning and building file: $<'
	@echo src\smc_gen\Config_POE\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_POE\cDepSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\Config_POE\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo src\smc_gen\Config_POE\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_POE\cSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\Config_POE\cSubCommand.tmp" "$<"


