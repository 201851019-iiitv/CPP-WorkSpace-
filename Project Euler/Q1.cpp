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

	ll sum = 0;

	loop(i, 1000)
	{
		if (i % 3 == 0 || i % 5 == 0) //check number is divisible by 3 or 5
			sum += i;

	}

	cout << sum  << "\n";


	return 0;
}