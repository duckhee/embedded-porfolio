###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=
SUB_ARCH += src
SUB_ARCH += src/api
SUB_ARCH += src/apps
SUB_ARCH += src/core
SUB_ARCH += src/core/ipv4
SUB_ARCH += src/core/ipv6
SUB_ARCH += src/netif
SUB_ARCH += src/netif/ppp
SUB_ARCH += src/netif/ppp/polarssl
SUB_ARCH += system/OS

SUB_ARCH := $(addprefix $(TOP)/library/STM32F1/Third_Party/LwIP/, $(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)
vpath %.cpp $(SUB_ARCH)

sinclude $(addsuffix /Makefile, $(SUB_ARCH))