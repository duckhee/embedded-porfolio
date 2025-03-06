###########################################################
# GCC template makefile
###########################################################

SUB_ARCH :=

SUB_ARCH += api
SUB_ARCH += apps
SUB_ARCH += core
SUB_ARCH += core/ipv4
SUB_ARCH += core/ipv6
SUB_ARCH += netif
SUB_ARCH += netif/ppp

EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/system/arch \
$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/system

EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include \
$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/lwip \
$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat \
$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/netif \
#$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/lwip/apps \
#$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/lwip/priv \
#$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/lwip/prot \
#$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat/stdc \
#$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat/posix \
#$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa \
#$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat/posix/net \
#$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/compat/posix/sys \
#$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/include/netif/ppp \

SUB_ARCH := $(addprefix $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/, $(SUB_ARCH))


vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)
vpath %.cpp $(SUB_ARCH)

sinclude $(addsuffix /Makefile, $(SUB_ARCH))

