#include <stdint.h>
#include <stdbool.h>


// Note:
// int64_t x = (1 << 32) 
// The above expression will give the value of x to be 0 since 1 is by default a signed integer (4 bytes) which can only left shift 31 places before overflowing to 0.
// 1 << 31 yields a negative number since it is an signed integer.
// 1 << 30 yields a positive number
// 1ULL << 32 yields a positive number since ULL is 8 bytes long and does not overflow. This positive number can also be stored in int64_t. If stored in int32_t, it will yield 0.

// UL(%lu) is gurarnteed to be 4 bytes long. Can be 8 bytes longs as well depending on the system
// ULL(%llu) is guaranteed to be 8 bytes long. 
// See https://stackoverflow.com/a/10631674/14225230
// size_t is normally UL i.e %lu and is of 8 bytes

#define LSB_MASK(x)                                     ((uint8_t)(x))                //Extract least significant byte using this mask
#define MSB_MASK(x)                                     ((uint8_t)((x) >> 8))         //Extract most significant byte using this mask.

/* a=target variable, b=bit number to act upon 0-n */ 
#define BIT_SET(a,b)                                    ((a) |= (1UL<<(b))) 
#define BIT_CLEAR(a,b)                                  ((a) &= ~(1UL<<(b))) 
#define BIT_FLIP(a,b)                                   ((a) ^= (1UL<<(b))) 
#define BIT_CHECK(a,b)                                  (!!((a) & (1UL<<(b))))        // '!!' to make sure this returns 0 or 1 
 

/* x=target variable, y=mask */ 
#define BITMASK_SET(x,y)                                ((x) |= (y)) 
#define BITMASK_CLEAR(x,y)                              ((x) &= (~(y))) 
#define BITMASK_FLIP(x,y)                               ((x) ^= (y)) 
#define BITMASK_CHECK_ALL(x,y)                          (((x) & (y)) == (y))   // warning: evaluates y twice 
#define BITMASK_CHECK_ANY(x,y)                          ((x) & (y)) 

#define rotateleft(value,x)                             (((unsigned int)value << x) | ((unsigned int)value >> (32-x))) 
#define rotateright(value,x)                            (((unsigned int)value >> x) | ((unsigned int)value << (32-x))) 


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


// Set bit position
int find_MSB_set(int number);
int find_LSB_set(int number);
size_t exchange_odd_even_bits(size_t number);
size_t reverse_bits(size_t number);


// Decimal-Binary conversion 
void decimal_to_binary(int number);
void binary_to_decimal(int number);
void binary_to_decimal_recursive(int number);