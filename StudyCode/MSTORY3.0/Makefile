###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
SUB_ARCH += Mango-M3_Board
SUB_ARCH += Mango-Z1_Board

SUB_ARCH := $(addprefix $(TOP)/StudyCode/MSTORY3.0/, ${SUB_ARCH})

vpath %.c ${SUB_ARCH}
vpath %.s ${SUB_ARCH}

sinclude $(addsuffix /Makefile, ${SUB_ARCH})