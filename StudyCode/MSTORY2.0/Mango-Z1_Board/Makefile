###########################################################
# GCC template makefile
###########################################################


SUB_ARCH :=


SUB_ARCH := $(addprefix $(TOP)/StudyCode/MSTORY2.0/Mango-Z1_Board/, ${SUB_ARCH})

vpath %.c ${SUB_ARCH}
vpath %.s ${SUB_ARCH}

sinclude $(addsuffix /Makefile, ${SUB_ARCH})