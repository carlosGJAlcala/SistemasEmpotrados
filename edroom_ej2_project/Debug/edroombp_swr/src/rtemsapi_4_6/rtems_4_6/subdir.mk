################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.cpp 

OBJS += \
./edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.o 

CPP_DEPS += \
./edroombp_swr/src/rtemsapi_4_6/rtems_4_6/edroombp.d 


# Each subdirectory must supply rules for building sources it contributes
edroombp_swr/src/rtemsapi_4_6/rtems_4_6/%.o: ../edroombp_swr/src/rtemsapi_4_6/rtems_4_6/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej2_project/config/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej2_project/edroom_glue/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej2_project/edroombp_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej2_project/edroomsl_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej2_project/edroomsl_types_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/edroom_ej2_project/rtems_osswr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


