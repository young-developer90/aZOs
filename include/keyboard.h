#pragma once
#include <stdint.h>

namespace Keyboard {
    void init();
    char get_key();
    bool is_key_pressed();
}
