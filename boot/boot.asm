; Multiboot2 header
section .multiboot
align 8
header_start:
    dd 0xE85250D6
    dd 0
    dd header_end - header_start
    dd 0x100000000 - (0xE85250D6 + 0 + (header_end - header_start))
    dw 0, 0, 8
header_end:

section .text
global start
extern kmain
start:
    mov rsp, stack_top
    call kmain
    hlt

section .bss
align 16
stack_bottom:
    resb 16384
stack_top: