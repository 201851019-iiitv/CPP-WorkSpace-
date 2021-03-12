//Playfair Cipher

#include<stdio.h>
#include<string.h>


//This function will delete repeated letters
void delete(char* str) {
	char str1[strlen(str)], t1[strlen(str)];
	int i, j, m, m1, t2;
	for (i = 0; i < strlen(str); i++) {
		str1[i] = str[i]; t1[i] = '\0';
	}

//Initialize the first letter
	t1[0] = str[0];
	m = 0;
//This loop check repeatation and delete it
	for (i = 1; i < strlen(str); i++) {
		t2 = strlen(t1);

		m1 = 0;
		//Check str1[i] is present in t1[0] to t1[strlen(t1)] if absent include it into t1
		for (j = 0; j < t2; j++) {
			if (str1[i] == t1[j])
				m1++;
			else
				m1 = m1;
		}
		if (m1 == 0) {
			m++;
			t1[m] = str[i];
		}
		else
			m = m;
	}
//Reassign str with t1; t1 will not have any repeated letter
	for (i = 0; i < strlen(str); i++) str[i] = t1[i];

}


int main() {
	int i, j, k, len, s, r1, c1, r2, c2;
	char keytab[5][5];
	printf("Enter Key Length\n");
	scanf("%d", &len);
	char key[len], nkey[len];
	printf("\nEnter Key\n");
	scanf("%s", key);

//Converting j to i
	for (i = 0; i < strlen(key); i++) {
		if (key[i] == 'j')
			key[i] = 'i';
	}
	len = strlen(key);

//Remove the repeated letter from key
	delete(key);
	// printf("%s\n",key);
	len = strlen(key);

//Defining an array based on lenght of key
	char temp[len + 26];
	for (i = 0; i < len + 27; i++) temp[i] = '\0';

//Storing keys to temp
	for (i = 0; i < len; i++)
		temp[i] = key[i];
	s = 0;

//Add all alphabates to temp
	for (i = len; i < len + 26; i++) {
		if ('a' + s == 'j')
			temp[i] = 'i';
		else
			temp[i] = 'a' + s;
		s++;
	}

	// printf("%s\n",temp);

//Delete the repeated letter from temp (temp will have repeatations as we are stored all letters after storing key in temp)
	delete(temp);
	//printf("%s\n",temp);

//Store temp to 5X5 matrix
	s = 0;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++) {
			keytab[i][j] = temp[s];
			s++;
		}
	printf("\nPrinting 5X5 Table\n");
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++)
			printf("%c ", keytab[i][j]);
		printf("\n");
	}

//Encryption part
	int lenm, rp;
	printf("\nEnter Length of the Message\n");
	scanf("%d", &lenm);
	char msg[lenm];
	printf("\nEnter Your Message\n");
	scanf("%s", msg);

//Checking the number of repeated letters in message
	rp = 0;
	for (i = 0; i < lenm - 1; i++) {
		if (msg[i] == msg[i + 1])
			rp++;
	}

//Defining a new array based on number of repeatation

	char msg1[lenm + rp];

//Add extra x in between of two repeatation. Updated array will be msg1
	j = 0;
	for (i = 0; i < lenm - 1; i++) {
		if (msg[i] == msg[i + 1]) {
			msg1[j] = msg[i];
			msg1[j + 1] = 'x';
			j = j + 2;
		}
		else {
			msg1[j] = msg[i];
			j++;
		}
	}
//Include last letter in msg1 from msg
	msg1[lenm + rp - 1] = msg[lenm - 1];

//Definig final message which is fmsg. The size of the array is increased by 1. If the length of msg1 is odd we will add x or we will add a null character.
	char fmsg[lenm + rp + 1];

	if (((strlen(msg1)) % 2) == 1) {
		fmsg[lenm + rp] = 'x';
	}
	else
		fmsg[lenm + rp] = '\0';
	for (i = 0; i < lenm + rp; i++)
		fmsg[i] = msg1[i];
	printf("\nPrinting Even Length Message\n");
	printf("%s\n", fmsg);

//Defining ciphertext array
	char cipher[strlen(fmsg)];
	for (i = 0; i < strlen(fmsg) + 1; i++) cipher[i] = '\0';

//Performing the enryption
	k = 0;
	while (k < (strlen(fmsg) - 1)) {

//This loop will find the row number and column number of the matrix depending on 2 length of message
		for (i = 0; i < 5; i++) {
			for (j = 0; j < 5; j++) {
				if (keytab[i][j] == fmsg[k]) {
					r1 = i; c1 = j;
				}
				if (keytab[i][j] == fmsg[k + 1]) {
					r2 = i; c2 = j;
				}
			}
		}

//checking different possibilities (i.e., different row or same row or same column)
		if ((r1 != r2) & (c1 != c2)) {
			cipher[k] = keytab[r1][c2];
			cipher[k + 1] = keytab[r2][c1];
		}
		if (r1 == r2) {
			cipher[k] = keytab[r1][(c1 + 1) % 5];
			cipher[k + 1] = keytab[r1][(c2 + 1) % 5];
		}
		if (c1 == c2) {
			cipher[k] = keytab[(r1 + 1) % 5][c1];
			cipher[k + 1] = keytab[(r2 + 1) % 5][c2];
		}
		k = k + 2;
	}
	printf("\nPrinting Ciphertext\n");
	printf("%s\n", cipher);
	printf("\n");
	return 0;
}