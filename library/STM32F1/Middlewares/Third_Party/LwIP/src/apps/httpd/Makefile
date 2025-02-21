###########################################################
# GCC template makefile
###########################################################


LWIP_APPS_HTTPD_SOURCE :=
LWIP_APPS_HTTPD_SOURCE += fs.c
LWIP_APPS_HTTPD_SOURCE += fsdata.c
LWIP_APPS_HTTPD_SOURCE += httpd.c


EXTRAINCDIRS += $(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/apps \
$(TOP)/library/STM32F4/Middlewares/Third_Party/LwIP/src/apps/httpd

C_SOURCES += $(LWIP_APPS_HTTPD_SOURCE)

