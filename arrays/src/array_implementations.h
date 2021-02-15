#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>


// Size of the enum is the maximum datatype size i.e acts as a union
// This mapping is stored in the text/code segment
// https://www.programiz.com/c-programming/c-enumeration
enum card_values
{
    club_1, club_2, club_3, club_4, club_5, club_6, club_7, club_8, club_9, club_10, club_11, club_12, club_13,
    diamond_1, diamond_2, diamond_3, diamond_4, diamond_5, diamond_6, diamond_7, diamond_8, diamond_9, diamond_10, diamond_11, diamond_12, diamond_13,
    hearts_1, hearts_2, hearts_3, hearts_4, hearts_5, hearts_6, hearts_7, hearts_8, hearts_9, hearts_10, hearts_11, hearts_12, hearts_13,
    spades_1, spades_2, spades_3, spades_4, spades_5, spades_6, spades_7, spades_8, spades_9, spades_10, spades_11, spades_12, spades_13
};

struct card_deck
{
    // Array of the card deck
    char deck_array[52];
    // Index to keep track of the next card to deal
    char deal_counter; 
    // Enum value of the latest card dealt
    enum card_values last_card_dealt;
};

// Card deck
struct card_deck *init_deck();
bool shuffle_deck(struct card_deck *deck);
char deal(struct card_deck *deck);
const char * identify_card(struct card_deck *deck);
