################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/capathplanner/src/CAPathPlannerB.cpp \
../components/capathplanner/src/CAPathPlannerS.cpp 

OBJS += \
./components/capathplanner/src/CAPathPlannerB.o \
./components/capathplanner/src/CAPathPlannerS.o 

CPP_DEPS += \
./components/capathplanner/src/CAPathPlannerB.d \
./components/capathplanner/src/CAPathPlannerS.d 


# Each subdirectory must supply rules for building sources it contributes
components/capathplanner/src/%.o: ../components/capathplanner/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/components/ccavoidobstaclesirq/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/leon3_bprint/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/io_ctrl/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/bprint_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/dataclasses/CDLocation/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/dataclasses/CDPath/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/actuators_drv/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/components/capathplanner/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/components/vehicle/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/planner_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/random_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/components/capathtracker/include" -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/config/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/sensors_drv/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/edroom_glue/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/edroombp_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/edroomsl_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/edroomsl_types_swr/include" -I"/home/carlos/OneDrive/3anyo/2cuatri/SistemasEmpotrados/workspace/prac6_2_students/rtems_osswr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


