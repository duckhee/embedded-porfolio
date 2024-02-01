###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
ifeq ($(CONFIG_MANGO_M3_BOARD_SIMPLE_LED_ON),y)
SUB_ARCH += 01_simpleLED/Src
else ifeq ($(CONFIG_MANGO_M3_BOARD_SIMPLE_LED_BLINK_ONCE),y)
SUB_ARCH += 02_simpleLED_OFF/Src
else ifeq ($(CONFIG_MANGO_M3_BOARD_SIMPLE_ALL_LED_BLINK),y)
SUB_ARCH += 03_simple_all_blink_LED/Src
endif
SUB_ARCH := $(addprefix  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/,$(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

sinclude $(addsuffix  /Makefile,$(SUB_ARCH))
