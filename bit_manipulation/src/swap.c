#include <stdio.h>
#include <stdlib.h>

#include "bit_manipulation.h"


/**
 * @brief Function to swap value of two numbers
 * 
 * @param x 
 * @param y 
 */
void swap(int *x, int *y)
{
    // Will fail if addition overflows
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

/**
 * @brief Function to swap value of two numbers using xor. Better than swap()
 * 
 * @param x 
 * @param y 
 */
void swap_xor(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}