#ifndef _6502EMU_MEMORY_H_
#define _6502EMU_MEMORY_H_

/**
 * @brief 6502 Memory
 * 
 * Represents the memory of the 6502 CPU.
 */
typedef struct _memory_6502_t
{
    uint8_t* data;  // Pointer to the raw memory data
    uint16_t size;  // Size of the memory
} memory_6502_t;

/**
 * @brief Initialize 6502 Memory
 * 
 * @param memory Pointer to the memory to initialize
 * @param size Size of the memory to initialize
 * 
 * @return EMU_RES_OK if the memory was initialized successfully
*/
emu_e_result_t memory_6502_init(memory_6502_t *memory, uint16_t size);

/**
 * @brief Free 6502 Memory
 * 
 * @param memory Pointer to the memory to free
 * 
 * @return EMU_RES_OK if the memory was freed successfully
*/
emu_e_result_t memory_6502_free(memory_6502_t *memory);

/**
 * @brief Read a byte from 6502 Memory
 * 
 * @param memory Pointer to the memory to read from
 * @param address Address to read from
 * @param data Pointer to the data to read into
 * 
 * @return EMU_RES_OK if the byte was read successfully
*/
emu_e_result_t memory_6502_read(memory_6502_t *memory, uint16_t address, uint8_t *data);

/**
 * @brief Write a byte to 6502 Memory
 * 
 * @param memory Pointer to the memory to write to
 * @param address Address to write to
 * @param data Data to write
 * 
 * @return EMU_RES_OK if the byte was written successfully
*/
emu_e_result_t memory_6502_write(memory_6502_t *memory, uint16_t address, uint8_t data);

/**
 * @brief Read a word from 6502 Memory
 * 
 * @param memory Pointer to the memory to read from
 * @param address Address to read from
 * @param data Pointer to the data to read into
 * 
 * @return EMU_RES_OK if the word was read successfully
*/
emu_e_result_t memory_6502_read_word(memory_6502_t *memory, uint16_t address, uint16_t *data);

/**
 * @brief Write a word to 6502 Memory
 * 
 * @param memory Pointer to the memory to write to
 * @param address Address to write to
 * @param data Data to write
 * 
 * @return EMU_RES_OK if the word was written successfully
*/
emu_e_result_t memory_6502_write_word(memory_6502_t *memory, uint16_t address, uint16_t data);

#endif // _6502EMU_MEMORY_H_