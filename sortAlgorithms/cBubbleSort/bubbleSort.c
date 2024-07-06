#include <stdio.h>

void bubbleSort(int[], int);

void main() {
    int arrayNumber[] = {3, 9, 1, 5, 4, 7, 6, 8, 2};
    int arrayPositions = 9;
    printf("---Before Sort---\n");
    for(int i = 0; i < arrayPositions; i++)
    {
        printf("%d ", arrayNumber[i]);
    }
    
    bubbleSort(arrayNumber, arrayPositions);

    printf("\n---After Sort---\n");
    for(int i = 0; i < arrayPositions; i++)
    {
        printf("%d ", arrayNumber[i]);
    }
}

void bubbleSort(int arrayNumber[], int arrayPositions) {
    int swap;
    for(int i = 0; i < arrayPositions - 1; i++) 
    {
        for(int j = 0; j < arrayPositions - i - 1; j++) 
        {
            if(arrayNumber[j] > arrayNumber[j + 1]) {
                swap = arrayNumber[j];
                arrayNumber[j] = arrayNumber[j + 1];
                arrayNumber[j + 1] = swap;
            }
        }
    }
}
