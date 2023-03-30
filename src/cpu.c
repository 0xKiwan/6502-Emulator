#include "../inc/shared.h"
#include "../inc/result.h"
#include "../inc/memory.h"
#include "../inc/cpu.h"

// Implementation for 'cpu.h' cpu_6502_init
emu_e_result_t cpu_6502_init(cpu_6502_t *cpu)
{
    // Initialize registers
    cpu->a  = cpu->x = cpu->y = 0x00;
    cpu->sp = 0xff;
    cpu->pc = 0x0000;

    // Initialize status register
    cpu->sr.c = cpu->sr.b = cpu->sr.d = cpu->sr.i = cpu->sr.v = cpu->sr.z = cpu->sr.n = 0;

    // Initialize memory
    return memory_6502_init(cpu->memory, 1024 * 64);
}