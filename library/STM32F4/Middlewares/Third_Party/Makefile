###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
SUB_ARCH += ST
SUB_ARCH += Third_Party

ifeq ($(CONFIG_ARCH_M4), y)
ifeq ($(CONFIG_FAT_FS), y)
	SUB_ARCH += FatFs/Src
	SUB_ARCH += FatFs/Src/option
	SUB_ARCH += FatFs/Src/drivers
	SUB_ARCH := $(addprefix $(TOP)/library/STM32F4/Middlewares/Third_Party/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)

endif

endif

sinclude $(addsuffix /Makefile, $(SUB_ARCH))