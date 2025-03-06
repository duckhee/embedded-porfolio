###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
SUB_ARCH += ST
SUB_ARCH += Third_Party


SUB_ARCH := $(addprefix $(TOP)/library/STM32F1/Middlewares/, $(SUB_ARCH))

sinclude $(addsuffix /Makefile, $(SUB_ARCH))