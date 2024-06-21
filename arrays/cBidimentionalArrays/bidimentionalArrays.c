#include <stdio.h>

int main()
{
    int bidimentionalArray[10][10];

    for(int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            bidimentionalArray[i][j] = (i * 10) + j;
        }
    }

    for(int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", bidimentionalArray[i][j]);
        }
        printf("\n");
    }

    return 0;
}