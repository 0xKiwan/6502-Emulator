#ifndef _6502EMU_CPU_H_
#define _6502EMU_CPU_H_


/**
 * @brief 6502 CPU Status Register
 */
typedef struct _cpu_6502_t_status_register
{
    uint8_t     c : 1;  // Carry Flag
    uint8_t     z : 1;  // Zero Flag
    uint8_t     i : 1;  // Interrupt Disable
    uint8_t     d : 1;  // Decimal Mode (unused in this implementation)
    uint8_t     b : 1;  // Break Command
    uint8_t     u : 1;  // Unused
    uint8_t     v : 1;  // Overflow Flag
    uint8_t     n : 1;  // Negative Flag
} cpu_6502_t_status_register;

/**
 * @brief 6502 CPU
 * 
 * The 6502 CPU is a 8-bit CPU with a 16-bit address bus.
 * 
*/
typedef struct _cpu_6502_t
{
    uint16_t pc;                    // Program Counter
    uint8_t sp;                     // Stack Pointer
    uint8_t a;                      // Accumulator
    uint8_t x;                      // X Register
    uint8_t y;                      // Y Register
    cpu_6502_t_status_register sr;  // Status Register
    memory_6502_t *memory;          // Pointer to the memory
} cpu_6502_t;

/**
 * @brief Initializes the 6502 CPU
 * 
 * @param cpu Pointer to the 6502 CPU
 * 
 * @return EMU_RES_OK if successful
*/
emu_e_result_t cpu_6502_init(cpu_6502_t *cpu);





#endif // _6502EMU_CPU_H_