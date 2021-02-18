#include <stdio.h>
#include <stdlib.h>

#include "array_implementations.h"


/**
 * @brief Function to identify and move the zeroes to the end of the array
 * 
 * @param array This can be an array or a malloced pointer
 * @param size The size of the array or malloced pointer. If it is a malloced pointer the size value should not consist of Null character
 * @return true 
 * @return false 
 */
bool sort_with_end_zero(int *array, size_t size)
{
    bool status = false;
    if (array != NULL && size != 0)
    {
        size_t index = 0;
        size_t i = 0;
        for (i = 0; i < size; i++)
        {
            if (array[i] != 0)
            {
                array[index] = array[i];
                index++;
            }
        }

        while(index < size)
        {
            array[index] = 0;
            index++;
        }

        status = true;
    }
    
    return status;
}