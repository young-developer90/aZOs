CC = x86_64-elf-gcc
CPP = x86_64-elf-g++
AS = x86_64-elf-as
LD = x86_64-elf-ld

CFLAGS = -m64 -ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti -nostdlib -Iinclude
CPPFLAGS = $(CFLAGS) -fno-use-cxa-atexit
LDFLAGS = -T linker.ld -nostdlib -z max-page-size=0x1000

OBJS = boot/boot.o kernel/kernel.o kernel/vga.o

all: aZOs.iso

boot/boot.o: boot/boot.asm
	$(AS) $< -o $@

kernel/%.o: kernel/%.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

aZOs.bin: $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

aZOs.iso: aZOs.bin
	mkdir -p iso/boot/grub
	cp aZOs.bin iso/boot/
	cp boot/grub.cfg iso/boot/grub/
	grub-mkrescue -o $@ iso 2>/dev/null || echo "Install grub-mkrescue"

clean:
	rm -rf *.o */*.o aZOs.bin aZOs.iso iso