################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../components/capathtracker/src/CAPathTrackerB.cpp \
../components/capathtracker/src/CAPathTrackerS.cpp 

OBJS += \
./components/capathtracker/src/CAPathTrackerB.o \
./components/capathtracker/src/CAPathTrackerS.o 

CPP_DEPS += \
./components/capathtracker/src/CAPathTrackerB.d \
./components/capathtracker/src/CAPathTrackerS.d 


# Each subdirectory must supply rules for building sources it contributes
components/capathtracker/src/%.o: ../components/capathtracker/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"/home/user/workspace/prac7_1/components/ccavoidobstacles/include" -I"/home/user/workspace/prac7_1/leon3_bprint/include" -I"/home/user/workspace/prac7_1/io_ctrl/include" -I"/home/user/workspace/prac7_1/bprint_swr/include" -I"/home/user/workspace/prac7_1/dataclasses/CDLocation/include" -I"/home/user/workspace/prac7_1/dataclasses/CDPath/include" -I"/home/user/workspace/prac7_1/actuators_drv/include" -I"/home/user/workspace/prac7_1/components/capathplanner/include" -I"/home/user/workspace/prac7_1/components/vehicle/include" -I"/home/user/workspace/prac7_1/planner_swr/include" -I"/home/user/workspace/prac7_1/random_swr/include" -I"/home/user/workspace/prac7_1/components/capathtracker/include" -I/opt/rtems-4.6/sparc-rtems/leon3/lib/include -I"/home/user/workspace/prac7_1/config/include" -I"/home/user/workspace/prac7_1/sensors_drv/include" -I"/home/user/workspace/prac7_1/edroom_glue/include" -I"/home/user/workspace/prac7_1/edroombp_swr/include" -I"/home/user/workspace/prac7_1/edroomsl_swr/include" -I"/home/user/workspace/prac7_1/edroomsl_types_swr/include" -I"/home/user/workspace/prac7_1/rtems_osswr/include" -O0 -g3 -Wall -msoft-float -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


