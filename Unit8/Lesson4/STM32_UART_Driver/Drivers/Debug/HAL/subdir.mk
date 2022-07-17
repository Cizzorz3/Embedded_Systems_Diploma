################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Keypad_Driver.c \
../HAL/LCD.c \
../HAL/Seven_segment.c 

OBJS += \
./HAL/Keypad_Driver.o \
./HAL/LCD.o \
./HAL/Seven_segment.o 

C_DEPS += \
./HAL/Keypad_Driver.d \
./HAL/LCD.d \
./HAL/Seven_segment.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Keypad_Driver.o: ../HAL/Keypad_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson4/STM32_UART_Driver/Drivers/HAL/Inc" -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson4/STM32_UART_Driver/Drivers/STM32_F103C6_Drivers/inc" -I../Inc -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson4/STM32_UART_Driver/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Keypad_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson4/STM32_UART_Driver/Drivers/HAL/Inc" -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson4/STM32_UART_Driver/Drivers/STM32_F103C6_Drivers/inc" -I../Inc -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson4/STM32_UART_Driver/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Seven_segment.o: ../HAL/Seven_segment.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson4/STM32_UART_Driver/Drivers/HAL/Inc" -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson4/STM32_UART_Driver/Drivers/STM32_F103C6_Drivers/inc" -I../Inc -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson4/STM32_UART_Driver/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Seven_segment.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

