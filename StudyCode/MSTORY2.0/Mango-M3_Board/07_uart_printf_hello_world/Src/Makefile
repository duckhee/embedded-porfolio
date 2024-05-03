###########################################################
# GCC template makefile
###########################################################

MANGO_BOARD_UART_HELLO_WORLD_SOURCE :=
MANGO_BOARD_UART_HELLO_WORLD_SOURCE += key.c
MANGO_BOARD_UART_HELLO_WORLD_SOURCE += led.c
MANGO_BOARD_UART_HELLO_WORLD_SOURCE += main.c

DEFAULT_ASMSOURCES :=
DEFAULT_ASMSOURCES = startup_stm32f10x_md.s

EXTRAINCDIRS += $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/07_uart_printf_hello_world/Inc

ASM_SOURCES += $(DEFAULT_ASMSOURCES)

C_SOURCES += $(MANGO_BOARD_UART_HELLO_WORLD_SOURCE)