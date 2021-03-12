#include<bits/stdc++.h>
#include"ncatish.h"


using namespace std;



int main()
{

	int  word_length;


	cin >> word_length ;



	char *word = new char[word_length];

	for (int i = 0; i < word_length; i++)
		cin >> &word[i];


	if (InNCATish(word, word_length))
		cout << "True" << '\n' ;
	else
		cout << "False" << '\n' ;





}