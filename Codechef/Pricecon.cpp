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

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		ll sum1 = 0, sum2 = 0;

		int arr[n];

		loop(i, n)
		{
			cin >> arr[i];
			sum1 += (ll)arr[i];

			if (arr[i] > k)
				arr[i] = k;


			sum2 += (ll)arr[i];

		}


		cout << (sum1 - sum2) << '\n' ;


	}
	return 0;
}