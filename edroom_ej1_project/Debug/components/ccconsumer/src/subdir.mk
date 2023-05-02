################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/ccconsumer/src/CCConsumerB.cpp \
../components/ccconsumer/src/CCConsumerS.cpp 

OBJS += \
./components/ccconsumer/src/CCConsumerB.o \
./components/ccconsumer/src/CCConsumerS.o 

CPP_DEPS += \
./components/ccconsumer/src/CCConsumerB.d \
./components/ccconsumer/src/CCConsumerS.d 


# Each subdirectory must supply rules for building sources it contributes
components/ccconsumer/src/%.o: ../components/ccconsumer/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


