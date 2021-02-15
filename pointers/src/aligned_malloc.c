#include <stdio.h>
#include <stdlib.h>

#include "pointers.h"



/**
 * @brief Function to malloc data as per the alignment specified in the parameter
 * 
 * @param alignment The alignment number
 * @param size Size of data to be malloced
 * @return void* Pointer to aligned address
 */
void * aligned_malloc(size_t alignment, size_t size)
{

    void *original_address = NULL;
    void *aligned_address = NULL;

    // `sizeof(size_t)` is the space reserved to store the pointer to the original memory address malloced. 
    // This is because we return the aligned memory address to the user and need to keep a track of the original pointer 
    // that will be used to free the allocated address space while using aligned_free.
    // `size` is the requested size to be malloced
    // `alignemnt` is the extra bytes needed to be padded in order to align the data as per the requested `alignment`
    /**
     * Use case: 
     * alignment = 8 bytes, size = 10 bytes, word size i.e (sizeof(size_t)) = 8 bytes
     * malloc returns memory address 102 
     */
    original_address = malloc(size + alignment + sizeof(size_t));
    if (original_address != NULL)
    {
        // A maximum of `alignment` bytes would be wasted if the obtained original_address is already aligned
        // As per different scenarios, extra bytes would be aligned at the start, end or a both

        // Moving ahead by the maximum alignment number and leaving some space to store the `original_address` value
        // As per the use case above : intermediate_address = 102 + 8 + 8 = 118
        size_t intermediate_address = (size_t)original_address + alignment + sizeof(size_t);

        // Retracting to the aligned memory address
        // As per the use case above : aligned_address = 118 - (118 % 8) = 118 - 6 = 112
        aligned_address = (void *)(intermediate_address - (intermediate_address % alignment));

        // The original address is stored at : 112 - 8 = 104
        *( ((size_t *)aligned_address) - 1) = (size_t)original_address;

        // So there has been a padding of 2 bytes at the start i.e 104 - 102(original_address) = 2
        // and a padding of 6 bytes at the end since : 102{original_address} + (10 + 8 + 8){total size allocated} - (112{aligned_address} + 10{size}) = 128 - 122 = 6
        // So a total of 8 bytes were padded as expected in total : 2(at the start) + 6(at the end)

        // See Readme/wiki for different use case scenarios
    }

    return aligned_address;
}


/**
 * @brief Function to free the aligned address
 * 
 * @param address The pointer to be freed
 */
void aligned_free(void *address)
{
    // Typecasting to size_t * so that it moves back by the word size on doing a -1. See aithmetic pointer operations to understand this step
    // The original address is stored at a custom address word size before the aligned address i.e 8 bytes before the aligned address.
    // Fetching the value of the original address from that custom address be dereferencing the custom address and typecasting it as a pointer to supply as a parameter to `free`.
    free((void *)(*((size_t *)address - 1)));
}