
DEBUGER:= JLINK
JLINK_PATH := $(PRO_DIR)/tool/JLINK/JLink.exe
TARGET_DEVICE := STM32F407VG
INTERFACE := SWD
SPEED := 4000
FLASH_ADDRESS := 0x08000000

SRC_DIRS += $(PRO_DIR)/driver/gpio/source \
						$(PRO_DIR)/user/source \
						$(PRO_DIR)/startup

INC_DIRS += $(PRO_DIR)/driver/gpio/include \
						$(PRO_DIR)/driver/uart/include \
						$(PRO_DIR)/driver \
						$(PRO_DIR)/user/include
