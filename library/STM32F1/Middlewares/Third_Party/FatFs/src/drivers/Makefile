###########################################################
# GCC template makefile
###########################################################

LIBRARY_DRIVER_FAT_FS :=
LIBRARY_DRIVER_FAT_FS  += sd_diskio.c
LIBRARY_DRIVER_FAT_FS  += sdram_diskio.c
LIBRARY_DRIVER_FAT_FS  += sram_diskio.c
LIBRARY_DRIVER_FAT_FS  += usbh_diskio.c


EXTRAINCDIRS += $(TOP)/library/STM32F1/Middlewares/Third_Party/FatFs/src/drivers

C_SOURCES += $(LIBRARY_DRIVER_FAT_FS)