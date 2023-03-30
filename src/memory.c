#include "../inc/shared.h"
#include "../inc/result.h"
#include "../inc/memory.h"

// Implementation for 'memory.h' memory_6502_init
emu_e_result_t memory_6502_init(memory_6502_t *memory, uint16_t size)
{
    // Allocate memory
    memory->data = (uint8_t *)malloc(size * sizeof(uint8_t));

    // Check if memory was allocated, if not return fail
    if (memory->data == NULL) return EMU_RES_MEMORY_ALLOC_FAIL;

    // Set size
    memory->size = size;

    // Zero memory
    for (uint16_t i = 0; i < size; i++) memory->data[i] = 0;

    // Return success
    return EMU_RES_OK;
}

// Implementation for 'memory.h' memory_6502_free
emu_e_result_t memory_6502_free(memory_6502_t *memory)
{
    // Free memory
    free(memory->data);

    // Return success
    return EMU_RES_OK;
}

// Implementation for 'memory.h' memory_6502_read
emu_e_result_t memory_6502_read(memory_6502_t *memory, uint16_t address, uint8_t *data)
{
    // Check if address is out of bounds, if so return fail
    if (address >= memory->size) return EMU_RES_READ_OUT_OF_BOUNDS;

    // Read data
    *data = memory->data[address];

    // Return success
    return EMU_RES_OK;
}

// Implementation for 'memory.h' memory_6502_write
emu_e_result_t memory_6502_write(memory_6502_t *memory, uint16_t address, uint8_t data)
{
    // Check if address is out of bounds, if so return fail
    if (address >= memory->size) return EMU_RES_WRITE_OUT_OF_BOUNDS;

    // Write data
    memory->data[address] = data;

    // Return success
    return EMU_RES_OK;
}

// Implementation for 'memory.h' memory_6502_read_word
emu_e_result_t memory_6502_read_word(memory_6502_t *memory, uint16_t address, uint16_t *data)
{
    // Check if address is out of bounds, if so return fail
    if (address >= memory->size) return EMU_RES_READ_OUT_OF_BOUNDS;

    // Read data
    *data = (memory->data[address + 1] << 8) | memory->data[address];

    // Return success
    return EMU_RES_OK;
}

// Implementation for 'memory.h' memory_6502_write_word
emu_e_result_t memory_6502_write_word(memory_6502_t *memory, uint16_t address, uint16_t data)
{
    // Check if address is out of bounds, if so return fail
    if (address >= memory->size) return EMU_RES_WRITE_OUT_OF_BOUNDS;

    // Write data
    memory->data[address] = data & 0xFF;
    memory->data[address + 1] = (data >> 8) & 0xFF;

    // Return success
    return EMU_RES_OK;
}