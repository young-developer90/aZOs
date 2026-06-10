#pragma once
#include <stdint.h>

namespace VGA {
    void clear();
    void print(const char* str, uint8_t color = 0x07);
    void putchar(char c, uint8_t color = 0x07);
}