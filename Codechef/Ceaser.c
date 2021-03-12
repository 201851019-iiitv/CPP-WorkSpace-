/*
----------------------------------------------------------
      Author : Ambesh Kumar
      Student ID:201851019
      Date :15-01-2021
      Time:07:47:00


---------------------------------------------------------
*/



#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>

// This ceaser Cipher only work on alphabets  i.e. a--> z and A-->Z;


char *Get_decryption(char *s, int n) {

	for (int i = 0; i < n; i++)
	{

		if (s[i] >= 'a' && s[i] <= 'z')
		{

// First change char (s[i]) into it's ASCII value
//substract  3 i.e means shift three characters of alphabets in backward direction.
// then change integer value to character same using ASCII value.
// we also add 26 to insure that the value can't be negative otherwise take garbage value.

			char c = char((s[i] - 'a' - 3 + 26) % 26 + 'a');
			s[i] = c;



		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
// First change char (s[i]) into it's ASCII value
//sunstract 3 i.e means shift three characters of alphabets.
// then change integer value to character same using ASCII value in backward direction.
//we also add 26 to insure that the value can't be negative otherwise take garbage value.

			char c = char((s[i] - 'A' - 3 + 26) % 26 + 'A');
			s[i] = c;

		}


	}

	return s;
}



char *Get_Encryption(char *s , int n) {

	for (int i = 0; i < n; i++)
	{

		if (s[i] >= 'a' && s[i] <= 'z')
		{

// First change char (s[i]) into it's ASCII value
//Add 3 i.e means shift three characters of alphabets.
// then change integer value to character same using ASCII value.

			char c = char((s[i] - 'a' + 3) % 26 + 'a');
			s[i] = c;



		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
// First change char (s[i]) into it's ASCII value
//Add 3 i.e means shift three characters of alphabets in forward direction.
// then change integer value to character same using ASCII value.

			char c = char((s[i] - 'A' + 3) % 26 + 'A');
			s[i] = c;

		}


	}


	return s;
}


int main()
{
	char ss[1000];

	int n;

// take input length of string
	printf("Enter the length of string \n");
	scanf("%d\n", &n);
// input string which want to encrypt
	printf("Enter the string \n");
	scanf("%s", &ss);


// call encrypt function and pass by reference
	char *encrypted = Get_Encryption(ss, n);

	printf("Encryption:\t");
//print encrypted string
	printf("%s\n", encrypted);

// call encrypt function and pass by reference
	char * decrypted = Get_decryption(ss, n);

	printf("decryption:\t");
//print encrypted string
	printf("%s\n", decrypted);




	return 0;
}