################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../My_Application/adc.c \
../My_Application/cli_command.c \
../My_Application/cli_command_table.c \
../My_Application/cli_types.c \
../My_Application/exti.c \
../My_Application/gpio.c \
../My_Application/pwm.c \
../My_Application/rcc.c \
../My_Application/systick.c \
../My_Application/tempperature_cli.c \
../My_Application/uart.c 

OBJS += \
./My_Application/adc.o \
./My_Application/cli_command.o \
./My_Application/cli_command_table.o \
./My_Application/cli_types.o \
./My_Application/exti.o \
./My_Application/gpio.o \
./My_Application/pwm.o \
./My_Application/rcc.o \
./My_Application/systick.o \
./My_Application/tempperature_cli.o \
./My_Application/uart.o 

C_DEPS += \
./My_Application/adc.d \
./My_Application/cli_command.d \
./My_Application/cli_command_table.d \
./My_Application/cli_types.d \
./My_Application/exti.d \
./My_Application/gpio.d \
./My_Application/pwm.d \
./My_Application/rcc.d \
./My_Application/systick.d \
./My_Application/tempperature_cli.d \
./My_Application/uart.d 


# Each subdirectory must supply rules for building sources it contributes
My_Application/%.o My_Application/%.su My_Application/%.cyclo: ../My_Application/%.c My_Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"E:/STM32/STM32F411/STM32F411_adv/My_Application" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-My_Application

clean-My_Application:
	-$(RM) ./My_Application/adc.cyclo ./My_Application/adc.d ./My_Application/adc.o ./My_Application/adc.su ./My_Application/cli_command.cyclo ./My_Application/cli_command.d ./My_Application/cli_command.o ./My_Application/cli_command.su ./My_Application/cli_command_table.cyclo ./My_Application/cli_command_table.d ./My_Application/cli_command_table.o ./My_Application/cli_command_table.su ./My_Application/cli_types.cyclo ./My_Application/cli_types.d ./My_Application/cli_types.o ./My_Application/cli_types.su ./My_Application/exti.cyclo ./My_Application/exti.d ./My_Application/exti.o ./My_Application/exti.su ./My_Application/gpio.cyclo ./My_Application/gpio.d ./My_Application/gpio.o ./My_Application/gpio.su ./My_Application/pwm.cyclo ./My_Application/pwm.d ./My_Application/pwm.o ./My_Application/pwm.su ./My_Application/rcc.cyclo ./My_Application/rcc.d ./My_Application/rcc.o ./My_Application/rcc.su ./My_Application/systick.cyclo ./My_Application/systick.d ./My_Application/systick.o ./My_Application/systick.su ./My_Application/tempperature_cli.cyclo ./My_Application/tempperature_cli.d ./My_Application/tempperature_cli.o ./My_Application/tempperature_cli.su ./My_Application/uart.cyclo ./My_Application/uart.d ./My_Application/uart.o ./My_Application/uart.su

.PHONY: clean-My_Application

