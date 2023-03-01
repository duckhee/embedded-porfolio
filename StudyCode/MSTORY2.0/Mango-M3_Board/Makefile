###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
SUB_ARCH += 01_simpleLED/Src

SUB_ARCH := $(addprefix $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)


sinclude $(addsuffix /Makefile, $(SUB_ARCH))
