#include <stdio.h>

void referenceTest(int *pInt)
{
    printf("Print pointer address: %p\n", pInt);
    printf("Printing value of pointer reference: %d", *pInt);
}

int main()
{
    int number = 11;
    int *pNumber = NULL;
    pNumber = &number;

    printf("--------Number--------\n");
    printf("Number value: %d\n", number);
    printf("Number address: %p\n", &number);

    printf("-----Number Pointer-----\n");
    printf("Pointer value: %p\n", pNumber);
    printf("Pointer value at address: %d\n", *pNumber);

    printf("-----Comparing Size-----\n");
    printf("Size of number: %d bytes\n", (int) sizeof(number));
    printf("Size of pointer: %d bytes\n", (int) sizeof(pNumber));

    printf("---Pointers as function params---\n");
    referenceTest(pNumber);

    return 0;
}