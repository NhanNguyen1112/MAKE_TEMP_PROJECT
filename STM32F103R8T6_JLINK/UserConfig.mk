
PROJ_NAME := main
PRO_DIR := .
PATH_OUTPUT := $(PRO_DIR)/output

COMPILER_DIR := C:/GCC_ARM
DEBUGER := JLINK

# SWD or JTAG
INTERFACE := SWD 

JLINK_PATH := $(PRO_DIR)/tool/JLINK/JLink.exe
TARGET_DEVICE := STM32F103R8
SPEED := 4000
FLASH_ADDRESS := 0x08000000

SRC_DIRS += $(PRO_DIR)/driver/gpio/source \
						$(PRO_DIR)/startup \
						$(PRO_DIR)/user/source \

INC_DIRS += $(PRO_DIR)/driver/gpio/include \
						$(PRO_DIR)/user/include

