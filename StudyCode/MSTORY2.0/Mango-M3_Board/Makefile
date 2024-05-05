###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
ifeq ($(CONFIG_MANGO_M3_BOARD_SIMPLE_LED_ON),y)
SUB_ARCH += 01_simpleLED/Src

SUB_ARCH := $(addprefix  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/,$(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

else ifeq ($(CONFIG_MANGO_M3_BOARD_SIMPLE_LED_BLINK_ONCE),y)
SUB_ARCH += 02_simpleLED_OFF/Src

SUB_ARCH := $(addprefix  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/,$(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

else ifeq ($(CONFIG_MANGO_M3_BOARD_SIMPLE_ALL_LED_BLINK),y)
SUB_ARCH += 03_simple_all_blink_LED/Src

SUB_ARCH := $(addprefix  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/,$(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

else ifeq ($(CONFIG_MANGO_M3_BOARD_LED_CONTROL_WITH_DEFINE),y)
SUB_ARCH += 04_led_control_with_define_header/Src

SUB_ARCH := $(addprefix  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/,$(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

else ifeq ($(CONFIG_MANGO_BOARD_LED_CONTROL_ADDRESS_OFFSET),y)
SUB_ARCH += 05_led_control_with_address_offset/Src

SUB_ARCH := $(addprefix  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/,$(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

else ifeq ($(CONFIG_MANGO_BOARD_KEY_PRESS),y)
SUB_ARCH += 06_key_press/Src

SUB_ARCH := $(addprefix  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/,$(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

else ifeq ($(CONFIG_UART_HELLO_WORLD),y)
SUB_ARCH += 07_uart_printf_hello_world/Src

SUB_ARCH := $(addprefix  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/,$(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

else ifeq ($(CONFIG_USART_STANDARD_IO_HELLO_WORLD), y)

SUB_ARCH += 08_lib_printf_hello_world/Src

SUB_ARCH := $(addprefix  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/,$(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

else ifeq ($(CONFIG_RECEIVE_USART_DATA),y)

SUB_ARCH += 09_uart_receive_data/Src
SUB_ARCH := $(addprefix  $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/,$(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

endif


sinclude $(addsuffix  /Makefile,$(SUB_ARCH))
