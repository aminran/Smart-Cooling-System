# Compiler and Linker
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
CFLAGS = -mcpu=cortex-m3 -mthumb -Wall -O2
LDFLAGS = -T stm32f103.ld

# Directories
SRC = src
BUILD = build
INCLUDE = include

# Source and Object Files
SRCS = $(wildcard $(SRC)/*.c)
OBJS = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

# Output Binary
TARGET = $(BUILD)/firmware.elf

# Compilation Rules
all: $(TARGET)

$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $^ -o $@
	$(OBJCOPY) -O ihex $(TARGET) $(BUILD)/firmware.hex

# Clean Build Artifacts
clean:
	rm -rf $(BUILD)

# Flashing to MCU (Example using OpenOCD)
flash: all
	openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c "program $(TARGET) verify reset exit"
