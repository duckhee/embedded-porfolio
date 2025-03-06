###########################################################
# GCC template makefile
###########################################################


SUB_ARCH :=
SUB_ARCH += httpd
SUB_ARCH += httpd/makefsdata
SUB_ARCH += lwiperf
SUB_ARCH += mdns
SUB_ARCH += mqtt
SUB_ARCH += netbiosns
SUB_ARCH += snmp
SUB_ARCH += sntp
SUB_ARCH += tftp

SUB_ARCH := $(addprefix $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/apps/, $(SUB_ARCH))


vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)
vpath %.cpp $(SUB_ARCH)


sinclude $(addsuffix /Makefile, $(SUB_ARCH))