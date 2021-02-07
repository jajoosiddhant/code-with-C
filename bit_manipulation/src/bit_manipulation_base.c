#include <stdio.h>
#include <stdlib.h>

#include "bit_manipulation.h"


/**
 * @brief Set the bit object
 * 
 * @param number The number of which bit is to be set
 * @param bit_position bit position
 * @return size_t The final number
 */
size_t set_bit(size_t number, size_t bit_position)
{
    return (number | (1UL << bit_position));
}

/**
 * @brief Clear the bit position
 * 
 * @param number The number of which bit is to be cleared
 * @param bit_position bit position
 * @return size_t The final number
 */
size_t clear_bit(size_t number, size_t bit_position)
{
    return (number & ~(1UL << bit_position)); 
}

/**
 * @brief Toggle the bit position
 * 
 * @param number The number of which bit is to be toggled
 * @param bit_position bit position
 * @return size_t The final number
 */
size_t toggle_bit(size_t number, size_t bit_position)
{
    return (number ^ (1UL << bit_position));
}

/**
 * @brief Set the bit position to a specified value
 * 
 * @param number Number
 * @param bit_position Bit position
 * @param value The value of the bit position
 * @return size_t The final number 
 */
size_t set_bit_value(size_t number, size_t bit_position, bool value)
{
    // (number & ~(1UL << bit_position)) will clear the bit_position bit 
    // and (value << bit_position) will set the bit_position bit to value
    return ((number & ~(1UL << bit_position)) | (value << bit_position)); 
}

/**
 * @brief Function to compute XOR of n consecutive integers
 * 
 * @param n The number upto which xor needs to be computed
 * @return int Value of XOR of n consecutive integers
 */
int computeXOR(int n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;      
}


/**
 * @brief computeXOR() efficient method
 * 
 * @param n 
 * @return int 
 * @see https://www.geeksforgeeks.org/calculate-xor-1-n/
 */
int computeXOR_efficient(int n)
{
    // Modulus operator are expensive on most of the computers. n & 3 will be equivalent to n % 4. 
    switch(n & 3)
    {
        case 0: return n;                       // n is multiple of 4
        case 1: return 1;                       // n%4 gives remainder 1
        case 2: return n + 1;                   // n%4 gives remainder 2
        case 3: return 0;                       // n%4 gives remainder 3
    }
}


/**
 * @brief Function to check if number is even
 * 
 * @param number number
 * @return true true if even
 * @return false false if odd
 */
bool check_even(int number)
{
    return (number & 1) ? false : true;
}


/**
 * @brief Function to count set bits in a number
 * 
 * @param number The number
 * @return size_t Count of set bits
 */
size_t count_set_bit(size_t number)
{
    size_t count = 0;
    while (number)
    {
        // This operation below clears the least significant bit of the number 
        number = number & (number - 1);
        count++;
    }
    return count;
}