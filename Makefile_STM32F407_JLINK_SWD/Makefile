
PROJ_NAME := main
PRO_DIR := .
PATH_OUTPUT := $(PRO_DIR)/output
LINKER_FILE := $(PRO_DIR)/linker/stm32f407_linker.ld

COMPILER_DIR 	:= C:/GCC_ARM

CC := $(COMPILER_DIR)/bin/arm-none-eabi-gcc
LD := $(COMPILER_DIR)/bin/arm-none-eabi-ld

include UserConfig.mk

SRC_FILES := $(foreach SRC_DIRS,$(SRC_DIRS),$(wildcard $(SRC_DIRS)/*))
INC_FILES := $(foreach INC_DIRS,$(INC_DIRS),$(wildcard $(INC_DIRS)/*))			

INC_DIRS_OPT := $(foreach INC_DIRS,$(INC_DIRS),-I$(INC_DIRS))

CC_OPT := -mcpu=cortex-m4 -c -O0 -g -mthumb $(INC_DIRS_OPT)
LD_OPT := -T $(LINKER_FILE) -Map $(PATH_OUTPUT)/$(PROJ_NAME).map

OJB_FILES  := $(notdir $(SRC_FILES))
OJB_FILES  := $(subst .c,.o,$(OJB_FILES))
PATH_OJBS  := $(foreach OJB_FILES,$(OJB_FILES),$(PATH_OUTPUT)/$(OJB_FILES))

vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)

.PHONY: build
build: $(OJB_FILES) $(LINKER_FILE)
	$(LD) $(LD_OPT) $(PATH_OJBS) -o $(PATH_OUTPUT)/$(PROJ_NAME).elf
	$(COMPILER_DIR)/arm-none-eabi/bin/objcopy.exe -O ihex $(PATH_OUTPUT)/$(PROJ_NAME).elf $(PATH_OUTPUT)/$(PROJ_NAME).hex
	$(COMPILER_DIR)/arm-none-eabi/bin/objcopy.exe -O binary $(PATH_OUTPUT)/$(PROJ_NAME).elf $(PATH_OUTPUT)/$(PROJ_NAME).bin
	size $(PATH_OUTPUT)/$(PROJ_NAME).elf
	size $(PATH_OUTPUT)/$(PROJ_NAME).hex
	
	@echo "================================================="
	@echo "                BUILD DONE !!!                   "
	@echo "================================================="

%.o: %.c $(INC_FILES)
	$(CC) $(CC_OPT) -c $< -o $(PATH_OUTPUT)/$@

.PHONY: run
run:
	@ touch jlink.script
	@echo device $(TARGET_DEVICE) > jlink.script
	@echo SelectInterface $(INTERFACE) >> jlink.script
	@echo speed $(SPEED) >> jlink.script
	@echo r >> jlink.script
	@echo erase >> jlink.script
	@echo loadfile $(PATH_OUTPUT)/$(PROJ_NAME).hex $(FLASH_ADDRESS) >> jlink.script
	@echo r >> jlink.script
	@echo g >> jlink.script
	@echo exit >> jlink.script

	$(JLINK_PATH) -CommanderScript jlink.script

	@echo "================================================="
	@echo "             FLASH DOWNLOAD OK!!!                "
	@echo "================================================="

.PHONY: clean 
clean:
	@rm ./$(PATH_OUTPUT)/*

.PHONY: print
print-%:
	@echo $($(subst print-,,$@))
