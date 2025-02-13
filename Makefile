###########################################################
# GCC template makefile
###########################################################

# makefile folder path setting
TOP = .

# embedded project version setting 
VERSION = 0
PATCHVERSION = 0
SUBVERSION = 1
EXTRAVERSION = 
# project name setting
PROJECT_NAME = embeddedProject
# Build name 
TARGET = $(PROJECT_NAME)

# include makefile
-include $(TOP)/Inc.mk
# project full version variable
CUSTOMVERSION = v$(VERSION)$(if $(PATCHVERSION),.$(PATCHVERSION)$(if $(SUBVERSION),.$(SUBVERSION)))$(if $(EXTRAVERSION),-$(EXTRAVERSION))

# get host os 
HOSTOS := $(shell uname -s | tr '[:upper:]' '[:lower:]' | \
	    sed -e 's/\(cygwin\).*/cygwin/')

export HOSTOS


# source file all setting 
# source file %.c
SRCS += $(C_SOURCES)
# source file %.cpp
CPPSRCS += $(CPP_SOURCES)
# assmebler source file add
ASM_SOURCES =

# sub folder setting
SUB_DIRS :=
# core start up code 
SUB_DIRS += CMSIS
# lecture code sample folder
SUB_DIRS += StudyCode
# driver code
SUB_DIRS += driver

# SUB_DIR addprefix Setting
SUB_DIRS := $(addprefix $(TOP)/,$(SUB_DIRS))

# Source File add compling
vpath %.c $(SUB_DIRS)
vpath %.s $(SUB_DIRS)
vpath %.cpp $(SUB_DIRS)

sinclude $(addsuffix /Makefile, $(SUB_DIRS))

# float printf add libs nano.spec
# linker lib add float library add -spec=nano.spec -u_printf_float not use system file syscall file _write _read _getpid _close
LD_LIBS = -lc -lm -lnosys -specs=nano.specs -u _printf_float -u _scanf_float -static
# Linker script add setting
LDFLAGS = $(MCU) $(LD_LIBS) -Wl,-Map=$(OUT_DIR)/$(TARGET).map,--cref -Wl,--gc-sections
# LIBC_LIB = -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-file-name=libc.a`) -lc
# MATH_LIB = -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-file-name=libm.a`) -lm
# LIBGCC_LIB += -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-libgcc-file-name`) -lgcc
# CPLUSPLUS_LIB = -lstdc++
LDFLAGS += $(patsubst %,-L%, $(EXTRA_LIBDIRS))
LDFLAGS += $(patsubst %,-L%, $(EXTRA_LIBS))
# Flash Linker Script add Setting
LDFLAGS += -T$(FLASH_LDSCRIPT)


all: project-version compiler-version build elf-size


# Build Command Do
build: clean createdirs elf bin lss sym elf-size

# project version make command
project-version:
	@(echo $(PROJECT_NAME) $(CUSTOMVERSION))

link-source:
	@echo "Include Folder list -> $(SUB_DIRS)"
	@echo "link source Files -> $(SRCS)"
	@echo "Assembler Source Files -> $(ASM_SOURCES)"
	@echo "Include Header Files -> $(EXTRAINCDIRS)"


# common make command
menuconfig: project-version
	@$(MAKE) -f scripts/Makefile $@

distclean: 
	$(REMOVE_CMD) $(OUT_DIR)
	$(REMOVE_CMD) $(BUILD_DIR)
	$(REMOVE_CMD) $(LIB_DIR)
	$(REMOVE_CMD) build $(TOP)/include .config .config.old
	@$(MAKE) -f scripts/Makefile clean


# Help Command explain
help:
	@echo "----$(PROJECT_NAME) $(CUSTOMVERSION)--- "
	@echo menuconfig - "GUI Config Sample Code, Select Board "
	@echo distclean - "All Object File, Folder Delete"
	@echo clean - "Folder Delete"
	@echo project-version - "Show this project Version"
	@echo link-source - "Get Inlclude Folder and Source File"
	@echo elf-size - "Get Binaray File Size"
	@echo compiler-version - "Get arm-none-eabi-gcc version Check"
	@echo createdirs - "Make Object, Binary, hex file In Folder Name"	
	@$(MAKE) -f scripts/Makefile help

lss: $(BUILD_DIR)/$(TARGET).lss
bin: $(BUILD_DIR)/$(TARGET).bin
sym: $(BUILD_DIR)/$(TARGET).sym


# include makefile rule file
include  $(TOP)/rule.mk
