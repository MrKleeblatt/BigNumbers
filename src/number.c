#include <malloc.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include "include/number.h"

// returns a string of nine characters (8 ones and zeros and the NULL character)
char* byte2bin_s(byte_t n) {
	static char s[9];
	for(int i = 7; i >= 0; --i) {
		if( n >> i & 1 ) s[7 - i] = '1';
		else s[7 - i] = '0';
	}
	s[8] = '\0';
	return s;
}

int calc_num_size(unsigned long long a) {
	int number_size = 0;
	// get byte array number_size
	// If the next byte has also at minimum a one in it, the number_size increases,
	// and we repeat the same but with the now next byte.
	// This continues until the maximum size of the integer is reached.
	while(number_size < sizeof(a) && a >> ((number_size + 1) * 7)) {
		number_size++;
	}
	return ++number_size;
}

// creates a new number object that contains the int "a"
// the number's size is stored as the amount of ones before the first zero minus 1
// because the size of "01111111" is one and there is no sense in wasting one more bit for it
number Number(unsigned long long a) {
	if( !a ) return calloc(1, 1);
	static byte_t* bytes = NULL;

	int number_size = calc_num_size(a);
	bytes = calloc(number_size, 1);
	// set amount of ones if front of the first zero to the number_size
	// (minus one because there obviously can't be a number with size 0 lol)
	int byte_index = 0;
	int bit_index = 7;
	for(int _ = 0; _ < (number_size - 1); _++) {
		// bit_index is in reversed order, so that pow(2,8) equivalents to 10000000
		bytes[byte_index] += (byte_t) pow(2, bit_index);
		bit_index--;
		// go to next byte and reset bit index if eight bits wre set to ones
		if( bit_index == -1 ) {
			byte_index++;
			bit_index = 7;
		}
	}

	// add the number to it
	for(; byte_index < number_size; ++byte_index) {
		byte_t b;
		// why the fuck is a 32bit-int right shifted 32 the same int again?!? Why isn't it zero?!?
		// That's why I have to check first whether the right shift could cause the same number to outcome
		// and not zero, and have to manually set it. Dumb shit!
		if( number_size - byte_index > sizeof(a)) b = 0;
		else b = (a >> ((number_size - byte_index - 1) * 8));
		bytes[byte_index] += b;
	}
	return bytes;
}

// returns the number of Bytes this number takes up
size_t number_size(number bytes) {
	size_t count = 0;
	// for every byte until the maximum range of bytes
	// or the first 0 is reached
	for(int i = 0; i < NUMBER_MAX_SIZE; i++) {
		byte_t byte = bytes[i];
		// for every bit
		for(int j = 7; j >= 0; --j) {
			unsigned char bit = byte >> j;
			count++;
			if( !(bit & 1)) return count;
		}
	}
	return count;
}

// prints all the bits from a number grouped in bytes to stdout
void number_print(number n) {
	printf("Größe: %zu\n", number_size(n));
	for(int i = 0; i < number_size(n); ++i)
		printf("%s ", byte2bin_s(n[i]));
	printf("\n");
}

// returns the number as an unsigned long long
unsigned long long number_to_llu(number num) {
	printf("Not implemented yet\n");
	exit(EXIT_FAILURE);
}

// returns a string that contains the number in its integer representation in decimal format
char* number_to_intString(number num) {
	printf("Not implemented yet\n");
	exit(EXIT_FAILURE);
}