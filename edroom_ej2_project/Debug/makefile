################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include edroomsl_types_swr/src/subdir.mk
-include edroomsl_swr/src/subdir.mk
-include edroombp_swr/src/rtemsapi_4_6/rtems_4_6/subdir.mk
-include edroom_glue/src/subdir.mk
-include components/Example2/src/subdir.mk
-include components/CCServer/src/subdir.mk
-include components/CCClient/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: edroom_ej2_project

# Tool invocations
edroom_ej2_project: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: SPARC RTEMS C++ Linker'
	sparc-rtems-g++ -msoft-float -o "edroom_ej2_project" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(S_DEPS)$(S_UPPER_DEPS)$(CPP_DEPS)$(C_DEPS) edroom_ej2_project
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
