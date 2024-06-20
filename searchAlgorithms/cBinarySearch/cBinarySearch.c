#include <stdio.h>

int search(int sortedArray[], int length, int value) 
{
    int left = 0;
    int right = length;
    int middle;

    while(left <= right) 
    {
        middle = (int) ((left + right) / 2);
        if(sortedArray[middle] == value) {
            return middle;
        }
        if(value < sortedArray[middle]) {
            right = middle - 1;
            continue;
        }
        left = middle + 1;
    }
    return -1;
}

void main() 
{
    int sortedArray[] = {4, 12, 27, 31, 49, 55, 63, 74, 87, 90};
    int length = (int) (sizeof(sortedArray) / sizeof(sortedArray[0]));
    int value = 12;

    int position = search(sortedArray, length, value);
    printf("The value has found in position %d\n", position);
}