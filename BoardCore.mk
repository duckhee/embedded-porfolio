###########################################################
# GCC template makefile
###########################################################

# include makefile 
-include $(TOP)/Inc.mk

# include linkber script select makefile
-include $(TOP)/Linker.mk

# shell if 

ifeq ($(CONFIG_MANGO_M3), y)
CPU = $(M3_CPU)
FLOAT-ABI = 
C_DEFS = \
-D STM32F103xB \
-D BOARD_DEF_MANGO_M32 

else ifeq ($(CONFIG_MANGO_Z1), y)
CPU = $(M3_CPU)
FPU = 
FLOAT-ABI = 
C_DEFS = \
-D STM32F103xB 

else ifeq ($(CONFIG_MANGO_M32F2), y)

CPU = $(M3_CPU)
FPU = 
FLOAT-ABI = 
C_DEFS = \
-D SMT32F103xB \

else ifeq ($(CONFIG_MANGO_M4), y)

CPU = $(M4_CPU)
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=hard
C_DEFS = \
-D STM32F407xx \
-D STM32F40_41xxx

else ifeq ($(CONFIG_EDU_BOARD), y)

CPU = $(M4_CPU)
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=hard
C_DEFS = \
-D STM32F407xx

else ifeq ($(CONFIG_ARCH_M3), y)

CPU = $(M3_CPU)
FPU = 
FLOAT-ABI = 

else ifeq ($(CONFIG_ARCH_M4), y)

CPU = $(M4_CPU)
FPU = -mfpu=fpv4-sp-d16
FLOAT-ABI = -mfloat-abi=hard

endif
