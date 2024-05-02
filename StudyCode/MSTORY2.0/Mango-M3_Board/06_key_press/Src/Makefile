###########################################################
# GCC template makefile
###########################################################


#ifeq ($(CONFIG_MANGO_BOARD_KEY_PRESS), y)
  	MANGO_BOARD_MANGO_BOARD_KEY_PRESS :=
    MANGO_BOARD_MANGO_BOARD_KEY_PRESS += led.c
    MANGO_BOARD_MANGO_BOARD_KEY_PRESS += key.c
    MANGO_BOARD_MANGO_BOARD_KEY_PRESS += main.c
    DEFAULT_ASMSOURCES :=
    DEFAULT_ASMSOURCES = startup_stm32f10x_md.s

    EXTRAINCDIRS += $(TOP)/StudyCode/MSTORY2.0/Mango-M3_Board/06_key_press/Inc

    ASM_SOURCES += $(DEFAULT_ASMSOURCES)

    C_SOURCES += $(MANGO_BOARD_MANGO_BOARD_KEY_PRESS)

#    vpath %.c $(SUB_ARCH)
#    vpath %.s $(SUB_ARCH)

#endif