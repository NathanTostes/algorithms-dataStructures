#include <stdio.h>

void main() {
	int number = 9;
	int copiedNumber = number;
	int * pointer = &number;
	*pointer = 11;
	printf("Number memory address = %p\n", &number);
	printf("Copied number memory address = %p\n", &copiedNumber);
	printf("Pointer memory address = %p\n", pointer);
	printf("Number value = %d\n", number);
	printf("Copied number value = %d\n", copiedNumber);
	printf("Pointer value = %d\n", *pointer);
}
