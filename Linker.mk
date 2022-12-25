###########################################################
# GCC template makefile
###########################################################

# LIBC_LIB = -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-file-name=libc.a`) -lc
# MATH_LIB = -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-file-name=libm.a`) -lm
# LIBGCC_LIB += -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-libgcc-file-name`) -lgcc
# CPLUSPLUS_LIB = -lstdc++

# Linker flags.
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
# LDFLAGS = -Map=$(TARGET).map --cref
# Linker script flash
ifeq ($(CONFIG_MANGO_M3), y)
# Flash LinkerScript setting
FLASH_LDSCRIPT = LinkerScripts/stm32f10x/STM32F103RBTx_FLASH.ld

else ifeq ($(CONFIG_MANGO_Z1), y)
# Flash LinkerScript setting
FLASH_LDSCRIPT = LinkerScripts/stm32f10x/STM32F103RBTx_FLASH.ld

else ifeq ($(CONFIG_MANGO_M4), y)
# Flash LinkerScript setting
FLASH_LDSCRIPT = LinkerScripts/stm32f407/STM32F407ZETx_FLASH.ld

else ifeq ($(CONFIG_MANGO_M32F2), y)
FLASH_LDSCRIPT =
else ifeq ($(CONFIG_EDU_BOARD), y)
# Flash LinkerScript setting
FLASH_LDSCRIPT = LinkerScripts/stm32f407/STM32F407VE_FLASH.ld

else ifeq ($(CONFIG_ARCH_M3), y)
FLASH_LDSCRIPT = LinkerScripts/stm32f10x/STM32F103RBTx_FLASH.ld

else ifeq ($(CONFIG_ARCH_M4), y)
FLASH_LDSCRIPT = LinkerScripts/stm32f407/STM32F407VE_FLASH.ld

endif
