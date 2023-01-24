#include "mem.h"

void memory_copy(char* src, char* dst, unsigned int size)
{
    for(int i = 0; i < size; i++)
    {
        dst[i] = src[i];
    }
}

void memory_set(uint8_t* dst, uint8_t val, uint32_t len)
{
    uint8_t* tmp = dst;
    
    while(len != 0)
    {
        *(tmp++) = val;
        len--;
    }
}

uint32_t free_mem_addr = 0x10000;

uint32_t kmalloc(size_t size, int align, uint32_t* phys_addr)
{
    if(align == 1 && (free_mem_addr & 0xFFFFF000))
    {
        free_mem_addr &= 0xFFFFF000;
        free_mem_addr += 0x1000;
    }

    if(phys_addr)
    {
        phys_addr = free_mem_addr;
    }

    uint32_t ret = free_mem_addr;
    free_mem_addr += size;

    return ret;
}