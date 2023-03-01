###########################################################
# GCC template makefile
###########################################################
ifeq ($(CONFIG_MANGO_M3_BOARD_SIMPLE_LED_ON), y)

    MANGO_BOARD_LED_ON_SOURCES =
    MANGO_BOARD_LED_ON_SOURCES += main.c


    EXTRAINCDIRS += $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/01_simpleLED/Inc

    DEFAULT_ASMSOURCES = startup_stm32f10x_md.s

    ASM_SOURCES += $(DEFAULT_ASMSOURCES)

    C_SOURCES += $(MANGO_BOARD_LED_ON_SOURCES)
endif