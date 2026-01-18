################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/smc_gen/Config_S12AD2/Config_S12AD2.c \
../src/smc_gen/Config_S12AD2/Config_S12AD2_user.c 

COMPILER_OBJS += \
src/smc_gen/Config_S12AD2/Config_S12AD2.obj \
src/smc_gen/Config_S12AD2/Config_S12AD2_user.obj 

C_DEPS += \
src/smc_gen/Config_S12AD2/Config_S12AD2.d \
src/smc_gen/Config_S12AD2/Config_S12AD2_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/smc_gen/Config_S12AD2/%.obj: ../src/smc_gen/Config_S12AD2/%.c 
	@echo 'Scanning and building file: $<'
	@echo src\smc_gen\Config_S12AD2\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_S12AD2\cDepSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\Config_S12AD2\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo src\smc_gen\Config_S12AD2\cSubCommand.tmp=
	@sed -e "s/^/ /" "src\smc_gen\Config_S12AD2\cSubCommand.tmp"
	ccrx -subcommand="src\smc_gen\Config_S12AD2\cSubCommand.tmp" "$<"


