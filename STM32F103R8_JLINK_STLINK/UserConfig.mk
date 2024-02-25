
PROJ_NAME := main
PRO_DIR := .
PATH_OUTPUT := $(PRO_DIR)/output

LINKER_FILE := STM32F103R8TX_LINKER.ld
PATH_LINKER := $(PRO_DIR)/linker/$(LINKER_FILE)

COMPILER_DIR := C:/GCC_ARM
# JLINK or STLINK
DEBUGER := STLINK

ifeq ($(DEBUGER),STLINK)
PATH_STLINK := $(PRO_DIR)/tool/ST-LINKutility/ST-LINK_CLI.exe
endif

ifeq ($(DEBUGER),JLINK)
# SWD or JTAG
INTERFACE := SWD  
JLINK_PATH := $(PRO_DIR)/tool/JLINK/JLink.exe
endif

TARGET_DEVICE := STM32F103R8
SPEED := 4000
FLASH_ADDRESS := 0x08000000

SRC_DIRS += $(PRO_DIR)/driver/gpio/source \
						$(PRO_DIR)/startup \
						$(PRO_DIR)/user/source \

INC_DIRS += $(PRO_DIR)/driver/gpio/include \
						$(PRO_DIR)/user/include

