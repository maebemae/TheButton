# THE BUTTON

This project aims to solve a key issue of the everyday programmer - how to safely, reliably, and in a repeatable fashion provide good feedback.

# Demonstration

[Youtube Video](https://www.youtube.com/shorts/mlwx9P0IeXQ) showing the button in action

# Flashing the firmware
## Using USB DFU

1. Put The Button into DFU mode, either by
	a. Fully pressing the button and then plugging it in, or
	b. Pressing the 'boot' button and then plugging it in
2. You can use the [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html) or [DfuSe](https://www.st.com/en/development-tools/stsw-stm32080.html)
3. Select USB Connection, and refresh the Port Necessarily. If you have sucessfully put your device into DFU mode, you will now see USB1 (or similar number) in the ports
4. Click connect
5. Switch to the 'Erasing & Programming' Section, load the firmware file path, and
6. Start programming
7. Disconnect and Reconnect The Button 

# Hardware

I've selected the STM32C071 as it has crystalless USB, is affordable with sufficient Flash, RAM and GPIO for potential extensions. It also has affordable dev kit [STM32 nucleo-c071rb](https://www.st.com/en/evaluation-tools/nucleo-c071rb.html) at $10 with USB-C.

Designed with Kicad, can be found under /pcb

The schematic and gerbers can be found under /pcb/v<version>, e.g. /pcb/v1

# Firmware

The project is built with [STM32CubeIde](https://www.st.com/en/development-tools/stsw-stm32080.html)

Main entrypoint can be found at `The Buttoner/Core/Src/main` \
This is where the initialization generated by the STM32CubeMx IOC project happens,and also where we actually process the inputs

The second point is in `The Buttoner/libs/gbmUSBdevice/USBdev/Src/usb_app.c`, this is where we have the polled hook `HIDUpdateKB` which actually does the writing out to usb 

The gbmUSBdevice library was slightly altered and linked into the project. See [gbmUSBdevice](https://github.com/gbm-ii/gbmUSBdevice) for more details.

# Todo

1. Hardware
	1. Add optional eeprom
	1. Add hardware revision selector pins
	1. Add USB vid/pid selector (or do we just leave this in firmware?
	1. Add OpenHardware Logo 

1. Firmware
	1. Add ondemand VCP to configure messages
	1. Apply for dedicated vid/pid from openmoko

1. Project
	1. Cleanup structure 
	1. Tag versions
