###########################################################
# GCC template makefile
###########################################################

ifeq ($(CONFIG_MANGO_M3_BOARD_LED_CONTROL_WITH_DEFINE), y)
	MANGO_BOARD_LED_CONTROL_WITH_DEFINE_SOURCES :=
    MANGO_BOARD_LED_CONTROL_WITH_DEFINE_SOURCES += main.c
    MANGO_BOARD_LED_CONTROL_WITH_DEFINE_SOURCES += led.c
    DEFAULT_ASMSOURCES :=
    DEFAULT_ASMSOURCES = startup_stm32f10x_md.s

    EXTRAINCDIRS += $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/04_led_control_with_define_header/Inc

    ASM_SOURCES += $(DEFAULT_ASMSOURCES)

    C_SOURCES += $(MANGO_BOARD_LED_CONTROL_WITH_DEFINE_SOURCES)
endif