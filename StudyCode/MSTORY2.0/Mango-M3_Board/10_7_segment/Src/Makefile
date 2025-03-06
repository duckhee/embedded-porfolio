###########################################################
# GCC template makefile
###########################################################

MANGO_BOARD_SEVEN_SEGMENT_SOURCE :=
MANGO_BOARD_SEVEN_SEGMENT_SOURCE += main.c
MANGO_BOARD_SEVEN_SEGMENT_SOURCE += key.c
MANGO_BOARD_SEVEN_SEGMENT_SOURCE += led.c
MANGO_BOARD_SEVEN_SEGMENT_SOURCE += segment.c

DEFAULT_ASMSOURCES :=
DEFAULT_ASMSOURCES = startup_stm32f10x_md.s

EXTRAINCDIRS +=  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/10_7_segment/Inc

ASM_SOURCES += $(DEFAULT_ASMSOURCES)
C_SOURCES += $(MANGO_BOARD_SEVEN_SEGMENT_SOURCE)