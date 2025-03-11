# Compiler and Linker
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld

# Compilation Flags
CFLAGS = -mcpu=cortex-m3 -mthumb -Wall -g
LDFLAGS = -T stm32f103.ld

# Source and Object Files
SRC = hal_temperature.c hal_fan.c smart_cooling.c main.c
OBJ = $(SRC:.c=.o)

# Build Target
all: build/firmware.elf

# Compile C files into Object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link Object Files into Firmware
build/firmware.elf: $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $(OBJ)

# Clean Build Files
clean:
	rm -f *.o build/firmware.elf
