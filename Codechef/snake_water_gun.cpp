// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error thhen you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

#define  ll  long long
# define  loop(x,n)  for(int x = 0; x < n; ++x)
#define   constloop(x,a,n) for(int x = a; x < n; ++x)
#define  revloop(x,a,n)  for(int x = a; x > n; x--)

// ------- above define macros---------------------//


using namespace std;

int compare(char comp, char you)
{

	if (comp == you)
		return 0;

	if (comp == 's' && you == 'w')
		return -1;
	else if (comp == 'w' && you == 's')
		return 1;
	if (comp == 's' && you == 'g')
		return 1;
	else if (comp == 'g' && you == 's')
		return -1;
	if (comp == 'w' && you == 'g')
		return -1;
	else if (comp == 'g' && you == 'w')
		return 1;



	return 0;

}





int main()
{



	int totalyou = 0, totalcomp = 0;
	bool y = true;

	while (y)
	{

		char comp, you, choice;
		srand(time(0));
		int n = (rand() % 3) + 1;//1---3

		if (n == 1)
			comp = 's';
		else if (n == 2)
			comp = 'w';
		else
			comp = 'g';


		cout << "Pls Enter  choice " << '\n' ;
		cout << "**** For Snake choose s ****" << '\n' ;
		cout << "**** For Water choose w  ****" << '\n' ;
		cout << "**** For Gun   choose g  ****" << '\n' ;
		cin >> you;

		int res = compare(comp, you);
		cout << "You choose " << you << " " << "and computer choose " << comp << "\n";
		if (res == 1)
		{
			cout << "Congratulation You Win !! " << '\n' ;
			totalyou++;
		}
		else if (res == 0)
			cout << "Match Draw" << '\n' ;
		else
		{
			cout << "You Lose " << '\n' ;
			totalcomp++;
		}


		cout << "Your total score " << totalyou << " " << "and computer score " << totalcomp << '\n' ;
		cout << " Hopefully !! You Enjoy The game " << "\n";
		cout << "You want to play game again " << '\n' ;

		cout << "If Yes enter y otherwise enter n" << '\n' ;
		cin >> choice;

		if (choice == 'n' || choice == 'N')
			y = false;
	}



	return 0;
}