#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<stdbool.h>


// Created by Ambesh Kumar -->201851019
// This Playfair Cipher only work on alphabets  i.e. a--> z and A-->Z;

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



char* Get_Encrypted(char *s, int n)
{

	char Str[100];


	//printf("Hello\t");
	int i = 0, j = 0;
	for (; i < n - 1; i++)
	{
		if (s[i] == s[i + 1] && s[i] != 'x')
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
		else if (s[i] == s[i + 1] && s[i] == 'x')
		{

			int row1 = Find_Row(s[i]);
			int row2 = Find_Row('z');
			int col1 = Find_Col(s[i]);
			int col2 = Find_Col('z');


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
		else
		{

			//printf("Hello\t");
			int row1 = Find_Row(s[i]);

			//printf("%d\t", row1);
			int row2 = Find_Row(s[i + 1]);
			int col1 = Find_Col(s[i]);
			int col2 = Find_Col(s[i + 1]);


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





			//printf("%s \t", Str);
			i++;

		}





	}


	if (i == n - 1)
	{

		if (s[i] != 'x')
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
		else
		{

			int row1 = Find_Row(s[i]);
			int row2 = Find_Row('z');
			int col1 = Find_Col(s[i]);
			int col2 = Find_Col('z');


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



	}



	printf("%s \t", Str);


}







int main()
{

	int n;


	scanf("%d", &n);

	char key[n];


/// take input as key;
	scanf ("%s", &key);


	///printf("%s\n", key);

/// 0-->25 alphabates occurancance   track
	bool occured[26];



/// Just temp array to store key and help to make table of 5*5;
/// i and j are consoder same
	char temp[25];


	int i = 0, j = 0, m;

	while (i < n)
	{

		m = (int)((key[i] - 'a' + 26) % 26);

		/// check at index value is true i.e. value occured ??
		/// if occured then no need to add otherwise add it.




		/// check  for special case i
		if (m == 17)
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
		else if (m == 18)
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

	scanf("%d", &kk);
	char ss[kk];

	scanf("%s", ss);


	//printf("%s\n", ss);

	Get_Encrypted(ss, kk);

	//printf("%s\n", cc);






}