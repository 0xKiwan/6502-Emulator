#ifndef _6502EMU_RESULT_H_
#define _6502EMU_RESULT_H_

// Represents a result for a given function.
typedef enum _emu_e_result_t
{
    EMU_RES_OK,
    EMU_RES_FAIL,
    EMU_RES_READ_OUT_OF_BOUNDS,
    EMU_RES_WRITE_OUT_OF_BOUNDS,
    EMU_RES_MEMORY_ALLOC_FAIL

} emu_e_result_t;

#endif // _6502EMU_RESULT_H_