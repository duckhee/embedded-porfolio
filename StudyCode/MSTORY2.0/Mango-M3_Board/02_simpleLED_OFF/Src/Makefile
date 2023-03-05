###########################################################
# GCC template makefile
###########################################################

ifeq ($(CONFIG_),y)
  	MANGO_BOARD_LED_OFF_SOURCES =
    MANGO_BOARD_LED_OFF_SOURCES += main.c
    DEFAULT_ASMSOURCES =
    DEFAULT_ASMSOURCES = startup_stm32f10x_md.s

    EXTRAINCDIRS += $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/02_simpleLED_OFF

    ASM_SOURCES += $(DEFAULT_ASMSOURCES)

    C_SOURCES += $(MANGO_BOARD_LED_OFF_SOURCES)
endif