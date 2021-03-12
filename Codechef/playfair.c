/*
----------------------------------------------------------
      Author : Ambesh Kumar
      Student ID:201851019
      Date :20-01-2021
      Time:03:47:00


---------------------------------------------------------
*/


#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdlib.h>

// This Playfair Cipher only work on alphabets  i.e. a--> z ;

// global declare table of 5*5

char table[5][5];


int  Find_Row(char c1)
{

	int row = -1;

// Find the row of s[i]  i.e. c1

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (table[i][j] == c1)
			{
				row = i;
				break;
			}

		}
	}


	return row;

}

int Find_Col(char c1)
{

	int col = -1;
// Find the col of s[i]  i.e. c1

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (table[i][j] == c1)
			{
				col = j;
				break;
			}

		}
	}

	return col;

}



void  Get_decrypted(char s[], int  n)
{


//// This decryption part  in case of i j it always print i .
//// in this case we should replace i ,j .
/// because both i,j consider as same in table .

	char Str[100];

	char ss[100];

	for (int i = 0; i < 100; i++)
	{
		Str[i] = '\0';
		ss[i] = '\0';
	}

	int j = 0, i;

	for ( i = 0; i < n; i += 2)
	{
		int row1 = Find_Row(s[i]);
		int row2 = Find_Row(s[i + 1]);
		int col1 = Find_Col(s[i]);
		int col2 = Find_Col(s[i + 1]);


		if (row1 == row2)
		{
			// incremnet or shift one right;
			Str[j] = table[row1][(col1 - 1 + 5) % 5];
			Str[j + 1] = table[row1][(col2 - 1 + 5) % 5];

			j += 2;

		}
		else if (col1 == col2)
		{
			// increment or shift one down;
			Str[j] = table[(row1 - 1 + 5) % 5][col1];
			Str[j + 1] = table[(row2 - 1 + 5) % 5][col1];

			j += 2;


		}
		else
		{
			// make rectangle i.e change row and column;
			Str[j] = table[row1][col2];
			Str[j + 1] = table[row2][col1];

			j += 2;



		}





	}



//// Remove x in decryption part;
	i = 0, j = 0;
	while (Str[i] != '\0')
	{

///Incase of occurence x then if x is last char or corner left or right characters are same
/// we do nothing in this case.

		if (Str[i] == 'x' && (Str[i + 1] == '\0' || (Str[i + 1] == Str[i - 1])));
		else
		{
			ss[j] = Str[i];
			j++;
		}

		i++;
	}

	printf("%s\n", Str);
	printf("decryption:\t");
	printf("%s\n", ss);


}



void  Get_Encrypted(char s[], int n)
{



	char Str[100];



	for (int i = 0; i < 100; i++)
		Str[i] = '\0';




	int i = 0, j = 0;
	for (; i + 1 < n; i++)
	{



		// if pair of character are same insert one 'x' between them
		if (s[i] == s[i + 1] )
		{

			int row1 = Find_Row(s[i]);
			int row2 = Find_Row('x');
			int col1 = Find_Col(s[i]);
			int col2 = Find_Col('x');


			if (row1 == row2)
			{
				// incremnet or shift one right;
				Str[j] = table[row1][(col1 + 1) % 5];
				Str[j + 1] = table[row1][(col2 + 1) % 5];

				j += 2;

			}
			else if (col1 == col2)
			{
				// increment or shift one down;
				Str[j] = table[(row1 + 1) % 5][col1];
				Str[j + 1] = table[(row2 + 1) % 5][col2];

				j += 2;


			}
			else
			{
				// make rectangle i.e change row and column;
				Str[j] = table[row1][col2];

				Str[j + 1] = table[row2][col1];

				j += 2;


			}



		}

// Both characters are different .
		else
		{

			int row1 = Find_Row(s[i]);
			int row2 = Find_Row(s[i + 1]);
			int col1 = Find_Col(s[i]);
			int col2 = Find_Col(s[i + 1]);


			if (row1 == row2)
			{
				// incremnet or shift one right;
				Str[j] = table[row1][(col1 + 1) % 5];
				Str[j + 1] = table[row1][(col2 + 1) % 5];

				j += 2;

			}
			else if (col1 == col2)
			{
				// increment or shift one down;
				Str[j] = table[(row1 + 1) % 5][col1];
				Str[j + 1] = table[(row2 + 1) % 5][col1];

				j += 2;


			}
			else
			{
				// make rectangle i.e change row and column;
				Str[j] = table[row1][col2];
				Str[j + 1] = table[row2][col1];

				j += 2;


			}





			i++;

		}



	}

	///if last one character left then we need to insert 'x' for pair.

	if (i == n - 1)
	{
		int row1 = Find_Row(s[i]);
		int row2 = Find_Row('x');
		int col1 = Find_Col(s[i]);
		int col2 = Find_Col('x');


		if (row1 == row2)
		{
			Str[j] = table[row1][(col1 + 1) % 5];
			Str[j + 1] = table[row1][(col2 + 1) % 5];

			j += 2;

		}
		else if (col1 == col2)
		{
			Str[j] = table[(row1 + 1) % 5][col1];
			Str[j + 1] = table[(row2 + 1) % 5][col2];

			j += 2;


		}
		else
		{

			Str[j] = table[row1][col2];
			Str[j + 1] = table[row2][col1];

			j += 2;


		}





	}


	printf("Encryption:\t");
	printf("%s\n", Str);

	Get_decrypted(Str, strlen(Str));


}







int main()
{

	int n;


	scanf("%d\n", &n);

	char key[n];


/// take input as key;
	scanf ("%s\n", &key);


	///printf("%s\n", key);

/// 0-->25 alphabates occurancance   track
	bool occured[26];



/// Just temp array to store key and help to make table of 5*5;
/// i and j are consider same
	char temp[25];


	int i = 0, j = 0, m;

	while (i < n)
	{

		m = (int)((key[i] - 'a' + 26) % 26);

		/// check at index value is true i.e. value occured ??
		/// if occured then no need to add otherwise add it.




		/// check  for special case i
		if (m == 8)
		{

			if (!occured[m] && !occured[m + 1] )
			{
				temp[j] = key[i];
				j++;

				occured[m] = true;
				occured[m + 1] = true;

			}



		}

		///check for special case j;
		else if (m == 9)
		{

			if (!occured[m] && !occured[m - 1] )
			{
				temp[j] = key[i];
				j++;

				occured[m] = true;
				occured[m - 1] = true;

			}



		}


		else if (!occured[m])
		{
			temp[j] = key[i];
			j++;

			occured[m] = true;

		}



		i++;

	}



	char c;

	for (i = 0; i < 26; i++)
	{

		if (i == 9)
			continue;
		if (!occured[i])
		{

			c = (char)(('a' + i));
			temp[j] = c;
			j++;
			occured[i] = true;
		}

	}


	//printf("%s \t", temp);




/// intialized all values in  table

	printf("Table of 5x5 :\n" );

	int k = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{

			table[i][j] = temp[k];
			k++;

			printf("%c \t", table[i][j]);
		}
		printf("\n");
	}



	int kk;

	scanf("%d\n", &kk);
	char ss[kk];

	scanf("%s\n", ss);


	//printf("%s\n", ss);

	Get_Encrypted(ss, kk);

	//printf("%s\n", cc);






}