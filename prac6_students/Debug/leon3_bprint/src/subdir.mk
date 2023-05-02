################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../leon3_bprint/src/leon3_uart.c \
../leon3_bprint/src/leon_bprint.c 

OBJS += \
./leon3_bprint/src/leon3_uart.o \
./leon3_bprint/src/leon_bprint.o 

C_DEPS += \
./leon3_bprint/src/leon3_uart.d \
./leon3_bprint/src/leon_bprint.d 


# Each subdirectory must supply rules for building sources it contributes
leon3_bprint/src/%.o: ../leon3_bprint/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C Compiler'
	sparc-rtems-gcc -I"/home/user/workspace/prac7_1/rtems_osswr/include" -I"/home/user/workspace/prac7_1/leon3_bprint/include" -I"/home/user/workspace/prac7_1/bprint_swr/include" -I"/home/user/workspace/prac7_1/edroomsl_types_swr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


