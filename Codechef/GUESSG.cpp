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

	int t = 1;
	//cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int low = 1, high = n, k = 1;
		char c;

		while (  low <= high)
		{


			int mid = (low + high) / 2;



			cout << mid << "\n";
			fflush(stdout);


			cin >> c;
			//cout<<c <<'\n' ;

			if (k % 2 == 0)
			{

				if (c == 'E')
					return mid;

				else if (c == 'L')
					low = mid - 1;
				else
					high = mid + 1;
			}

			k++;

		}

		low = 1, high = n, k = 1;

		while (  low <= high)
		{

			int mid = (low + high) / 2;


			cout << mid << '\n' ;
			fflush(stdout);

			cin >> c;
			//cout<<c <<'\n' ;
			if (k % 2 != 0)
			{


				if (c == 'E')
					return 0;

				else if (c == 'L')
					low = mid - 1;
				else
					high = mid + 1;


			}

			k++;
		}







	}
	return 0;
}