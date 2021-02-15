#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


// Memmove functions
void *memmove_custom (void *dest, const void *src, size_t len);
void *memmove_align_custom (void *dest, const void *src, size_t len);