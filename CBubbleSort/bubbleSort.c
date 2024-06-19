#include <stdio.h>

void main() {
    int numbers[] = {42, 69, 11, 2, 88, 91};
    int i;
    int j;
    int aux;
    printf("-----Initial Array-----\n");
    for (i = 0; i < 6; i++)
    {
        printf("%i\n", numbers[i]);
    }
    
    for(i = 0; i < 5; i++) 
    {
        for(j = i + 1; j < 6; j++) 
        {
            if(numbers[i] > numbers[j]) 
            {
                aux = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
            }       
        }
    }

    printf("-----Sorted Array-----\n");
    for (i = 0; i < 6; i++)
    {
        printf("%i\n", numbers[i]);
    }
}