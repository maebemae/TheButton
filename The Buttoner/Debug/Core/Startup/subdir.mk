################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32c071rbtx.s 

OBJS += \
./Core/Startup/startup_stm32c071rbtx.o 

S_DEPS += \
./Core/Startup/startup_stm32c071rbtx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g3 -DDEBUG -c -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/STM32_Inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32c071rbtx.d ./Core/Startup/startup_stm32c071rbtx.o

.PHONY: clean-Core-2f-Startup

