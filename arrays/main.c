#include <stdio.h>
#include <stdlib.h>

#include "src/array_implementations.h"


int main() 
{
    struct card_deck *deck;
    deck = init_deck();
    shuffle_deck(deck);
    
    printf("Deal: %d\n", deal(deck));
    const char * x = identify_card(deck);
    printf("main dealt Card : %s \n", x);
    
    free(deck);

    int array[6] = {5, 0, 3, 0, 4, 2};
    bool status = sort_with_end_zero(array, 6);
    if (status)
    {
        for (int i = 0; i < 6; i++)
        {
            printf("Array: %d\n", array[i]);
        }
    }
    return 0;

}