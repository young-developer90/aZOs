#include "vga.h"

static const uint16_t* VGA_BUFFER = (uint16_t*)0xB8000;
static uint16_t* vga_buffer = const_cast<uint16_t*>(VGA_BUFFER);
static int cursor_x = 0;
static int cursor_y = 0;

void VGA::clear() {
    for (int i = 0; i < 80 * 25; ++i) {
        vga_buffer[i] = 0x0720;
    }
    cursor_x = cursor_y = 0;
}

void VGA::putchar(char c, uint8_t color) {
    if (c == '\n') {
        cursor_x = 0;
        ++cursor_y;
    } else {
        vga_buffer[cursor_y * 80 + cursor_x] = static_cast<uint16_t>(c) | (static_cast<uint16_t>(color) << 8);
        ++cursor_x;
    }
    if (cursor_x >= 80) {
        cursor_x = 0;
        ++cursor_y;
    }
    if (cursor_y >= 25) {
        for (int i = 0; i < 24*80; ++i) vga_buffer[i] = vga_buffer[i+80];
        for (int i = 24*80; i < 25*80; ++i) vga_buffer[i] = 0x0720;
        cursor_y = 24;
    }
}

void VGA::print(const char* str, uint8_t color) {
    while (*str) {
        putchar(*str++, color);
    }
}