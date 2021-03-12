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


		if (n % 2 != 0)
		{
			int k = 1;
			for (int i = 1; i <= n; i++)
			{

				for (int j = 1; j <= n; j++)
				{

					cout << k << " ";

					k++;

				}
				cout << "\n";
			}

		}
		else
		{
			int k = 1;
			for (int i = 1; i <= n; i++)
			{
				if (i % 2 != 0)
				{
					for (int j = 1; j <= n; j++)
					{

						cout << k << " ";

						k++;

					}

				}
				else
				{
					int p = k + n - 1;

					for (int j = 1; j <= n; j++)
					{

						cout << p << " ";

						p--;
						k++;
					}


				}
				cout << "\n";

			}





		}


	}
	return 0;
}