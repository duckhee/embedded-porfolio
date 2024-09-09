###########################################################
# GCC template makefile
###########################################################


SUB_ARCH :=
ifeq ($(CONFIG_H_HIVE_EDU_BOARD_SIMPLE_LED),y)
	SUB_ARCH += 01_simple_gpio/Src
	SUB_ARCH := $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMXstudy/,$(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)
endif

sinclude $(addsuffix /Makefile, $(SUB_ARCH))