#include <stdio.h>
#include <stdlib.h>


int search(int arrayInt[], int length, int value) 
{
    for(int i = 0; i < length; i++) 
    {
        if (value == arrayInt[i])
        {
            return i;
        }
    }
    return -1;
}

void main() 
{
    int numberArray[] = {9, 4, 8, 1, 10, 2, 6, 5, 3, 7};
    int length = (int) (sizeof(numberArray) / sizeof(int));
    int position = search(numberArray, length, 10);
    printf("The position of the value is: %d\n", position);
}