################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../edroomsl_swr/src/edroomsl.cpp \
../edroomsl_swr/src/edroomtc.cpp 

OBJS += \
./edroomsl_swr/src/edroomsl.o \
./edroomsl_swr/src/edroomtc.o 

CPP_DEPS += \
./edroomsl_swr/src/edroomsl.d \
./edroomsl_swr/src/edroomtc.d 


# Each subdirectory must supply rules for building sources it contributes
edroomsl_swr/src/%.o: ../edroomsl_swr/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/components/ccavoidobstacles/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/leon3_bprint/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/io_ctrl/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/bprint_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/dataclasses/CDLocation/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/dataclasses/CDPath/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/actuators_drv/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/components/capathplanner/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/components/vehicle/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/planner_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/random_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/components/capathtracker/include" -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/config/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/sensors_drv/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/edroom_glue/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/edroombp_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/edroomsl_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/edroomsl_types_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_students/rtems_osswr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


