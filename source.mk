OBJ= main.o ADC.o capacitive_touch.o nordic_module.o nordic_lib.o
SRC= main.c ADC.c capacitive_touch.c nordic_module.c nordic_lib.c #project.c #memory.c #data.c
ASM = main.s ADC.s 
Preprocessed = main.i ADC.i #project.i #memory.i #data.i
VPATH : ADC capacitive_touch project

vpath %.s asm-file
vpath %.i preprocessed	
vpath %.c source
vpath %.h HEADER
	
