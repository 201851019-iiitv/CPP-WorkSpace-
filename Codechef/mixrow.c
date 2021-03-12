#include <stdio.h>
#include <string.h>
#define ul unsigned long

ul res[4][4];

void mixcol()
{

    ul predef[4][4] = { {2, 3, 1, 1},
        {1, 2, 3, 1},
        {1, 1, 2, 3},
        {3, 1, 1, 2},

    };

    printf("Predefine column:\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", predef[i][j]);
        }
        printf("\n");
    }


    ul temp[4][4] ;


    int p, p1 ;

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            temp[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {

                temp[i][j] = (temp[i][j] ^ (predef[i][k] * res[k][j])) % 283;

                // ul k1 = predef[i][k] * res[k][j];
                // printf("%d %d %d \n", k1, predef[i][k], temp1[k][j]);

            }





        }
    }


    printf("After mix col :\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d\t", temp[i][j]);
        }
        printf("\n");
    }



}


void shiftrows()
{


    for (int i = 0; i < 4; i++)
    {

        int leftshift = i;
        while (leftshift > 0)
        {

            int temp = res[i][0];
            for (int j = 1; j < 4; j++)
            {
                res[i][j - 1] = res[i][j];

            }
            res[i][3] = temp;

            leftshift--;
        }
    }


    printf("After shift :\n");

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%x\t", res[i][j]);
        }
        printf("\n");
    }


}


int main()
{

    ul arr[16];
    for (int i = 0; i < 16; i++)
    {
        scanf("%d", &arr[i]);
    }



    printf("Input :\n");
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


    //shiftrows();
    mixcol();

}