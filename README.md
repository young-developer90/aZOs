# aZOs - Advanced Zenith Operating System

![aZOs Logo](https://github.com/young-developer90/aZOs/raw/main/logo.png)

**یک سیستم عامل x86_64 واقعی از صفر**، نوشته شده با C++، Assembly.  
بوت می‌کنه روی QEMU و سخت‌افزار واقعی از طریق GRUB2 + Multiboot2.

## ویژگی‌ها
- 64-bit Long Mode
- VGA Text Mode با رنگ و splash logo
- Keyboard Interrupt کامل (IRQ1)
- Heap Allocator (kmalloc/kfree)
- Paging پایه
- AZFS فایل‌سیستم persistent روی ATA disk
- AzShell کامل با parser و دستورات
- ATA PIO Driver برای ذخیره دائمی
- IDT + PIC + Exception handlers
- Minimal libc (printf, string funcs و ...)
- Monolithic Kernel

## ساختار پروژه
```
aZOs/
├── boot/
├── kernel/
├── drivers/
├── fs/
├── shell/
├── memory/
├── include/
├── linker.ld
├── Makefile
├── grub.cfg
├── README.md
└── logo.png (optional)
```

## ساخت و اجرا

### پیش‌نیازها
```bash
sudo apt update
sudo apt install build-essential nasm qemu-system-x86 grub-common xorriso mtools
```

### Clone و Build
```bash
git clone https://github.com/young-developer90/aZOs.git
cd aZOs
make clean && make
```

### اجرا در QEMU (با دیسک persistent)
```bash
qemu-system-x86_64 -cdrom aZOs.iso -drive file=disk.img,format=raw,if=ide,index=0 -enable-kvm -m 512M
```

## دستورات AzShell
```
help    clear    echo    uname    about    version
time    reboot   ls      pwd      mkdir    cd
touch   rm       cat     write    append   meminfo
cpuinfo date     hello   calc
```

**مثال استفاده:**
```
touch notes.txt
write "Welcome to aZOs!" notes.txt
append "Persistent storage works!" notes.txt
cat notes.txt
reboot
```

(بعد reboot فایل‌ها هنوز هستن)


## وضعیت
- ✅ Boot + VGA + Keyboard + Persistent FS + Shell
- 🔄 Scheduler, Virtual Terminals, Advanced Paging در حال توسعه

**داداش اگه فیچر جدید بخوای بگو فوری اضافه می‌کنم.**

Made for fun and learning OSDev 🚀