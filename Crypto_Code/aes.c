#include <stdio.h>
#define ul unsigned long
int main()
{

    ul arr[16];
    for (int i = 0; i < 16; i++)
    {
        scanf("%x", &arr[i]);
    }

    ul res[4][4];

    printf("Before shift :\n");
    for (int i = 0; i < 4; i++)
    {

        int k = 0, j = i;
        while (k < 4)
        {

            res[i][k] = arr[j];
            k++;
            j += 4;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 4; i++)
    {

        int leftshift = i;
        while (leftshift > 0)
        {

             int temp=res[i][0];
            for (int j = 1; j < 4; j++)
            {
                res[i][j-1]=res[i][j];

            }
            res[i][3]=temp;

            leftshift--;
        }
    }


printf("After shift :\n");
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
}