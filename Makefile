# -*- Makefile -*-

#target: dependencies
#	action
include source.mk
CC=gcc  #declaring the compilers
CFLAGS= -g -Wall -O0 -std=c99 #declaring the flags

CPROG= main.c ADC.c capacitive_touch.c nordic_lib.c nordic_module.c  # declaring all the C files

COBJ= main.c ADC.c capacitive_touch.c nordic_lib.c nordic_module.c# Files for which object files are to be generated

HEAD= capacitive_touch.h nordic_lib.h nordic_module.h MKL25Z4.h # files for which header files are present

OBJ= main.o ADC.o capacitive_touch.o nordic_module.o nordic_lib.o#files for which object files are to be generated

INCLUDE=./HEADER #giving the header path

PREP= ADC.i capacitive_touch.i nordic_module.i nordic_lib.i main.i  #all the preprocessor files


ifeq ($(arch),bbb) # for defining the beagle bone board
CC=arm-linux-gnueabihf-gcc
else ifeq ($(arch),frdm) # for defining the freedom scale compiler
CC=arm-none-eabi-gcc
else ifeq ($(arch),host)# for taking the native compiler
CC=gcc
else 
CC=gcc #defining default compiler 
endif

#all: %

.PHONY: %.i
makefile.i: $(PREP)
	cpp -I $(INCLUDE) $^ > preprocessed/$@
%.i: %.c
	mkdir -p preprocessed
	$(CC) $(CFLAGS) -I $(INCLUDE) -E $^
	cpp -I $(INCLUDE) $^ > preprocessed/$@
.PHONY: makefiles.s
makefile.s: $(CPROG)
	mkdir -p asm-file
	$(CC) $(CFLAG) -I $(INCLUDE) $^ -S
	mv *.s asm-file

.PHONY: main.s
main.s: main.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^ 
.PHONY: ADC.s
ADC.s: ADC.c 
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: capacitive_touch.s
capacitive_touch.s: capacitive_touch.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^
.PHONY: nordic_lib.s
nordic_lib.s: nordic_lib.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^

.PHONY: nordic_module.s
nordic_module.s: nordic_module.c
	$(CC) $(CFLAG) -I $(INCLUDE) -S $^

.PHONY: %.o
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) $^ -c

.PHONY: compile-all
compile-all: $(OBJ)
	$(CC) $(CFLAGS) -I $(INCLUDE) $^ -c

Build: $(COBJ)
	$(CC) $(CFLAGS) $^ -I $(INCLUDE) -o output
	$(CC) $(CFLAGS) -I $(INCLUDE) -M ./source/*.c > output.dep
	size -d output 
	objdump -a $(OBJ)
upload: output
	scp $(BBB)

Build-lib: $(CPROG)
	ar rU libproject1.a ./source/*.c
	ranlib libproject1.a 
	tar -cvf libproject1.tar ./source/*.c
	
clear:
	rm -rf *.i *.o *.s main compail-all Build Build-lib libproject1.a libproject1.tar Mapfile output

