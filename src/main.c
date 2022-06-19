//#include "include/stringimpl.h"
#include "include/number.h"

int main() {
	unsigned int a = 0b11111111111111111111111111111111;
	number num = Number(a);
	number_add_int(num, 4);
	number_sub(num, Number(4));
	number_print(num);
}




//int main() {
//	unsigned char* data = (unsigned char[]) { 0b00000000, 0b00000000, 0b00000000 };  // expected: 0
//	unsigned char* data2 = (unsigned char[]) { 0b11100000, 0b00000000, 0b00000000 }; // expected: 3
//	unsigned char* data3 = (unsigned char[]) { 0b11111111, 0b00000000, 0b00000000 }; // expected: 8
//	unsigned char* data4 = (unsigned char[]) { 0b11111111, 0b11000000, 0b11111111 }; // expected: 10
//	printf("%zu ", number_size(data));
//	printf("%zu ", number_size(data2));
//	printf("%zu ", number_size(data3));
//	printf("%zu ", number_size(data4));
//}