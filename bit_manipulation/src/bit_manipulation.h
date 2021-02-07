#include <stdint.h>
#include <stdbool.h>


#define LSB_MASK(x)                         ((uint8_t)(x))                //Extract least significant byte using this mask
#define MSB_MASK(x)                         ((uint8_t)((x) >> 8))         //Extract most significant byte using this mask.

/* a=target variable, b=bit number to act upon 0-n */ 
#define BIT_SET(a,b)                                    ((a) |= (1ULL<<(b))) 
#define BIT_CLEAR(a,b)                                  ((a) &= ~(1ULL<<(b))) 
#define BIT_FLIP(a,b)                                   ((a) ^= (1ULL<<(b))) 
#define BIT_CHECK(a,b)                                  (!!((a) & (1ULL<<(b))))        // '!!' to make sure this returns 0 or 1 
 

/* x=target variable, y=mask */ 
#define BITMASK_SET(x,y)                                ((x) |= (y)) 
#define BITMASK_CLEAR(x,y)                              ((x) &= (~(y))) 
#define BITMASK_FLIP(x,y)                               ((x) ^= (y)) 
#define BITMASK_CHECK_ALL(x,y)                          (((x) & (y)) == (y))   // warning: evaluates y twice 
#define BITMASK_CHECK_ANY(x,y)                          ((x) & (y)) 

// bit manipulation base functions
size_t set_bit(size_t number, size_t bit_position);
size_t clear_bit(size_t number, size_t bit_position);
size_t toggle_bit(size_t number, size_t bit_position);
size_t set_bit_value(size_t number, size_t bit_position, bool value);
int computeXOR(int n);
int computeXOR_efficient(int n);
bool check_even(int number);
size_t count_set_bit(size_t number);

// Swap functions
void swap(int *x, int *y);
void swap_xor(int *x, int *y);

// power of even number functions
bool validate_power_of_2(int number);
bool validate_power_of_4(int number);
bool validate_power_of_8(int number);
int calculate_power(int number, size_t raise);
int square_root(int number);
