################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../app/board_ui/r_app_board_ui.c \
../app/board_ui/r_app_board_ui_ctrl_rx26t_mcilv1.c 

COMPILER_OBJS += \
app/board_ui/r_app_board_ui.obj \
app/board_ui/r_app_board_ui_ctrl_rx26t_mcilv1.obj 

C_DEPS += \
app/board_ui/r_app_board_ui.d \
app/board_ui/r_app_board_ui_ctrl_rx26t_mcilv1.d 

# Each subdirectory must supply rules for building sources it contributes
app/board_ui/%.obj: ../app/board_ui/%.c 
	@echo 'Scanning and building file: $<'
	@echo app\board_ui\cDepSubCommand.tmp=
	@sed -e "s/^/ /" "app\board_ui\cDepSubCommand.tmp"
	ccrx -subcommand="app\board_ui\cDepSubCommand.tmp" -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.d=%.obj)" -MT="$(@:%.obj=%.d)" "$<"
	@echo app\board_ui\cSubCommand.tmp=
	@sed -e "s/^/ /" "app\board_ui\cSubCommand.tmp"
	ccrx -subcommand="app\board_ui\cSubCommand.tmp" "$<"


