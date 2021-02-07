#include <stdio.h>
#include <stdlib.h>

#include "bit_manipulation.h"


/**
 * @brief Function to check if the number is a power of 2
 * 
 * @param number The number
 * @return true 
 * @return false 
 */
bool validate_power_of_2(int number)
{
    bool status = false;
    if (number > 0)
    {
        // if (number & (number - 1)) is 0, then power of 2 since only one bit is set
        status = (!(number & (number - 1))) ? true : false;
    }
    return status;

    // Shortest Method
    // return (number > 0) ? ( (!(number & (number - 1))) ? true : false ) : false;

}


/**
 * @brief Function to check if a number is a power of 4
 * 
 * @note See: https://www.geeksforgeeks.org/find-whether-a-given-number-is-a-power-of-4-or-not/  
 * METHOD similar to validate_power_of_8 can also be used here, the modulo operation would be 2.
 * @param number The number
 * @return true 
 * @return false 
 */
bool validate_power_of_4(int number)
{
    bool status = false;
    if (validate_power_of_2(number))
    {
        // if the expression value is non zero, then it is a power of 4
        if (!(number & 0xAAAAAAAA))
            status = true;
    }

    return status;
    // return (validate_power_of_2(number)) ? ( (!(number & 0xAAAAAAAA)) ? true : false ) : false;
}


/**
 * @brief Function to check if the number is a power of 8
 *
 * @note See: https://www.geeksforgeeks.org/check-number-power-8-not/ 
 * METHOD similar to validate_power_of_4 can also be used here, the constant value would be 0xB6DB6DB6.
 * @param number 
 * @return true 
 * @return false 
 */
bool validate_power_of_8(int number)
{
    bool status = false;
    if (validate_power_of_2(number))
    {
        size_t count = 0; 
        // if the expression value is non zero, then it is a power of 4
        while(number != 1)
        {
            number = number >> 1;
            count++;
        }

        printf("Count: %ld\n", count);
        // If count is a multiple of 3, it is a power of 8
        status = (count % 3) ? false : true;
    }

    return status;
}

/**
 * @brief Function to calculate power of the given number
 * 
 * @param number The base number
 * @param raise Raise to number
 * @return int Final value
 */
int calculate_power(int number, size_t raise)
{
    int base = 1;

    // If number is zero
    if (!number)
    {
        base = 0;
    }
    else
    {
        size_t i;
        for (i = 0; i < raise; i++)
        {
            base = base * number;
        }
    }

    return base;
}


/**
 * @brief Find square root of the given number
 * 
 * @note See: https://www.geeksforgeeks.org/square-root-of-an-integer/
 * @param number The given number
 * @return int Square root
 */
int square_root(int number)
{
    // Error value if number is negative
    int root = -1;

    if (number == 0 || number == 1)
    {
        root = number;
    }
    else if (number > 1)
    {
        int i = 1;
        int result = 0;
        for (i = 1; result <= number; i++)
        {
            result = i * i;
        }
        root = i-2;
    }

    return root;
}