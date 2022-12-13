# ?= means if ARMGNU is not value it will assign to aarch64-linux-gnu
ARMGNU ?= aarch64-linux-gnu

# -Wall: show all warning
# -nostdlib : don't use C standard lib
# -nostartfiles : don't use startup file
# -ffreestanding : don't use main
COPS = -Wall -nostdlib -nostartfiles -ffreestanding -mgeneral-regs-only
COPS += -Iinclude
COPS += -Idevice_header

ASMOPS = -Iinclude
ASMOPS += -Idevice_header

BUILD_DIR = build
LINK_DIR = linker
ASM_DIR = asm
SRC_DIR = src

all : kernel8.img

clean :
	rm -rf $(BUILD_DIR) *.img

# @D: evaluates to directory from target
# $<: evaluates to first prerequisite
# $@: evaluates to target
$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(ARMGNU)-gcc $(COPS) -MMD -c $< -o $@

$(BUILD_DIR)/%_s.o: $(ASM_DIR)/%.S
	$(ARMGNU)-gcc $(ASMOPS) -MMD -c $< -o $@

C_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_FILES = $(wildcard $(ASM_DIR)/*.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(ASM_DIR)/%.S=$(BUILD_DIR)/%_s.o)

DEP_FILES = $(OBJ_FILES:%.o=%.d)
-include $(DEP_FILES)

kernel8.img: $(LINK_DIR)/linker.ld $(OBJ_FILES)
	$(ARMGNU)-ld -T $(LINK_DIR)/linker.ld -o $(BUILD_DIR)/kernel8.elf  $(OBJ_FILES)
	$(ARMGNU)-objcopy $(BUILD_DIR)/kernel8.elf -O binary kernel8.img