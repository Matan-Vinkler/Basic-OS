#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "kernel.h"
#include "../libc/string.h"
#include "../libc/mem.h"

void kernel_main()
{
    uint8_t enable_debug;

    clear_screen();
    isr_install();
    irq_install();

    kprint("Type something, it will go through the kernel\nType END to halt the CPU or PAGE to request a kmalloc()\n> ");
}

void user_input(char* input)
{
    if(strcmp(input, "END") == 0)
    {
        kprint("Stopping the CPU. Bye!\n");
        asm volatile("hlt");
    }
    else if(strcmp(input, "PAGE") == 0)
    {
        uint32_t phys_addr;
        uint32_t page = kmalloc(1000, 1, &phys_addr);

        char page_str[16] = "", phys_str[16] = "";
        hex_to_ascii(page, page_str);
        hex_to_ascii(phys_addr, phys_str);

        kprint("Page: ");
        kprint(page_str);
        kprint(", Physical Address: ");
        kprint(phys_str);
    }
    else
    {
        kprint("You said: ");
        kprint(input);
    }

    kprint("\n> ");
}