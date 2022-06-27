################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32_F103C6_Drivers/Seven_Segment/Seven_segment.c 

OBJS += \
./STM32_F103C6_Drivers/Seven_Segment/Seven_segment.o 

C_DEPS += \
./STM32_F103C6_Drivers/Seven_Segment/Seven_segment.d 


# Each subdirectory must supply rules for building sources it contributes
STM32_F103C6_Drivers/Seven_Segment/Seven_segment.o: ../STM32_F103C6_Drivers/Seven_Segment/Seven_segment.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"E:/Courses/Embedded_Systems_Course/Unit7/Lesson3_Section/Drivers/STM32_F103C6_Drivers/Seven_Segment" -I"E:/Courses/Embedded_Systems_Course/Unit7/Lesson3_Section/Drivers/STM32_F103C6_Drivers/Keypad_Driver" -I"E:/Courses/Embedded_Systems_Course/Unit7/Lesson3_Section/Drivers/STM32_F103C6_Drivers/LCD_Driver" -I"E:/Courses/Embedded_Systems_Course/Unit7/Lesson3_Section/Drivers/STM32_F103C6_Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32_F103C6_Drivers/Seven_Segment/Seven_segment.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

