################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/CCProducer/src/CCProducerB.cpp \
../components/CCProducer/src/CCProducerS.cpp 

OBJS += \
./components/CCProducer/src/CCProducerB.o \
./components/CCProducer/src/CCProducerS.o 

CPP_DEPS += \
./components/CCProducer/src/CCProducerB.d \
./components/CCProducer/src/CCProducerS.d 


# Each subdirectory must supply rules for building sources it contributes
components/CCProducer/src/%.o: ../components/CCProducer/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/dataclasses/CDAux/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/components/ccconsumer/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/components/ccproducer/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/components/example1/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/config/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/edroom_glue/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/edroombp_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/edroomsl_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/edroomsl_types_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej1_project/rtems_osswr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


