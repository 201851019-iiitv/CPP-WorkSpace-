#include<stdio.h>
#include<conio.h>


// Created by Ambesh Kumar -->201851019
// This Affine Cipher only work on alphabets  i.e. a--> z and A-->Z;



// This Inverse take the O(n) time

int inverse_Value(int a, int mod)
{

	for (int i = 1; i < mod; i++)
	{

		if ((a * i) % mod == 1)
			return i;


	}




}



char *Get_decryption(char *s, int n, int a, int b) {

	a = inverse_Value(a, 26);


	for (int i = 0; i < n; i++)
	{

		if (s[i] >= 'a' && s[i] <= 'z')
		{
// change s[i] to integer ASCII value .
// change this  (c-b)*inverse(a) ,where c is char value of encrypted string and a,b pass by parameter.
// add 26 to insure that ASCII value can't be negative otherwise it take garbage value.
			char c = ((((s[i] - 'a') - b + 26) * a) % 26 + 'a');
			s[i] = c;



		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
// change s[i] to integer ASCII value .
// change this  (c-b)*inverse(a) ,where c is char value of encrypted string and a,b pass by parameter.
// add 26 to insure that ASCII value can't be negative otherwise it take garbage value.
			char c =((((s[i] - 'A') - b + 26) * a) % 26 + 'A');
			s[i] = c;

		}


	}

	return s;
}



char *Get_Encryption(char *s , int n, int a, int b) {

	for (int i = 0; i < n; i++)
	{

		if (s[i] >= 'a' && s[i] <= 'z')
		{

// change s[i] to integer ASCII value .
// change this  a*x+b where x is char value and a,b pass by parameter.

			char c = (((s[i] - 'a') * a + b) % 26 + 'a');
			s[i] = c;


		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{

// change s[i] to integer ASCII value .
// change this  a*x+b where x is char value and a,b pass by parameter.

			char c = (((s[i] - 'A') * a + b) % 26 + 'A');
			s[i] = c;



		}


	}


	return s;
}


int main()
{

	char ss[1000];

	int n, a, b;

// take input length of string
	printf("Enter the length of string \n");
	scanf("%d", &n);
// input string which want to encrypt
	printf("Enter the string \n");
	scanf("%s", &ss);
// take input a and b values
	printf("Enter the values of a and b \n");
	scanf("%d %d", &a, &b);


// call encrypt function and pass by reference
	char *encrypted = Get_Encryption(ss, n, a, b);

//print encrypted string
	printf("%s\n", encrypted);

// call encrypt function and pass by reference
	char * decrypted = Get_decryption(ss, n, a, b);

//print encrypted string
	printf("%s\n", decrypted);


}