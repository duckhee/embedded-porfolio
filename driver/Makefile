###########################################################
# GCC template makefile
###########################################################

ifeq ($(CONFIG_STANDARD_DRIVER), y)

	ifeq ($(CONFIG_ARCH_M3), y)
		SUB_ARCH :=
		SUB_ARCH += STM32F10x_StdPeriph_Driver/Src

		SUB_ARCH := $(addprefix $(TOP)/driver/standard/, $(SUB_ARCH))

		vpath %.s $(SUB_ARCH)
		vpath %.c $(SUB_ARCH)
		vpath %.cpp $(SUB_ARCH)

	else ifeq ($(CONFIG_ARCH_M4), y)

                SUB_ARCH :=
                SUB_ARCH += STM32F4xx_StdPeriph_Driver/Src

                SUB_ARCH := $(addprefix $(TOP)/driver/standard/, $(SUB_ARCH))

                vpath %.s $(SUB_ARCH)
                vpath %.c $(SUB_ARCH)
                vpath %.cpp $(SUB_ARCH)

	endif

	sinclude $(addsuffix /Makefile, $(SUB_ARCH))

else ifeq ($(CONFIG_HAL_DRIVER), y)

	ifeq ($(CONFIG_ARCH_M3), y)

                SUB_ARCH :=
                SUB_ARCH += STM32F1xx_HAL_Driver/Src

                SUB_ARCH := $(addprefix $(TOP)/driver/hal/, $(SUB_ARCH))

                vpath %.s $(SUB_ARCH)
                vpath %.c $(SUB_ARCH)
                vpath %.cpp $(SUB_ARCH)

	else ifeq ($(CONFIG_ARCH_M4), y)

                SUB_ARCH :=
                SUB_ARCH += STM32F4xx_HAL_Driver/Src

                SUB_ARCH := $(addprefix $(TOP)/driver/hal/, $(SUB_ARCH))

                vpath %.s $(SUB_ARCH)
                vpath %.c $(SUB_ARCH)
                vpath %.cpp $(SUB_ARCH)

	endif


	sinclude $(addsuffix /Makefile, $(SUB_ARCH))

endif