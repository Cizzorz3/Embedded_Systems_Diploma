#Copyrights : Mohamed Adel
CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS= -I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)


all: learn_in_depth.bin
	@echo "Build is done"

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@
app.o: app.c 
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@ 

uart.o: uart.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c  $< -o $@ 

learn_in_depth.elf: $(OBJ) startup.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) startup.o -o $@ -Map=Map_file.map

learn_in_depth.bin: learn_in_depth.elf
	$(CC)objcopy.exe -O binary $< $@ 

clean_all:
	rm *.o *.elf *.bin
	echo "Succesfuly cleaned"
