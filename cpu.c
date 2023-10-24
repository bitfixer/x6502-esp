#include "cpu.h"
#include <stdlib.h>
#include <string.h>

cpu * new_cpu(uint16_t pc_start, uint8_t* cpu_ram) {
    cpu* m = malloc(sizeof(cpu));
    m->pc = pc_start;
    m->sr = FLAG_INTERRUPT;
    m->sp = 0xFF;
    m->interrupt_waiting = 0x00;
    m->mem = cpu_ram;
    memset(m->mem, 0xFF, MEMORY_SIZE);
    return m;
}
