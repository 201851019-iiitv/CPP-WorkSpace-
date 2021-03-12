

bool NCATishHelper(char *word, int &word_length, char c)
{

	if (word_length < 0)
		return false;


	if (word[word_length] == c)
		return true;

	word_length--;

	return NCATishHelper(word, word_length, c);



}






bool InNCATish(char *word, int &word_length)
{



	word_length--;



	bool t = NCATishHelper(word, word_length, 't');


	if (t)
	{

		bool a = NCATishHelper(word, word_length, 'a');

		if (a)
		{

			bool c = NCATishHelper(word, word_length, 'c');


			if (c)
			{


				bool n = NCATishHelper(word, word_length, 'n');

				if (n)
					return true;
				else
					return false;




			}
			else
				return false;



		}
		else
			return false;




	}




	return false;


}


