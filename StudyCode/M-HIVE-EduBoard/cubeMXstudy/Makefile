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

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_TIME_TIMER_SEG),y)

	SUB_ARCH += 07_TIM_Timer_SEG/Src

	SUB_ARCH :=  $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_EXTI_INPUT),y)

	SUB_ARCH += 08_EXTI_InputInterrupt/Src

	SUB_ARCH :=  $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_PWM_BASIC), y)
	SUB_ARCH += 09_PWM_Basic/Src

	SUB_ARCH :=  $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_PWM_SERVO_MOTOR), y)
	SUB_ARCH += 10_PWM_SERVO_90/Src

	SUB_ARCH :=  $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_PWM_BUZZER), y)
	SUB_ARCH += 11_PWM_passive_buzzer/Src

	SUB_ARCH :=  $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_PWM_MOTOR), y)
	SUB_ARCH += 12_PWM_DC_Motor/Src

	SUB_ARCH :=  $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_PWM_REPEAT_CYCLE), y)
	SUB_ARCH += 13_PWM_repeat_Cycle/Src

	SUB_ARCH :=  $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

ifeq ($(CONFIG_H_HIVE_EDU_BOARD_ADC_WITH_DMA), y)

	SUB_ARCH += 14_ADC_with_DMA/Src

	SUB_ARCH :=  $(addprefix $(TOP)/StudyCode/M-HIVE-EduBoard/cubeMxstudy/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)
endif

sinclude $(addsuffix /Makefile, $(SUB_ARCH))