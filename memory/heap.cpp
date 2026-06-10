#include "heap.h"
#include "../include/vga.h"

static uint8_t heap[1024 * 1024]; // 1MB heap for start
static size_t heap_used = 0;

void Memory::init_heap() {
    heap_used = 0;
    VGA::print("Heap initialized (1MB)\n", 0x0A);
}

void* Memory::kmalloc(size_t size) {
    if (heap_used + size > sizeof(heap)) return nullptr;
    void* ptr = &heap[heap_used];
    heap_used += size;
    return ptr;
}

void Memory::kfree(void* ptr) {
    // Simple bump allocator - no free for now
    (void)ptr;
}
