################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/command_parser.c \
../Src/led.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/tim.c \
../Src/uart.c 

C_DEPS += \
./Src/command_parser.d \
./Src/led.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/tim.d \
./Src/uart.d 

OBJS += \
./Src/command_parser.o \
./Src/led.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/tim.o \
./Src/uart.o 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -DSTM32F103x6 -c -I../Inc -I"C:/Users/stasj/STM32CubeIDE/workspace_1.13.2/IoT_Coding_Test/headers_chip/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/stasj/STM32CubeIDE/workspace_1.13.2/IoT_Coding_Test/headers_chip/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/command_parser.cyclo ./Src/command_parser.d ./Src/command_parser.o ./Src/command_parser.su ./Src/led.cyclo ./Src/led.d ./Src/led.o ./Src/led.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/tim.cyclo ./Src/tim.d ./Src/tim.o ./Src/tim.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

