################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/STM32_F103_C6_EXTI.c \
../STM32_F103C6_Drivers/STM32_F103_C6_GPIO.c \
../STM32_F103C6_Drivers/STM32_F103_C6_RCC.c \
../STM32_F103C6_Drivers/STM32_F103_C6_SPI.c \
../STM32_F103C6_Drivers/STM32_F103_C6_USART.c 

OBJS += \
./STM32_F103C6_Drivers/STM32_F103_C6_EXTI.o \
./STM32_F103C6_Drivers/STM32_F103_C6_GPIO.o \
./STM32_F103C6_Drivers/STM32_F103_C6_RCC.o \
./STM32_F103C6_Drivers/STM32_F103_C6_SPI.o \
./STM32_F103C6_Drivers/STM32_F103_C6_USART.o 

C_DEPS += \
./STM32_F103C6_Drivers/STM32_F103_C6_EXTI.d \
./STM32_F103C6_Drivers/STM32_F103_C6_GPIO.d \
./STM32_F103C6_Drivers/STM32_F103_C6_RCC.d \
./STM32_F103C6_Drivers/STM32_F103_C6_SPI.d \
./STM32_F103C6_Drivers/STM32_F103_C6_USART.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/STM32_F103_C6_EXTI.o: ../STM32_F103C6_Drivers/STM32_F103_C6_EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/HAL/Inc" -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/STM32_F103C6_Drivers/inc" -I../Inc -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/STM32_F103_C6_EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_F103C6_Drivers/STM32_F103_C6_GPIO.o: ../STM32_F103C6_Drivers/STM32_F103_C6_GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/HAL/Inc" -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/STM32_F103C6_Drivers/inc" -I../Inc -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/STM32_F103_C6_GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_F103C6_Drivers/STM32_F103_C6_RCC.o: ../STM32_F103C6_Drivers/STM32_F103_C6_RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/HAL/Inc" -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/STM32_F103C6_Drivers/inc" -I../Inc -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/STM32_F103_C6_RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_F103C6_Drivers/STM32_F103_C6_SPI.o: ../STM32_F103C6_Drivers/STM32_F103_C6_SPI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/HAL/Inc" -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/STM32_F103C6_Drivers/inc" -I../Inc -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/STM32_F103_C6_SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32_F103C6_Drivers/STM32_F103_C6_USART.o: ../STM32_F103C6_Drivers/STM32_F103_C6_USART.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/HAL/Inc" -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/STM32_F103C6_Drivers/inc" -I../Inc -I"E:/Courses/Embedded_Systems_Course/Unit8/Lesson5/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/STM32_F103_C6_USART.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

