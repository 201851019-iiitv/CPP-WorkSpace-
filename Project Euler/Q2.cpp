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

int main()
{


	ios::sync_with_stdio(0);
	cin.tie(0);

	ll sum = 2, a = 1, b = 2, c; // intially sum is 2nd term


	int i = 3;
	while (sum < 4000000) // check sum is less than 4 millions
	{

		c = a + b;
		if (c % 2 == 0) // check if  even terms then add the values in sum;
			sum += c;

		a = b;
		b = c;
		i++;

	}


	cout << sum << '\n' ;

	return 0;
}
