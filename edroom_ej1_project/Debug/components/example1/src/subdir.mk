################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/example1/src/Example1B.cpp \
../components/example1/src/Example1S.cpp 

OBJS += \
./components/example1/src/Example1B.o \
./components/example1/src/Example1S.o 

CPP_DEPS += \
./components/example1/src/Example1B.d \
./components/example1/src/Example1S.d 


# Each subdirectory must supply rules for building sources it contributes
components/example1/src/%.o: ../components/example1/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


