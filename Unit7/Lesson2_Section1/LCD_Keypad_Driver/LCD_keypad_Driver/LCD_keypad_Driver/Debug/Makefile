################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../LCD_Driver \
../Keypad_Driver


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Keypad_Driver/Keypad_Driver.c \
../LCD_Driver/LCD.c \
../main.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Keypad_Driver/Keypad_Driver.o \
LCD_Driver/LCD.o \
main.o

OBJS_AS_ARGS +=  \
Keypad_Driver/Keypad_Driver.o \
LCD_Driver/LCD.o \
main.o

C_DEPS +=  \
Keypad_Driver/Keypad_Driver.d \
LCD_Driver/LCD.d \
main.d

C_DEPS_AS_ARGS +=  \
Keypad_Driver/Keypad_Driver.d \
LCD_Driver/LCD.d \
main.d

OUTPUT_FILE_PATH +=LCD_keypad_Driver.elf

OUTPUT_FILE_PATH_AS_ARGS +=LCD_keypad_Driver.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
Keypad_Driver/Keypad_Driver.o: ../Keypad_Driver/Keypad_Driver.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)E:\Programs\Atmeel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"E:\Programs\Atmeel\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "E:\Programs\Atmeel\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

LCD_Driver/LCD.o: ../LCD_Driver/LCD.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)E:\Programs\Atmeel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"E:\Programs\Atmeel\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "E:\Programs\Atmeel\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)E:\Programs\Atmeel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"E:\Programs\Atmeel\7.0\Packs\atmel\ATmega_DFP\1.6.364\include"  -O0 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega32 -B "E:\Programs\Atmeel\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)E:\Programs\Atmeel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="LCD_keypad_Driver.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -B "E:\Programs\Atmeel\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega32"  
	@echo Finished building target: $@
	"E:\Programs\Atmeel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "LCD_keypad_Driver.elf" "LCD_keypad_Driver.hex"
	"E:\Programs\Atmeel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "LCD_keypad_Driver.elf" "LCD_keypad_Driver.eep" || exit 0
	"E:\Programs\Atmeel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "LCD_keypad_Driver.elf" > "LCD_keypad_Driver.lss"
	"E:\Programs\Atmeel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "LCD_keypad_Driver.elf" "LCD_keypad_Driver.srec"
	"E:\Programs\Atmeel\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "LCD_keypad_Driver.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "LCD_keypad_Driver.elf" "LCD_keypad_Driver.a" "LCD_keypad_Driver.hex" "LCD_keypad_Driver.lss" "LCD_keypad_Driver.eep" "LCD_keypad_Driver.map" "LCD_keypad_Driver.srec" "LCD_keypad_Driver.usersignatures"
	