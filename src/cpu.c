#include "../inc/shared.h"
#include "../inc/result.h"
#include "../inc/memory.h"
#include "../inc/cpu.h"

// Implementation for 'cpu.h' cpu_6502_init
emu_e_result_t cpu_6502_init(cpu_6502_t *cpu)
{
    // Initialize registers
    cpu->a  = cpu->x = cpu->y = 0x00;
    cpu->sp = 0x0100;
    cpu->pc = 0xfffc;

    // Initialize status register
    cpu->sr.c = cpu->sr.b = cpu->sr.d = cpu->sr.i = cpu->sr.v = cpu->sr.z = cpu->sr.n = 0;

    // Initialize memory
    return memory_6502_init(cpu->memory, 1024 * 64);
}

// Implementation for 'cpu.h' cpu_6502_reset
emu_e_result_t cpu_6502_reset(cpu_6502_t *cpu)
{
    // Free memory if it was allocated
    if (cpu->memory != NULL) memory_6502_free(cpu->memory);

    // We could just call init again.
    return cpu_6502_init(cpu);
}

// Implementation for 'cpu.h' cpu_6502_fetch_decode
emu_e_result_t cpu_6502_fetch_decode(cpu_6502_t *cpu, uint8_t* opcode, uint8_t* operand)
{
    // Will store the opcode
    uint8_t opcode = 0;

    // Read the opcode
    emu_e_result_t status = memory_6502_read(cpu->memory, cpu->pc, &opcode);

    // Check if the read was successful
    if (status != EMU_RES_OK) return status;

    // Increment the program counter
    cpu->pc++;

    return EMU_RES_OK;
}