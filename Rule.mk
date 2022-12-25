###########################################################
# GCC template makefile
###########################################################




ifndef COMPILER_PREFIX
$(error PREFIX is not defined. Plese include 'ink.mk' or PREFIX checking first exampl "gcc-path not include")
endif


#Assembler code complie flag 
ALL_ASMFLAGS = $(MCU) -I. -x assembler-with-cpp $(ASFLAGS)
# Add target proccessor to flags.
ALL_CFLAGS = $(MCU) -I. $(CFLAGS)

AOBJS = $(addprefix $(OUT_DIR)/, $(ASM_SOURCES:.s=.o))
COBJS = $(addprefix $(OUT_DIR)/, $(C_SOURCES:.c=.o))
CPPOBJS = $(addprefix $(OUT_DIR)/, $(CPP_SOURCES:.cpp=.o))

#hex file size
HEXSIZE = $(SIZE) --target=$(FORMAT) $(TARGET).hex
#bin file size
ELFSIZE = $(SIZE) -A $(BUILD_DIR)/$(TARGET).elf

#get Size info
elf-size:
	$(ELFSIZE)

# gcc version 
compiler-version:
	@$(CC) --version


# create dirs
createdirs:
	@echo create buid directory $(OUT_DIR)
	@echo build bin file in $(BUILD_DIR)
	@echo include Object file in $(LIB_DIR)
	$(shell mkdir $(OUT_DIR) $(BUILD_DIR) $(LIB_DIR))

# $* <- 확장자가 없는 현재의 목표 파일(Target)
# $@ <- 현재의 목표 파일(Target)
# $< <- 현재의 목표 파일(Target)보다 더 최근에 갱신된 파일 이름
# $? <- 현재의 목표 파일(Target)보다 더 최근에 갱신된 파일이름
# $^: 현재 Target이 의존하는 대상들의 전체 목록

# create hex file make command
%.hex: %.elf
	$(OBJCOPY) -O $(FORMAT) $< $@

# create binary file make command
%.bin: %.elf
	$(OBJCOPY) -O $(FORMAT) $< $@

# Create extended listing file from ELF output file.
# testing: option -C
%.lss: %.elf
	$(OBJDUMP) -h -S -C $< > $@

#create a symbol table from elf output file 
%.sym: %.elf
	$(NM) -n $< > $@

# Link: create ELF output file from object files.
#.SECONDARY가 의존하는 타겟들은 중간 파일들로 취급된다. 
#단 그들은 자동으로 삭제되지 않는다. See section 묵시적 규칙의 연쇄(Chains of Implicit Rules). 
#종속물이 없는 .SECONDARY는 makefile에서 언급된 모든 타겟을 secondary로 마킹한다.
.SECONDARY: $(BUILD_DIR)/$(TARGET).elf

#.PRECIOUS가 의존하는 타겟들은 다음과 같은 특별한 취급을 받는다: 
#make가 명령 실행 중에 죽거나 인터럽트를 받으면, 그 타겟은 삭제되지 않는다. 
#See section make를 인터럽트 또는 죽이기(Interrupting or Killing make). 
#또한, 그 타겟이 중간 파일이라면, 더이상 필요하지 않을 때, 일반적인 경우처럼, 삭제되지 않을 것이다. 
#See section 묵시적 규칙의 연쇄(Chains of Implicit Rules). 여러분은 또한 묵시적 규칙의 타겟 패턴(`%.o'와 같은)을 특별한 타겟
# .PRECIOUS의 종속 파일로 지정해서 그 파일의 이름과 매치하는 타겟 패턴 매치의 규칙ㅇ 의해서 생성된 중간 파일들을 보존할 수 있다.
.PRECIOUS: $(AOBJS) $(COBJS) $(CPPOBJS)

#make elf file.
%.elf: $(AOBJS) $(COBJS) $(CPPOBJS) $(PRJ_LIBS)
	$(CC) $(ALL_CFLAGS) $^ --output $@ $(LDFLAGS)

#Make C object file 
$(COBJS):$(OUT_DIR)/%.o : %.c
	$(CC) -c $(ALL_CFLAGS) $(CONLYFLAGS) $< -o $@

#Make Cpp object file
$(CPPOBJS):$(OUT_DIR)/%.o : %.cpp
	$(CPP) -c $(ALL_CFLAGS) $(CPOONLYFLAGS) $< -o $@

# Compile: create assembler files from C source files. ARM/Thumb
## does not work - TODO - hints welcome
##$(COBJ) : %.S : %.c
##	$(CC) -S $(ALL_CFLAGS) $< -o $@

# Assemble: create object files from assembler source files. ARM/Thumb
$(AOBJS):$(OUT_DIR)/%.o : %.s
	$(CC) -c $(ALL_CFLAGS) $< -o $@

#Remove Options
clean:
	$(REMOVE_CMD) $(OUT_DIR)
	$(REMOVE_CMD) $(BUILD_DIR)
	$(REMOVE_CMD) $(LIB_DIR)


# list of hphony target
.PHONY : all finish end elf-size projectversion compiler-version createdirs build elf hex bin lss sym clean