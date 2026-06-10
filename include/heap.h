#pragma once
#include <stddef.h>
#include <stdint.h>

namespace Memory {
    void init_heap();
    void* kmalloc(size_t size);
    void kfree(void* ptr);
}
