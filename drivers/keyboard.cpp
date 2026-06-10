#include "keyboard.h"
#include "../include/vga.h"

static bool keys[128];

void Keyboard::init() {
    // TODO: Proper PIC and IDT setup needed for real interrupts
    VGA::print("Keyboard driver initialized (stub)\n", 0x0A);
}

char Keyboard::get_key() {
    // Stub - in real impl use port 0x60
    return 'A'; // placeholder
}

bool Keyboard::is_key_pressed() {
    return false; // stub
}
