/*

-----------------------------------------------------------

          Author:Ambesh Kumar
          Student ID:201851019

-----------------------------------------------------------

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdint.h>


/// use only for debugg
/// this print all 64 bit binary representation of a number;

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





/// In this function  all values are 32-bit.
unsigned long fun(unsigned long r0, unsigned long  key)
{

	unsigned long x0 = r0 ^ key;
/// taking xor value to find X0 in 32 bit;


	unsigned long y0 = 0, b;

// store the value in the function;

	// printf("%lu\n", x0);
	// printbit(x0);

//// x0=b0b1b2b3b4b5b6b7
///  let x0=5;
///i.e x0=00000000000000000000000000000101
//// b0=0000 b1=0000 b2=0000 b3=0000 b4=0000 b5=0000 b6=0000 b7=0101;


	unsigned long b1[8];
	int j, i = 0, k = 7;
	while (i < 32)
	{

		b = 0;
		for (j = i; j < i + 4; j++)
		{

			if ((x0 & (1 << j)) > 0) // that means x0 jth bit is 1.
			{
				b = (b | (1 << (j - i)));

			}

		}


/// this is S function
		b1[k] = (b + 1) % 16;

		k--;
		i += 4;
	}


	// for (int i = 0; i < 8; i++)
	// 	printf("%lu\n", b1[i]);



/// merge all b0b1b2b3b4b5b6b7
/// b7 ---> LSB and b0 -->MSB
/// make 32-bit y0;

	k = 0;
	for (i = 7; i >= 0; i--)
	{

		for (j = 0; j < 4; j++)
		{
			if ((b1[i] & (1 << j)) > 0)
			{
				y0 = (y0 | (1 << k));
			}


			k++;
		}



	}


	// printf("%lu\n", y0);
	// printbit(y0);
	return y0;
}



/// Decryption :
/// L0=R1 xor(f(L1,key))
///R0=L1

void decrypted(unsigned long l1, unsigned long r1, unsigned long key)
{
	unsigned long r0 = 0, l0 = 0, y1 = 0;
	unsigned long long res = 0;

	r0 = l1;

	y1 = fun(l1, key);

	l0 = r1 ^ y1;


	res = r0;


	unsigned long long temp = 0;

	for (int i = 32; i < 64; i++)
	{

		temp = (1ULL << (i - 32));
		if ((temp & l0) > 0)
			res = (res | (1ULL << i ));


	}

	printf("Decryption :\n");
	printf("%llu\n", res);



}

void encrypted(unsigned long long pi, unsigned long key)
{

	unsigned long long  res = 0;
	unsigned long l0 = 0, r0 = 0;


/// R0
/// it is 32 bit unsigned number


	unsigned long long temp = 0;

	for (int i = 0; i < 32; i++)
	{



		temp = (1ULL << i); // mask for ith bit  to check bit is 1 or 0.
		if ((pi & temp) > 0) //if ith bit 1
			r0 = (r0 | temp);


	}



///L0

/// it is 32 bit unsigned number

	for (int i = 32; i < 64; i++)
	{

		temp = (1ULL << i);  // mask for ith bit  to check bit is 1 or 0

		if ((pi & temp) > 0)  //if ith bit is 1
			l0 = (l0 | (1 << (i - 32))); /// set index from 0 to 31

	}


	unsigned long l1, r1, r2;





/// L1=R0;
	l1 = r0;


/// R1=L0 xor(f(R0,key));


	r2 = fun(r0, key);



	r1 = r2 ^ l0;
	res = r1;

	for (int i = 32; i < 64; i++)
	{

		temp = (1ULL << (i - 32));
		if ((temp & l1) > 0)
			res = (res | (1ULL << i ));


	}

	printf("Encryption :\n");
	printf("%llu\n", res);

	decrypted(l1, r1, key);




}





int main()
{


	unsigned long long  pi;


	printf("Enter the plain text(upto 64-Bit unsigned integer) :\n");
///taking input as 64 bit ;
	scanf("%llu" , &pi);

	//printbit(pi);

	printf("Enter the Key(upto 32-Bit unsigned integer) :\n");
	unsigned long key;

	scanf("%lu", &key);


	encrypted(pi, key);
	return 0;
}