#include <stdio.h>
#include <stdlib.h>

#include "src/bit_manipulation.h"


int main() 
{
    printf("%d\n", calculate_power(4,1));
    printf("%d\n", square_root(-2));
    printf("%d\n", validate_power_of_4(-4));
    printf("%d\n", find_LSB_set(10));
    printf("%d\n", find_MSB_set(10));
    printf("%lx\n", exchange_odd_even_bits(0x5555555555555555));
    printf("%lu\n", reverse_bits(1));
    return 0;
}