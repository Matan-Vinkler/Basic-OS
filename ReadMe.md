##### This is my basic OS Project!

**Required softwares:**
1. Cross GCC Compiler `i686-elf-gcc` (if your prefix is "i386", change that in the MakeFile)
2. Cross Binutils `i686-elf-ld` (if your prefix is "i386", change that in the MakeFile)
3. NASM
4. QEMU `qemu-system-i386`
4. GDB (for debugging)

**How to Run this program:**
1. To compile and run the OS, type `make run`.
2. To compile and debug the OS, type `make debug`.
3. To clean the directory and delete all the binary files, type `make clean`.

**Usage:**
When you type `make run` or `make debug`, the system will boot from scratch a small terminal will be opened.

Type something, it will go through the kernel
Type `END` to halt the CPU or `PAGE` to request a kmalloc()