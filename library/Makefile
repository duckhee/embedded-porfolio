###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
SUB_ARCH += STM32F1
SUB_ARCH += STM32F4


SUB_ARCH := $(addprefix $(TOP)/library/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile, $(SUB_ARCH))


