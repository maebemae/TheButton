################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libs/gbmUSBdevice/Example/Src/usbdev_main.c 

OBJS += \
./gbmUSBdevice/Example/Src/usbdev_main.o 

C_DEPS += \
./gbmUSBdevice/Example/Src/usbdev_main.d 


# Each subdirectory must supply rules for building sources it contributes
gbmUSBdevice/Example/Src/usbdev_main.o: /Users/mae/STM32CubeIDE/workspace_1.17.0/The\ Buttoner/libs/gbmUSBdevice/Example/Src/usbdev_main.c gbmUSBdevice/Example/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/The Buttoner/libs/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/The Buttoner/libs/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/The Buttoner/libs/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-gbmUSBdevice-2f-Example-2f-Src

clean-gbmUSBdevice-2f-Example-2f-Src:
	-$(RM) ./gbmUSBdevice/Example/Src/usbdev_main.cyclo ./gbmUSBdevice/Example/Src/usbdev_main.d ./gbmUSBdevice/Example/Src/usbdev_main.o ./gbmUSBdevice/Example/Src/usbdev_main.su

.PHONY: clean-gbmUSBdevice-2f-Example-2f-Src

