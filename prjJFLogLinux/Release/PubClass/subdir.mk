################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PubClass/StaticPubFunc.cpp 

OBJS += \
./PubClass/StaticPubFunc.o 

CPP_DEPS += \
./PubClass/StaticPubFunc.d 


# Each subdirectory must supply rules for building sources it contributes
PubClass/%.o: ../PubClass/%.cpp PubClass/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -fPIC -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


