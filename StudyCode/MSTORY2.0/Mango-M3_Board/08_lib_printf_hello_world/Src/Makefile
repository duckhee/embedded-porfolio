###########################################################
# GCC template makefile
###########################################################

MANGO_BOARD_LIB_PRINTF_SOURCE :=
MANGO_BOARD_LIB_PRINTF_SOURCE += key.c
MANGO_BOARD_LIB_PRINTF_SOURCE += led.c
MANGO_BOARD_LIB_PRINTF_SOURCE += main.c

DEFAULT_ASMSOURCES :=
DEFAULT_ASMSOURCES = startup_stm32f10x_md.s

EXTRAINCDIRS += $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/08_lib_printf_hello_world/Inc

ASM_SOURCES += $(DEFAULT_ASMSOURCES)

C_SOURCES += $(MANGO_BOARD_LIB_PRINTF_SOURCE)