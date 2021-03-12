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
		int n;
		cin >> n;

		int arr[n], b[n];

		loop(i, n)
		cin >> arr[i];
		loop(i, n)
		cin >> b[i];
		int min1, index;
		for (int i = 0; i < n - 1; i++)
		{
			min1 = arr[i];
			for (int j = i + 1; j < n; j++)
			{
				if (min1 > arr[j])
				{
					min1 = arr[j];
					index = j;
				}


			}

			if (b[i] != b[index])
			{
				swap(arr[i], arr[index]);

			}


		}

		bool y = true;

		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				y = false;
				cout << "NO" << '\n' ;
				break;
			}

		}

		if (y)
			cout << "YES" << '\n' ;

	}
	return 0;
}