#include <stdio.h>

#define ull unsigned long long
#define ul unsigned long
#define mul 4294967296 //2^32
#define NBITS 32

//Right rotate function
ul rightrotate(ul n, ul d)
{
	return (n >> d) | (n << (NBITS - d));
}

// 1001
// 30-000 10
// 0100000000000000000000000000...
// example 01 1001

//  n=32
// rightrotate=8
// 28...0-1000
// 30...0 - 10

//This function will give R0
ul right(ull pl)
{
	ul temp;
	temp = pl & (mul - 1);

	return temp;
}

//This function will give L0
ul left(ull pl)
{
	ul temp;
	temp = pl >> 32;
	return temp;
}

//The round function

ul roundfunction(ul in)
{
	int i, k;
	ul t1, temp = (ul)0, t2, t3;
	t3 = in;
	// in=b7b6b5b4b3b2b0
	k = 0;
	for (i = 0; i < 8; i++)
	{
		// i=0 t1=b0;
		// i=1 t1=b1;

		t1 = (in & 15);
		// i=0 t1=S(b0)
		// i=1 t1=S(b1)
		// i=2 t1=S(b2)
		// t1 = (t1 + 1) % 16;
		t1 = (t1 + 1) & 15;
		// i=0 t2= S(b0)
		// i=1 t2= S(b1)
		// i=2 t2= S(b2)
		t2 = (t1 << k);
		temp = (temp | t2);
		// i=0 temp = S(b0)
		// i=1 temp =S(b1)S(b0)
		// i=2 temp = S(b2)S(b1)S(b0)

		//   in=rightrotate(in,4);
		in = in >> 4;
		//   1010 ... 1000
		k = k + 4;
	}
	// temp=S(b7)S(b6)S(b5)S(b4)S(b3)S(b2)S(b1)S(b0)
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

	//Computing L1 and R1
	l1 = r0;
	r1 = l0 ^ roundfunction(r0 ^ key);
	printf("L1: %lu   R1: %lu\n", l1, r1);

	//Generating final ciphertext
	cipher = (ull)0;
	cipher = cipher | l1;
	cipher = cipher << 32;
	cipher = cipher | r1;
	printf("Ciphertext\n");
	printf("%llu\n", cipher);
}