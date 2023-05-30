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
	sparc-rtems-g++ -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/dataclasses/CDAux/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/components/ccconsumer/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/components/ccproducer/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/components/example1/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/config/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/edroom_glue/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/edroombp_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/edroomsl_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/edroomsl_types_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/rtems_osswr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


