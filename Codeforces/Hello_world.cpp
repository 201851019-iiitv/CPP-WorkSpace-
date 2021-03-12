// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long
# define  loop(x,n)  for(int x = 0; x < n; ++x)
#define   constloop(x,a,n) for(int x = a; x < n; ++x)
#define  revloop(x,a,n)  for(int x = a; x > n; x--)

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

		cout << n << '\n' ;
		int arr[n], b[n];

		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];

		int min1, index ;
		for (int i = 0; i < n - 1; i++)
		{
			min1 = arr[i];
			index = i;
			for (int j = i + 1; j < n; j++)
			{
				//cout << arr[j] << '\n' ;
				if (arr[j] < min1)
				{
					min1 = arr[j];
					index = j;
				}


			}

			if (b[i] != b[index])
			{
				int tem = arr[i];
				arr[i] = arr[index];
				arr[index] = arr[tem];

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