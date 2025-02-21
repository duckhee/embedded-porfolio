###########################################################
# GCC template makefile
###########################################################
SUB_ARCHS :=
SUB_ARCH += api
#SUB_ARCH += apps
#SUB_ARCH += apps/http
#SUB_ARCH += apps/http/makefsdata
#SUB_ARCH += apps/lwiperf
#SUB_ARCH += apps/mdns
SUB_ARCH += apps/mqtt
#SUB_ARCH += apps/netbiosns
#SUB_ARCH += apps/smtp
#SUB_ARCH += apps/snmp
#SUB_ARCH += apps/sntp
#SUB_ARCH += apps/tftp
SUB_ARCH += core
SUB_ARCH += core/ipv4
SUB_ARCH += core/ipv6
SUB_ARCH += netif
SUB_ARCH += netif/ppp
SUB_ARCH += netif/ppp/polarssl
SUB_ARCH += system/os
SUB_ARCH += test
SUB_ARCH := $(addprefix $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/, $(SUB_ARCH))



	vpath %.s $(SUB_ARCH)
	vpath %.c $(SUB_ARCH)

	sinclude $(addsuffix /Makefile, $(SUB_ARCH))