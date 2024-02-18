
PATH_STLINK := $(PRO_DIR)/tool/ST-LINKutility/ST-LINK_CLI.exe
FLASH_ADDRESS := 0x08000000

SRC_DIRS += $(PRO_DIR)/driver/gpio/source \
						$(PRO_DIR)/user/source \
						$(PRO_DIR)/startup

INC_DIRS += $(PRO_DIR)/driver/gpio/include \
						$(PRO_DIR)/driver/uart/include \
						$(PRO_DIR)/driver \
						$(PRO_DIR)/user/include
