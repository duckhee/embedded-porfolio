###########################################################
# GCC template makefile
###########################################################


SUB_ARCH :=
ifeq ($(CONFIG_H_HIVE_EDU_BOARD_SIMPLE_LED),y)
	SUB_ARCH += 01_simple_gpio/Src
	SUB_ARCH := $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMXstudy/,$(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_SIMPLE_UART),y)
	SUB_ARCH += 02_simple_uart/Src
	SUB_ARCH := $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMXstudy/,$(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_SIMPLE_UART_PRINTF),y)
	SUB_ARCH += 03_uart_printf/Src
	SUB_ARCH := $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_UART_RECEIVE_INTERRUPT),y)
		SUB_ARCH += 04_uart_interrupt/Src
    	SUB_ARCH := $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

    	vpath %.s $(SUB_ARCH)
    	vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_CHARACTER_LCD_OUTPUT), y)

	SUB_ARCH += 05_character_LCD/Src
	SUB_ARCH :=  $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_TIME_TIMER),y)

SUB_ARCH += 06_TIM_Timer/Src

	SUB_ARCH :=  $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

sinclude $(addsuffix /Makefile, $(SUB_ARCH))