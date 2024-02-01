###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
SUB_ARCH += MSTORY2.0
# SUB_ARCH += MSTORY3.0
# SUB_ARCH += M-HIVE-EduBoard

SUB_ARCH := $(addprefix $(TOP)/StudyCode/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile, $(SUB_ARCH))

