################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../bag.cpp \
../bag_test.cpp 

OBJS += \
./bag.o \
./bag_test.o 

CPP_DEPS += \
./bag.d \
./bag_test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -D__cplusplus=201402L -I/usr/lib/boost_1_64_0 -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


