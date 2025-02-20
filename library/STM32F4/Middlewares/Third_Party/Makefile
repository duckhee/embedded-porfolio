###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
SUB_ARCH += ST
SUB_ARCH += Third_Party

ifeq ($(CONFIG_ARCH_M4), y)

ifeq ($(CONFIG_FAT_FS), y)
	SUB_ARCH += FatFs/Src
	SUB_ARCH += FatFs/Src/option
	SUB_ARCH += FatFs/Src/drivers
	SUB_ARCH := $(addprefix $(TOP)/library/STM32F4/Middlewares/Third_Party/, $(SUB_ARCH))

	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)

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

	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat/posix/net
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat/posix/sys
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat/stdc
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/lwip
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/lwip/apps
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/lwip/priv
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/lwip/prot
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/netif
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/netif/ppp
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/netif/polarssl


	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)

endif

endif

sinclude $(addsuffix /Makefile, $(SUB_ARCH))