################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/led.c \
../Src/main.c \
../Src/menu.c \
../Src/pwm.c \
../Src/system_stm32f4xx.c \
../Src/uart.c 

OBJS += \
./Src/led.o \
./Src/main.o \
./Src/menu.o \
./Src/pwm.o \
./Src/system_stm32f4xx.o \
./Src/uart.o 

C_DEPS += \
./Src/led.d \
./Src/main.d \
./Src/menu.d \
./Src/pwm.d \
./Src/system_stm32f4xx.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/led.cyclo ./Src/led.d ./Src/led.o ./Src/led.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/menu.cyclo ./Src/menu.d ./Src/menu.o ./Src/menu.su ./Src/pwm.cyclo ./Src/pwm.d ./Src/pwm.o ./Src/pwm.su ./Src/system_stm32f4xx.cyclo ./Src/system_stm32f4xx.d ./Src/system_stm32f4xx.o ./Src/system_stm32f4xx.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

