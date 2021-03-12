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

bool checkPrime(ll n)
{

	if (n <= 1)
		return false;
	for (int i = 2; i * i <= n; i++) {
		// check only sqrt if any divisor exist then definetly not a prime else a prime  number .!!
		if (n % i == 0)
			return false;

	}
	return true;

}



int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	// for get divisor of a number we should check only sqrt(number)

	ll n = 600851475143, maxprime = INT_MIN;

	for (ll i = 1; i * i <= n; i++)
	{


		if (n % i == 0 )
		{

			ll b = n / i;

			if (checkPrime(i)) // if i is prime divisor
				maxprime = max(maxprime, i);

			if (checkPrime(b)) // if b is prime divisor
				maxprime = max(maxprime, b);


		}


	}


	cout << maxprime << '\n' ;

	return 0;
}

