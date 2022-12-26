###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
SUB_ARCH += gcc

SUB_ARCH := $(addprefix $(TOP)/CMSIS/Core/CMSIS/Device/ST/STM32F1xx/Source/Templates/, $(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

EXTRAINCDIRS += $(TOP)/CMSIS/Core/CMSIS/Device/ST/STM32F1xx/Inc