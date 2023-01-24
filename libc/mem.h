#ifndef MEM_H
#define MEM_H

#include "../cpu/type.h"
#include <stddef.h>

void memory_copy(char* src, char* dst, unsigned int size);
void memory_set(uint8_t* dst, uint8_t val, uint32_t len);

uint32_t kmalloc(size_t size, int align, uint32_t* phys_addr);

#endif