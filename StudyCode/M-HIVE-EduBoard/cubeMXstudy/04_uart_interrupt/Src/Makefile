###########################################################
# GCC template makefile
###########################################################

  	EDU_BOARD_SIMPLE_UART_RECEIVE_INTERRUPT :=
  	EDU_BOARD_SIMPLE_UART_RECEIVE_INTERRUPT += stm32f4xx_hal_msp.c
  	EDU_BOARD_SIMPLE_UART_RECEIVE_INTERRUPT += stm32f4xx_it.c
  	EDU_BOARD_SIMPLE_UART_RECEIVE_INTERRUPT += syscalls.c
  	EDU_BOARD_SIMPLE_UART_RECEIVE_INTERRUPT += sysmem.c
  	EDU_BOARD_SIMPLE_UART_RECEIVE_INTERRUPT += system_stm32f4xx.c
    EDU_BOARD_SIMPLE_UART_RECEIVE_INTERRUPT += main.c


    EXTRAINCDIRS += $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMXstudy/04_uart_interrupt/Inc

    ASM_SOURCES += $(DEFAULT_ASMSOURCES)

    C_SOURCES += $(EDU_BOARD_SIMPLE_UART_RECEIVE_INTERRUPT)
