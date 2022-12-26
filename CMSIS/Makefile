###########################################################
# GCC template makefile
###########################################################

ifeq ($(CONFIG_STANDARD_DRIVER), y)
    ifeq ($(CONFIG_ARCH_M3), y)
    
        #core cortex m3
        SUB_ARCH :=
        SUB_ARCH += Core/CM3
        SUB_ARCH += Core/CM3/startup/gcc

        SUB_ARCH := $(addprefix $(TOP)/CMSIS/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)


        #include sub makefile add
        sinclude $(addsuffix /Makefile, $(SUB_ARCH))


        #include Header File
        EXTRAINCDIRS += $(TOP)/CMSIS/Core/CM3

    else ifeq ($(CONFIG_ARCH_M4), y)

        SUB_ARCH := 
        SUB_ARCH += Core/CM4/startup
        SUB_ARCH += Core/CM4/startup/gcc

        SUB_ARCH := $(addprefix $(TOP)/CMSIS/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

        sinclude $(addsuffix /Makefile, $(SUB_ARCH))
        
    endif
else ifeq ($(CONFIG_HAL_DRIVER), y)
    ifeq ($(CONFIG_ARCH_M3), y)
    
        #cortex cm3
        SUB_ARCH :=
        SUB_ARCH += Core/CMSIS/Device/ST/STM32F1xx/Source/Templates

        SUB_ARCH := $(addprefix $(TOP)/CMSIS/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

        sinclude $(addsuffix /Makefile, $(SUB_ARCH))

        EXTRAINCDIRS += $(TOP)/CMSIS/Core/CMSIS/Inc

    else ifeq ($(CONFIG_ARCH_M4), y)
    
        #cortex cm4
        SUB_ARCH :=
        SUB_ARCH += Core/CMSIS/Device/ST/STM32F4xx/Source/Templates

        SUB_ARCH := $(addprefix $(TOP)/CMSIS/, $(SUB_ARCH))

        vpath %.c $(SUB_ARCH)
        vpath %.s $(SUB_ARCH)

        sinclude $(addsuffix /Makefile, $(SUB_ARCH))

        EXTRAINCDIRS += $(TOP)/CMSIS/Core/CMSIS/Inc

    endif
endif



