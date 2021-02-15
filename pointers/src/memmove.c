#include <stdio.h>
#include <stdlib.h>

#include "pointers.h"



/**
 * @brief Function to copy range of bytes from source pointer to destination pointer
 * @note Pointers supplied need to be malloced before passing. This function copies byte by byte.
 * 
 * @param dest Destination pointer
 * @param src Source pointer
 * @param len Length of bytes to be copied
 * @return void* Return address of the destination pointer
 */
void *memmove_custom (void *dest, const void *src, size_t len)
{
    void *result = NULL;
    if ( src != NULL && dest != NULL )
    {
        if ( src == dest || len == 0 )
        {
            result = dest;
        }
        else
        {
            // Checking two conditions(&&) to make sure only 1 out of 4 cases passes to copy in the reverse direction
            if ( (dest > src) && ((src + len) > dest) )
            {   
                const char *temp_src = src + len - 1;
                char *temp_dest = dest + len - 1;
                while (len--)
                {
                    *temp_dest-- == *temp_src--;
                }
                result = dest;
            }
            else
            {
                const char *temp_src = src;
                char *temp_dest = dest;
                while (len--)
                {
                    *temp_dest++ = *temp_src++;
                }
                result = dest;
            }
        }
    }
  return result;
}



/**
 * @brief Function to copy range of bytes from source pointer to destination pointer efficiently i.e using alignment
 * @note Pointers supplied need to be malloced before passing. This function copies data in word size
 * 
 * @param dest Destination pointer
 * @param src Source pointer
 * @param len Length of bytes to be copied
 * @return void* Return address of the destination pointer
 */
void *memmove_align_custom (void *dest, const void *src, size_t len)
{
    void *result = NULL;
    uint8_t alignment_size = sizeof(size_t);

    if ( src != NULL && dest != NULL )
    {
        if ( src == dest || len == 0 )
        {
            result = dest;
        }
        else
        {
            // Checking two conditions(&&) to make sure only 1 out of 4 cases passes to copy in the reverse direction
            if ( (dest > src) && ((src + len) >= dest) )
            {
                const size_t *temp_src = src + len;
                size_t *temp_dest = dest + len;
                // Transferring word size bytes in one machine cycle for the initial bytes
                while(len >= alignment_size)
                {
                    temp_dest--;
                    temp_src--;
                    *temp_dest = *temp_src;
                    len -= alignment_size;
                }

                // Transferring single bytes until address is aligned
                const char * s_temp_src = (const char *)temp_src;
                char * s_temp_dest = (char *) temp_dest;
                while (len)
                {
                    s_temp_dest--;
                    s_temp_src--;
                    *s_temp_dest = *s_temp_src;
                    len--;
                }

                result = dest;
            }
            else
            {
                const size_t *temp_src = src;
                size_t *temp_dest = dest;
                // Transferring word size bytes in one machine cycle for the initial bytes
                while(len >= alignment_size)
                {
                    *temp_dest = *temp_src;
                    temp_dest++;
                    temp_src++;
                    len -= alignment_size;
                }

                // Transferring single bytes until address is aligned
                const char *s_temp_src = (const char *) temp_src;
                char *s_temp_dest = (char *) temp_dest;
                while (len)
                {
                    *s_temp_dest = *s_temp_src;
                    s_temp_dest++;
                    s_temp_src++;
                    len--;
                }
                
                result = dest;
            }
        }
    }
  return result;
}
