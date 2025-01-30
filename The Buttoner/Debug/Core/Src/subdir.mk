################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/bootloader.c \
../Core/Src/hid_converter.c \
../Core/Src/main.c \
../Core/Src/messages.c \
../Core/Src/stm32c0xx_hal_msp.c \
../Core/Src/stm32c0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32c0xx.c \
../Core/Src/user_data.c \
../Core/Src/user_interface.c 

OBJS += \
./Core/Src/bootloader.o \
./Core/Src/hid_converter.o \
./Core/Src/main.o \
./Core/Src/messages.o \
./Core/Src/stm32c0xx_hal_msp.o \
./Core/Src/stm32c0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32c0xx.o \
./Core/Src/user_data.o \
./Core/Src/user_interface.o 

C_DEPS += \
./Core/Src/bootloader.d \
./Core/Src/hid_converter.d \
./Core/Src/main.d \
./Core/Src/messages.d \
./Core/Src/stm32c0xx_hal_msp.d \
./Core/Src/stm32c0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32c0xx.d \
./Core/Src/user_data.d \
./Core/Src/user_interface.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/The Buttoner/libs/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/The Buttoner/libs/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/The Buttoner/libs/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/bootloader.cyclo ./Core/Src/bootloader.d ./Core/Src/bootloader.o ./Core/Src/bootloader.su ./Core/Src/hid_converter.cyclo ./Core/Src/hid_converter.d ./Core/Src/hid_converter.o ./Core/Src/hid_converter.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/messages.cyclo ./Core/Src/messages.d ./Core/Src/messages.o ./Core/Src/messages.su ./Core/Src/stm32c0xx_hal_msp.cyclo ./Core/Src/stm32c0xx_hal_msp.d ./Core/Src/stm32c0xx_hal_msp.o ./Core/Src/stm32c0xx_hal_msp.su ./Core/Src/stm32c0xx_it.cyclo ./Core/Src/stm32c0xx_it.d ./Core/Src/stm32c0xx_it.o ./Core/Src/stm32c0xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32c0xx.cyclo ./Core/Src/system_stm32c0xx.d ./Core/Src/system_stm32c0xx.o ./Core/Src/system_stm32c0xx.su ./Core/Src/user_data.cyclo ./Core/Src/user_data.d ./Core/Src/user_data.o ./Core/Src/user_data.su ./Core/Src/user_interface.cyclo ./Core/Src/user_interface.d ./Core/Src/user_interface.o ./Core/Src/user_interface.su

.PHONY: clean-Core-2f-Src

