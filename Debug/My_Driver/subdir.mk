################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../My_Driver/adc.c \
../My_Driver/exti.c \
../My_Driver/gpio.c \
../My_Driver/rcc.c \
../My_Driver/systick.c \
../My_Driver/uart.c 

OBJS += \
./My_Driver/adc.o \
./My_Driver/exti.o \
./My_Driver/gpio.o \
./My_Driver/rcc.o \
./My_Driver/systick.o \
./My_Driver/uart.o 

C_DEPS += \
./My_Driver/adc.d \
./My_Driver/exti.d \
./My_Driver/gpio.d \
./My_Driver/rcc.d \
./My_Driver/systick.d \
./My_Driver/uart.d 


# Each subdirectory must supply rules for building sources it contributes
My_Driver/%.o My_Driver/%.su My_Driver/%.cyclo: ../My_Driver/%.c My_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-My_Driver

clean-My_Driver:
	-$(RM) ./My_Driver/adc.cyclo ./My_Driver/adc.d ./My_Driver/adc.o ./My_Driver/adc.su ./My_Driver/exti.cyclo ./My_Driver/exti.d ./My_Driver/exti.o ./My_Driver/exti.su ./My_Driver/gpio.cyclo ./My_Driver/gpio.d ./My_Driver/gpio.o ./My_Driver/gpio.su ./My_Driver/rcc.cyclo ./My_Driver/rcc.d ./My_Driver/rcc.o ./My_Driver/rcc.su ./My_Driver/systick.cyclo ./My_Driver/systick.d ./My_Driver/systick.o ./My_Driver/systick.su ./My_Driver/uart.cyclo ./My_Driver/uart.d ./My_Driver/uart.o ./My_Driver/uart.su

.PHONY: clean-My_Driver

