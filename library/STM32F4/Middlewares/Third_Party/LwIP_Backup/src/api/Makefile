###########################################################
# GCC template makefile
###########################################################

LIBRARY_LWIP_SOURCE :=
LIBRARY_LWIP_SOURCE += api_lib.c
LIBRARY_LWIP_SOURCE += api_msg.c
LIBRARY_LWIP_SOURCE += err.c
LIBRARY_LWIP_SOURCE += if_api.c
LIBRARY_LWIP_SOURCE += netbuf.c
LIBRARY_LWIP_SOURCE += netdb.c
LIBRARY_LWIP_SOURCE += netifapi.c
LIBRARY_LWIP_SOURCE += sockets.c
LIBRARY_LWIP_SOURCE += tcpip.c


	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include

	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/system
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/system/arch
	EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat/posix
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


C_SOURCES += $(LIBRARY_LWIP_SOURCE)