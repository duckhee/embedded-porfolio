###########################################################
# GCC template makefile
###########################################################

LIBRARY_DRIVER_FAT_FS :=
LIBRARY_DRIVER_FAT_FS  += ppp_diskio_template.c
LIBRARY_DRIVER_FAT_FS  += sd_diskio_dma_rtos_template_bspv1.c
LIBRARY_DRIVER_FAT_FS  += sd_diskio_dma_rtos_template_bspv2.c
LIBRARY_DRIVER_FAT_FS  += sd_diskio_dma_template_bspv1.c
LIBRARY_DRIVER_FAT_FS  += sd_diskio_dma_template_bspv2.c
LIBRARY_DRIVER_FAT_FS  += sd_diskio_template_bspv1.c
LIBRARY_DRIVER_FAT_FS  += sd_diskio_template_bspv2.c
LIBRARY_DRIVER_FAT_FS  += sram_diskio_template.c
LIBRARY_DRIVER_FAT_FS  += usbh_diskio_dma_template.c
LIBRARY_DRIVER_FAT_FS  += usbh_diskio_template.c

EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/FatFs/src/drivers

C_SOURCES += $(LIBRARY_DRIVER_FAT_FS )