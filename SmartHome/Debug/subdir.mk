################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BUZZER.c \
../DC_MOTOR.c \
../FlameSensor.c \
../GPIO.c \
../LCD.c \
../LDR.c \
../LED.c \
../PWM.c \
../adc.c \
../lm35_sensor.c \
../smarHomeAppl.c 

OBJS += \
./BUZZER.o \
./DC_MOTOR.o \
./FlameSensor.o \
./GPIO.o \
./LCD.o \
./LDR.o \
./LED.o \
./PWM.o \
./adc.o \
./lm35_sensor.o \
./smarHomeAppl.o 

C_DEPS += \
./BUZZER.d \
./DC_MOTOR.d \
./FlameSensor.d \
./GPIO.d \
./LCD.d \
./LDR.d \
./LED.d \
./PWM.d \
./adc.d \
./lm35_sensor.d \
./smarHomeAppl.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


