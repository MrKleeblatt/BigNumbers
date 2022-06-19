#ifndef NUMBER_H
#define NUMBER_H

#include <stddef.h>

#define NUMBER_MAX_SIZE 100
typedef unsigned char byte_t;
typedef const unsigned char* number;

// creation functions in number.c

char* byte2bin_s(byte_t n);
int calc_num_size(unsigned long long a);
number Number(unsigned long long a);
size_t number_size(number n);
void number_print(number n);
unsigned long long number_to_llu(number num);
char* number_to_intString(number num);

// calculations in number_calc.c

void number_add(number a, number b);
void number_sub(number minuend, number subtrahend);
void number_multi(number a, number b);
void number_div(number dividend, number divisor);
void number_pow(number base, number exponent);
void number_add_int(number a, int b);
void number_sub_int(number minuend, int subtrahend);
void number_multi_int(number a, int b);
void number_div_int(number dividend, int divisor);
void number_pow_int(number base, int exponent);

#endif