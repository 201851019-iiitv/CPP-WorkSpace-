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

		ll a, x, b, y, c;
		cin >> a >> x >> b >> y >> c;
		int j = 1;
		ll count = 0;

		while (c * j <= (a * x + b * y))
		{

			ll p = c * j;
			int i = 1, k = 1;

			while (i <= x  )
			{
				ll s1 = i * a;

				ll s2 = (p - s1);

				if (s2 <= b * y && s2 % b == 0)
				{
					ll s3 = s2 / b;

					if (s3 <= y)
						count++;

				}
				else
					break;


				i += a;
			}

			while (k <= y  )
			{
				ll s1 = k * b;

				ll s2 = (p - s1);

				if (s2 <= a * x && s2 % a == 0)
				{
					ll s3 = s2 / b;

					if (s3 <= x)
						count++;

				}
				else
					break;


				k += b;
			}




		}






		cout << count << '\n' ;


	}
	return 0;
}