#include <stdio.h>

#define ull unsigned long long
#define ul unsigned long
#define mul 4294967296 //2^32
#define aul 281474976710656//2^48
#define tul 17179869184  //2^34 
#define NBITS 32


int expansion_table[] =  {  32,  1,  2,  3,  4,  5,
                            4,  5,  6,  7,  8,  9,
                            8,  9, 10, 11, 12, 13,
                            12, 13, 14, 15, 16, 17,
                            16, 17, 18, 19, 20, 21,
                            20, 21, 22, 23, 24, 25,
                            24, 25, 26, 27, 28, 29,
                            28, 29, 30, 31, 32,  1
                         };







void printbit(unsigned long long n)
{

	int arr[64];

	for (int i = 0; i < 64; i++)
	{
		if ((n & (1ULL << i)))
			arr[i] = 1;
		else
			arr[i] = 0;
	}



	for (int i = 63; i >= 0; i--)
	{
		if (i == 31)
			printf("\nNext 32-bit are :\n");
		printf("%d", arr[i]);

	}


	printf("\n");

}

//It take 32 bit input and make 48-bit .
ull expansion(ul val)
{
	ull temp = aul; // already define as 49 bit number
	if ((val & (1 << 31)) > 0) //check 1th bit is set/unset
		temp = temp | 1; //then set 1-bit


	if ((val & 1) > 0) //check 32th bit is set/unset
		temp = (temp | (1ULL << 33)); // then set 34-bit


	temp = (temp | ((val << 1) | mul));


	temp = (temp & (aul - 1)); //make 48-bit

	/*

	temp=R31R0R1R2R3R4R5R6R7R8R9R10R11R12R13R14R15R16R17R18R19R20R21R22R23R24R25R26R27R28R29R30R31R0

	*/

	// temp is exactly 34-bit number

	temp = reverse(temp) //reverse the temp
	       /*
	       Then we
	       temp=

	       */




}

//This function will give R0
ul right(ull pl) {
	ul temp;
	temp = pl & (mul - 1);

	return temp;
}

//This function will give L0
ul left(ull pl) {
	ul temp;
	temp = pl >> 32;
	return temp;
}



int main()
{
	ull plain, cipher;
	ul key, l0, l1, r0, r1;
	printf("Enter 64-bit plaintext\n");
	scanf("%llu", &plain);
	printf("Enter 32-bit key\n");
	scanf("%lu", &key);
	printf("\nEncryption Starting\n");

	//Finding L0 and R0

	l0 = left(plain);
	r0 = right(plain);
	printf("L0: %lu   R0:%lu\n", l0, r0);

	//Checking R0+K
	printf("R0+K: %lu\n", r0 ^ key);

	printbit(r0);

	ull temp = expansion(r0); // this 48-bit code



}