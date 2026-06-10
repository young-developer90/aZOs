// updated kernel with AZFS and shell calls
extern "C" void kmain() {
    // existing
    AZFS::init();
    shell_init();
}