###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=

ifeq ($(CONFIG_ARCH_M4), y)

ifeq ($(CONFIG_FAT_FS), y)
	SUB_ARCH += FatFs/src
	SUB_ARCH += FatFs/src/option
	SUB_ARCH += FatFs/src/drivers
	SUB_ARCH := $(addprefix $(TOP)/library/STM32F4/Middlewares/Third_Party/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)

	sinclude $(addsuffix /Makefile, $(SUB_ARCH))
endif

ifeq ($(CONFIG_LWIP), y)
	SUB_ARCH += LwIP/src/api
    SUB_ARCH += LwIP/src/apps
    SUB_ARCH += LwIP/src/apps/http
    SUB_ARCH += LwIP/src/apps/http/makefsdata
    SUB_ARCH += LwIP/src/apps/lwiperf
    SUB_ARCH += LwIP/src/apps/mdns
    SUB_ARCH += LwIP/src/apps/mqtt
    SUB_ARCH += LwIP/src/apps/netbiosns
    SUB_ARCH += LwIP/src/apps/smtp
    SUB_ARCH += LwIP/src/apps/snmp
    SUB_ARCH += LwIP/src/apps/sntp
    SUB_ARCH += LwIP/src/apps/tftp
    SUB_ARCH += LwIP/src/core
    SUB_ARCH += LwIP/src/core/ipv4
    SUB_ARCH += LwIP/src/core/ipv6
    SUB_ARCH += LwIP/src/netif
    SUB_ARCH += LwIP/src/netif/ppp
    SUB_ARCH += LwIP/src/netif/ppp/polarssl
    SUB_ARCH += LwIP/system/os
    SUB_ARCH += LwIP/test
	SUB_ARCH := $(addprefix $(TOP)/library/STM32F4/Middlewares/Third_Party/, $(SUB_ARCH))



	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)

	sinclude $(addsuffix /Makefile, $(SUB_ARCH))
endif

endif

