
#include <stdio.h>
#define ull unsigned long long
#define ul unsigned long

ul straight_permutation(ul val)
{
    int perm_table[] = {16, 7, 20, 21,
                        29, 12, 28, 17,
                        1, 15, 23, 26,
                        5, 18, 31, 10,
                        2, 8, 24, 14,
                        32, 27, 3, 9,
                        19, 13, 30, 6,
                        22, 11, 4, 25};

    ul temp = 0;
    for (int i = 0; i < 32; i++)
    {

        temp = temp | (val & (1 << (perm_table[i] - 1)));

        temp <<= 1;
    }

    return temp;
}

ul s_box(ull val)
{
    int S[512] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                  4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                  15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13,
                  15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                  0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                  13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9,
                  10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,
                  7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                  13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                  10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                  3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,
                  2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                  14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                  4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                  11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3,
                  12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                  10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                  9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                  4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13,
                  4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                  13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                  1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                  6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,
                  13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                  1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                  7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                  2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};

    int res[8], j = 7;
    for (int i = 0; i < 8; i++)
    {

        res[j] = (val & 63);
        val >>= 6;
        j--;
    }

    int s[8];
    for (int i = 7; i >= 0; i--)
    {

        /*
exmp=100101  we have 6 bit
so row will be = msblsb=11
column =0010
that is if we have 6-bit b0b1b2b3b4b5
row=b0b5
column=b1b2b3b4

*/

        int msb = (res[i] & 32); // msb
        int lsb = (res[i] & 1);  //lsb
        int row = msb;
        row <<= 1;
        row = (row | lsb); //b0b5

        int column = (res[i] & 30); // 4-bit (b1b2b3b4)

        s[i] = S[64 * i + row * 16 + column];
    }

     ul temp = 0;

    for (int i = 0; i < 8; i++)
    {

        temp = (temp | s[i]);
        temp <<= 4;
    }

    return temp;
}

ull expansion(ul r0)
{

    int expansion_table[] = {32, 1, 2, 3, 4, 5,
                             4, 5, 6, 7, 8, 9,
                             8, 9, 10, 11, 12, 13,
                             12, 13, 14, 15, 16, 17,
                             16, 17, 18, 19, 20, 21,
                             20, 21, 22, 23, 24, 25,
                             24, 25, 26, 27, 28, 29,
                             28, 29, 30, 31, 32, 1};

    ull temp = 0;
    for (int i = 0; i < 48; i++)
    {
        temp = temp | (ull)(r0 & (1 << (expansion_table[i] - 1)));

        temp <<= 1;
    }

    return temp;
}

ull Intial_Permutation(ull plain)
{

    int table[] = {58, 50, 42, 34, 26, 18, 10, 2,
                   60, 52, 44, 36, 28, 20, 12, 4,
                   62, 54, 46, 38, 30, 22, 14, 6,
                   64, 56, 48, 40, 32, 24, 16, 8,
                   57, 49, 41, 33, 25, 17, 9, 1,
                   59, 51, 43, 35, 27, 19, 11, 3,
                   61, 53, 45, 37, 29, 21, 13, 5,
                   63, 55, 47, 39, 31, 23, 15, 7};

    ull temp = 0;
    for (int i = 0; i < 64; i++)
    {

        temp = temp | (plain & (1 << (table[i] - 1)));

        temp <<= 1;
    }

    return temp;
}

int main()
{
    ull plain, cipher,key;
    ul l0, l1, r0, r1;
    printf("Enter 64-bit plaintext\n");
    scanf("%llu", &plain);
    printf("Enter 48-bit key\n");
    scanf("%llu", &key);
    printf("\nEncryption Starting\n");
    ull v1 = Intial_Permutation(plain); // IP for 64-bit input

    r0 = (int)v1;
    l0 = (int)(v1 >> 32);

    l1 = r0;

    ull r2 = expansion(r0); // change 32-bit to 48-bit key

    ull xorv = r2 ^ key; //it's 48-bit value
                         // need to change 32-bit using s-box

    ul s_r0 = s_box(xorv); // compress again 32-bit

    ul per_r0 = straight_permutation(s_r0);  // permutation of 32-bit ro value

    r1 = l0 ^ per_r0;

    //Generating final ciphertext
    cipher = (ull)0;
    cipher = cipher | l1;
    cipher = cipher << 32;
    cipher = cipher | r1;
    printf("Ciphertext\n");
    printf("%llu\n", cipher);
}