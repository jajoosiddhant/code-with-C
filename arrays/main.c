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

    return 0;

}