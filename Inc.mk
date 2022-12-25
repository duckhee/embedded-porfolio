###########################################################
# GCC template makefile
###########################################################


MODEL = 
SUBMODEL = 
# output file suffix 
OUTPUT_FOLDER_SUFFIX = build

# gcc prefix setting (cross compiler -> arm-none-eabi-gcc) 
COMPILER_PREFIX = arm-none-eabi-

# remove command
REMOVE_PREFIX = rm
REMOVE_CMD = $(REMOVE_PREFIX) -rf
# shell script using bash
SHELL = sh

# cross compile command setting
CC = $(COMPILER_PREFIX)gcc
CPP = $(COMPILER_PREFIX)g++
AR = $(COMPILER_PREFIX)ar
LD = $(COMPILER_PREFIX)ld
OBJCOPY = $(COMPILER_PREFIX)objcopy
OBJDUMP = $(COMPILER_PREFIX)objdump
SIZE = $(COMPILER_PREFIX)size
NM = $(COMPILER_PREFIX)nm

# Kconfig file add -> setting information include
-include .config

#####################################################################
# CFLAGS
#####################################################################

# default cpu architecture is m3
DEFAULT_CPU = -mcpu=cortex-m3

# architecture M3
M3_CPU = -mcpu=cortex-m3
# architecture M4
M4_CPU = -mcpu=cortex-m4

#####################################################################
# Board Core module setting 
#####################################################################

# default CPU setting
CPU := $(DEFAULT_CPU)

# floating point unit Setting
FPU :=

# Floating ABI Setting
FLOAT-ABI :=

# define setting
C_DEFS :=

# Board Select CPU and Define, FPU, FLOAT-ABI setting
-include $(TOP)/BoardCore.mk

# Micro Controller variable setting
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# output file format setting (using ihex or binary)
## Output format. (can be ihex or binary)
## (binary i.e. for openocd and SAM-BA, hex i.e. for lpc21isp and uVision)
#OUTPUT Format  setting
HEX = ihex
BIN = binary

FORMAT = $(BIN)

# Optimization level, can be [0, 1, 2, 3, s].
# 0 = turn off optimization. s = optimize for size.
# (Note: 3 is not always the best optimization level. See avr-libc FAQ.)
OPT = 0

# Debugging format.
# Native formats for GCC's -g are stabs [default], or dwarf-2.
#DEBUG = stabs
DEBUG = dwarf-2

# driver library setting 
ifeq ($(CONFIG_STANDARD_DRIVER), y)
# driver setting flag 
C_DEFS += \
-D USE_STDPERIPH_DRIVER \

else ifeq ($(CONFIG_HAL_DRIVER), y)
# driver setting flag 
C_DEFS += \
-D USE_HAL_DRIVER \

endif


# asmebler setting
#Place -D or -U options for ASM here
#ADEFS = -D$(RUN_MODE)
#Assembler Define Flag 
ADEFS = 

# comile option common 
COMFILE_COMMON_FLAGS = -Wall -fdata-sections -ffunction-sections

# Compiler flags.
#  -g*:          generate debugging information
#  -O*:          optimization level
#  -f...:        tuning, see GCC manual and avr-libc documentation
#  -Wall...:     warning level
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
#

# Flags for C and C++ (arm-elf-gcc/arm-elf-g++)
CFLAGS = -g$(DEBUG)
CFLAGS += $(C_DEFS) $(C_INCLUDES)
CFLAGS += -O$(OPT)
CFLAGS += -Wcast-align -Wimplicit
CFLAGS += -Wredundant-decls -Wreturn-type -Wshadow -Wunused
CFLAGS += $(COMFILE_COMMON_FLAGS)

# add Include File
CFLAGS += $(patsubst %,-I%,$(EXTRA_INCDIRS))
ASFLAGS = $(COMFILE_COMMON_FLAGS)

# Flags only for C
CONLYFLAGS += -Wnested-externs

# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
CONLYFLAGS += -std=gnu99

# Waring with
CFLAGS += -Wcast-qual
CONLYFLAGS += -Wmissing-prototypes
CONLYFLAGS += -Wstrict-prototypes
CONLYFLAGS += -Wmissing-declarations
#CONLYFLAGS += -Wno-traditional


# Output directory
LIB_DIR := $(TOP)/lib.$(OUTPUT_FOLDER_SUFFIX)
OUT_DIR := $(TOP)/obj.$(OUTPUT_FOLDER_SUFFIX)
BUILD_DIR := $(TOP)/bin.$(OUTPUT_FOLDER_SUFFIX)
PRJ_LIBS := 