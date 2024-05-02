###########################################################
# GCC template makefile
###########################################################


#ifeq ($(CONFIG_MANGO_BOARD_LED_CONTROL_ADDRESS_OFFSET), y)
  	MANGO_BOARD_LED_CONTROL_ADDRESS_OFFSET :=
    MANGO_BOARD_LED_CONTROL_ADDRESS_OFFSET += led.c
    MANGO_BOARD_LED_CONTROL_ADDRESS_OFFSET += main.c
    DEFAULT_ASMSOURCES :=
    DEFAULT_ASMSOURCES = startup_stm32f10x_md.s

    EXTRAINCDIRS += $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/05_led_control_with_address_offset/Inc

    ASM_SOURCES += $(DEFAULT_ASMSOURCES)

    C_SOURCES += $(MANGO_BOARD_LED_CONTROL_ADDRESS_OFFSET)


#endif