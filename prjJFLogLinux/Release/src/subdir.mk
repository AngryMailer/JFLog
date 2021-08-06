################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Log.cpp \
../src/LogText.cpp \
../src/inifile.cpp \
../src/prjJFLogLinux.cpp 

OBJS += \
./src/Log.o \
./src/LogText.o \
./src/inifile.o \
./src/prjJFLogLinux.o 

CPP_DEPS += \
./src/Log.d \
./src/LogText.d \
./src/inifile.d \
./src/prjJFLogLinux.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -fPIC -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


