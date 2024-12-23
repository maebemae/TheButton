################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_app.c \
/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_app_simple_cdc.c \
/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_class.c \
/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_dev.c \
/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_hw_f1.c \
/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_hw_g0.c \
/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_hw_l0.c \
/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_hw_l4.c \
/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_log.c 

OBJS += \
./gbmUSBdevice/USBdev/Src/usb_app.o \
./gbmUSBdevice/USBdev/Src/usb_app_simple_cdc.o \
./gbmUSBdevice/USBdev/Src/usb_class.o \
./gbmUSBdevice/USBdev/Src/usb_dev.o \
./gbmUSBdevice/USBdev/Src/usb_hw_f1.o \
./gbmUSBdevice/USBdev/Src/usb_hw_g0.o \
./gbmUSBdevice/USBdev/Src/usb_hw_l0.o \
./gbmUSBdevice/USBdev/Src/usb_hw_l4.o \
./gbmUSBdevice/USBdev/Src/usb_log.o 

C_DEPS += \
./gbmUSBdevice/USBdev/Src/usb_app.d \
./gbmUSBdevice/USBdev/Src/usb_app_simple_cdc.d \
./gbmUSBdevice/USBdev/Src/usb_class.d \
./gbmUSBdevice/USBdev/Src/usb_dev.d \
./gbmUSBdevice/USBdev/Src/usb_hw_f1.d \
./gbmUSBdevice/USBdev/Src/usb_hw_g0.d \
./gbmUSBdevice/USBdev/Src/usb_hw_l0.d \
./gbmUSBdevice/USBdev/Src/usb_hw_l4.d \
./gbmUSBdevice/USBdev/Src/usb_log.d 


# Each subdirectory must supply rules for building sources it contributes
gbmUSBdevice/USBdev/Src/usb_app.o: /Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_app.c gbmUSBdevice/USBdev/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
gbmUSBdevice/USBdev/Src/usb_app_simple_cdc.o: /Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_app_simple_cdc.c gbmUSBdevice/USBdev/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
gbmUSBdevice/USBdev/Src/usb_class.o: /Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_class.c gbmUSBdevice/USBdev/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
gbmUSBdevice/USBdev/Src/usb_dev.o: /Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_dev.c gbmUSBdevice/USBdev/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
gbmUSBdevice/USBdev/Src/usb_hw_f1.o: /Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_hw_f1.c gbmUSBdevice/USBdev/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
gbmUSBdevice/USBdev/Src/usb_hw_g0.o: /Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_hw_g0.c gbmUSBdevice/USBdev/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
gbmUSBdevice/USBdev/Src/usb_hw_l0.o: /Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_hw_l0.c gbmUSBdevice/USBdev/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
gbmUSBdevice/USBdev/Src/usb_hw_l4.o: /Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_hw_l4.c gbmUSBdevice/USBdev/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
gbmUSBdevice/USBdev/Src/usb_log.o: /Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Src/usb_log.c gbmUSBdevice/USBdev/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_NUCLEO_64 -DUSE_HAL_DRIVER -DSTM32C071xx -c -I../Core/Inc -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/Example/Inc/STM32C0" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/gbmUSBdevice/USBdev/Inc" -I"/Users/mae/STM32CubeIDE/workspace_1.17.0/STM32_Inc" -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/BSP/STM32C0xx_Nucleo -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-gbmUSBdevice-2f-USBdev-2f-Src

clean-gbmUSBdevice-2f-USBdev-2f-Src:
	-$(RM) ./gbmUSBdevice/USBdev/Src/usb_app.cyclo ./gbmUSBdevice/USBdev/Src/usb_app.d ./gbmUSBdevice/USBdev/Src/usb_app.o ./gbmUSBdevice/USBdev/Src/usb_app.su ./gbmUSBdevice/USBdev/Src/usb_app_simple_cdc.cyclo ./gbmUSBdevice/USBdev/Src/usb_app_simple_cdc.d ./gbmUSBdevice/USBdev/Src/usb_app_simple_cdc.o ./gbmUSBdevice/USBdev/Src/usb_app_simple_cdc.su ./gbmUSBdevice/USBdev/Src/usb_class.cyclo ./gbmUSBdevice/USBdev/Src/usb_class.d ./gbmUSBdevice/USBdev/Src/usb_class.o ./gbmUSBdevice/USBdev/Src/usb_class.su ./gbmUSBdevice/USBdev/Src/usb_dev.cyclo ./gbmUSBdevice/USBdev/Src/usb_dev.d ./gbmUSBdevice/USBdev/Src/usb_dev.o ./gbmUSBdevice/USBdev/Src/usb_dev.su ./gbmUSBdevice/USBdev/Src/usb_hw_f1.cyclo ./gbmUSBdevice/USBdev/Src/usb_hw_f1.d ./gbmUSBdevice/USBdev/Src/usb_hw_f1.o ./gbmUSBdevice/USBdev/Src/usb_hw_f1.su ./gbmUSBdevice/USBdev/Src/usb_hw_g0.cyclo ./gbmUSBdevice/USBdev/Src/usb_hw_g0.d ./gbmUSBdevice/USBdev/Src/usb_hw_g0.o ./gbmUSBdevice/USBdev/Src/usb_hw_g0.su ./gbmUSBdevice/USBdev/Src/usb_hw_l0.cyclo ./gbmUSBdevice/USBdev/Src/usb_hw_l0.d ./gbmUSBdevice/USBdev/Src/usb_hw_l0.o ./gbmUSBdevice/USBdev/Src/usb_hw_l0.su ./gbmUSBdevice/USBdev/Src/usb_hw_l4.cyclo ./gbmUSBdevice/USBdev/Src/usb_hw_l4.d ./gbmUSBdevice/USBdev/Src/usb_hw_l4.o ./gbmUSBdevice/USBdev/Src/usb_hw_l4.su ./gbmUSBdevice/USBdev/Src/usb_log.cyclo ./gbmUSBdevice/USBdev/Src/usb_log.d ./gbmUSBdevice/USBdev/Src/usb_log.o ./gbmUSBdevice/USBdev/Src/usb_log.su

.PHONY: clean-gbmUSBdevice-2f-USBdev-2f-Src

