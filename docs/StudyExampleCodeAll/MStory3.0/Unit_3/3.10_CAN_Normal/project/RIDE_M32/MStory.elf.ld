
/*
!!! Primary linker script file generated automatically !!!
This file contains the input and output files names
It also includes the secondary/main linker script that is specified in the Ride options (default or custom)
*/

SEARCH_DIR(".")
SEARCH_DIR("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj")
SEARCH_DIR("C:\Program Files (x86)\Raisonance\Ride\Lib\ARM")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\usb_pwr.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\debug.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\hw_config.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\key.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\led.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\main.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\seven_segment.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\stm32f10x_it.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\usb_desc.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\usb_endp.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\usb_istr.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\usb_prop.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\system_stm32f10x.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\startup_stm32f10x_md.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\usb_regs.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\usb_core.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\usb_init.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\usb_int.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\usb_mem.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\stm32f10x_usart.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\misc.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\stm32f10x_adc.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\stm32f10x_dma.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\stm32f10x_exti.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\stm32f10x_gpio.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\stm32f10x_rcc.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\stm32f10x_pwr.o")
INPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\stm32f10x_can.o")
EXTERN( __io_putchar )
EXTERN( _write )
GROUP(
"STM32x_io_putchar_thumb.a"
"std_sbrk_thumb.lib"
"smallprintf_thumb.a"
"libc.a"
"libm.a"

)
INCLUDE "C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\obj\STM32F103_128K_20K_FLASH.ld"
OUTPUT("C:\Users\Administrator\Downloads\MStory3.0\Unit_3\3.10_CAN_Normal\project\RIDE_M32\MStory.elf")
