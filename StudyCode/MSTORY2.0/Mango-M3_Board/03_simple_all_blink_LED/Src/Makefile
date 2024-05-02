###########################################################
# GCC template makefile
###########################################################


#ifeq ($(CONFIG_MANGO_M3_BOARD_SIMPLE_ALL_LED_BLINK), y)
  	MANGO_BOARD_LED_ALL_BLINK_SOURCES :=
    MANGO_BOARD_LED_ALL_BLINK_SOURCES += main.c
    DEFAULT_ASMSOURCES :=
    DEFAULT_ASMSOURCES = startup_stm32f10x_md.s

    EXTRAINCDIRS += $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/03_simple_all_blink_LED/Inc

    ASM_SOURCES += $(DEFAULT_ASMSOURCES)

    C_SOURCES += $(MANGO_BOARD_LED_ALL_BLINK_SOURCES)


#endif