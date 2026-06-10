#include "vga.h"
#include "../include/heap.h"
#include "../include/keyboard.h"

extern "C" void kmain() {
    VGA::clear();
    VGA::print("====================================\n", 0x0B);
    VGA::print("          aZOs\n", 0x0A);
    VGA::print("Advanced Zenith Operating System\n", 0x0F);
    VGA::print("             Version 0.1\n", 0x0C);
    VGA::print("====================================\n\n", 0x0B);
    VGA::print("Booting in x86_64 long mode...\n", 0x07);
    VGA::print("Kernel loaded successfully!\n", 0x0A);

    Memory::init_heap();
    Keyboard::init();

    VGA::print("Heap and Keyboard drivers ready!\n", 0x0A);
    VGA::print("Press any key... (basic VGA only for now)\n", 0x0F);

    while (true) {
        asm volatile("hlt");
    }
}
