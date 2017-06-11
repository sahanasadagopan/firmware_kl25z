################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/ADC.c \
../Sources/capacitive_touch.c \
../Sources/main.c \
../Sources/nordic_lib.c \
../Sources/nordic_module.c 

OBJS += \
./Sources/ADC.o \
./Sources/capacitive_touch.o \
./Sources/main.o \
./Sources/nordic_lib.o \
./Sources/nordic_module.o 

C_DEPS += \
./Sources/ADC.d \
./Sources/capacitive_touch.d \
./Sources/main.d \
./Sources/nordic_lib.d \
./Sources/nordic_module.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


