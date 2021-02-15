#include <stdio.h>
#include <stdlib.h>

#include "src/pointers.h"


int main() 
{

    char *src = "Hello Aligned World";
    char *dest = (char *)malloc(sizeof(*dest)*20);
    printf("Malloc Return value: %p\n", dest);

    printf("Return value: %p\n", memmove_align_custom((void *)dest, (void *)src, 20));
    printf("src: %s\n", src);
    printf("dest: %s\n", dest);
    

    return 0;

}