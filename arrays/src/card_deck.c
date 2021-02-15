#include <stdio.h>
#include <stdlib.h>

#include "array_implementations.h"


// Lookup table based on enum values as index. Lookup table normally consists of key-value pairs
// Can also be called as hashmap since no key-value pair. key is the enum value obtained.
// No need to malloc since we need this as read only and is stored in text segment.
static const char * map_enum_to_string[52] = 
{
    "club_ace", "club_two", "club_three", "club_four", "club_five", "club_six", "club_seven", "club_eight", "club_nine", "club_ten", "club_joker", "club_queen", "club_king",
    "diamond_ace", "diamond_two", "diamond_three", "diamond_four", "diamond_five", "diamond_six", "diamond_seven", "diamond_eight", "diamond_nine", "diamond_ten", "diamond_joker", "diamond_queen", "diamond_king",
    "hearts_ace", "hearts_two", "hearts_three", "hearts_four", "hearts_five", "hearts_six", "hearts_seven", "hearts_eight", "hearts_nine", "hearts_ten", "hearts_joker", "hearts_queen", "hearts_king",
    "spades_ace", "spades_two", "spades_three", "spades_four", "spades_five", "spades_six", "spades_seven", "spades_eight", "spades_nine", "spades_ten", "spades_joker", "spades_queen", "spades_king",
};


/**
 * @brief This function mallocs, initializes the required structure and returns the pointer to the structure.
 * 
 * @return struct card_deck* Pointer to the card_deck structure
 */
struct card_deck *init_deck()
{
    struct card_deck *deck;
    deck = (struct card_deck *)malloc(sizeof(struct card_deck));

    if (deck != NULL)
    {
        // Populating the deck_array with the correct values
        for(char i = club_1; i <= spades_13; i++)
        {
            deck->deck_array[i] = i;
        }

        // Resetting deal_counter to 0;
        deck->deal_counter = 0;
    }

    return deck;
}


/**
 * @brief Function to shuffle a deck of cards
 * 
 * @param deck Pointer to the card_deck structure
 * @return true 
 * @return false 
 */
bool shuffle_deck(struct card_deck *deck)
{
    bool status = false;
    size_t src_index, dest_index;
    size_t loop = 1000;

    // Resetting deal_counter to 0;
    deck->deal_counter = 0;

    if (deck != NULL)
    {
        while(loop--)
        {
            src_index = rand() % 52;
            dest_index = rand() % 52;
            // Swap two card values to shuffle
            // XOR fails here when src_index and dest_index end up with the same value so using temp variable method
            // i.e both index pointing to the same variable
            char temp;
            temp = deck->deck_array[src_index];
            deck->deck_array[src_index] = deck->deck_array[dest_index];
            deck->deck_array[dest_index] = temp;
        }
        status = true;
    }

    return status;
}


/**
 * @brief Function to deal the topmost card
 * 
 * @param deck Pointer to card_deck structure
 * @return char Return value
 */
char deal(struct card_deck *deck)
{
    // Error condition
    char deal_value = -1;
    if (deck != NULL)
    {
        if (deck->deal_counter < 52)
        {
            deal_value = deck->deck_array[deck->deal_counter];
            deck->last_card_dealt = deal_value;
            (deck->deal_counter)++;
        }
    }
    
    return deal_value;
}


/**
 * @brief Function to print card value and return the pointer to that value
 * 
 * @param deck Pointer to the card_deck structure
 * @return const char* Return pointer of card string
 */
const char * identify_card(struct card_deck *deck)
{
    const char * card = NULL;

    if (deck != NULL)
    {
        // Map with the correct string here and print
        printf("Dealt Card : %s \n", map_enum_to_string[deck->last_card_dealt]);
        card = map_enum_to_string[deck->last_card_dealt];
    }

    return card;
}




