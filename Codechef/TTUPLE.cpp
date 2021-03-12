// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error thhen you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

#define  ll  long long
# define  loop(x,n)  for(int x = 0; x < n; ++x)
#define   constloop(x,a,n) for(int x = a; x < n; ++x)
#define  revloop(x,a,n)  for(int x = a; x > n; x--)
#define X 1000000000000
// ------- above define macros---------------------//


using namespace std;

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll p, q, r, a, b, c;

		cin >> p >> q >> r;
		cin >> a >> b >> c;
		if (p == a && q == b && r == c)
			cout << "0" << '\n' ;
		else if (p == a && q == b )
			cout << "1" << '\n' ;
		else if (p == a &&  q != b && r != c)
		{

			if (b - q == c - r)
				cout << "1" << '\n' ;
			else
			{

				if (q != 0 && r != 0 && b % q == 0 && c % r == 0)
				{
					if ((b / q) == (c / r))
						cout << "1" << '\n' ;

					else
						cout << "2" << '\n' ;
				}
				else
					cout << "2" << '\n' ;


			}

		}
		else if (b == q &&  a != p && r != c)
		{

			if (a - p == c - r)
				cout << "1" << '\n' ;
			else
			{

				if (q != 0 && r != 0 && a % p == 0 && c % r == 0)
				{
					if ((a / p) == (c / r))
						cout << "1" << '\n' ;

					else
						cout << "2" << '\n' ;
				}
				else
					cout << "2" << '\n' ;


			}

		}

		else if (c == r &&  a != p && b != q)
		{

			if (a - p == b - q)
				cout << "1" << '\n' ;
			else
			{

				if (q != 0 && r != 0 && a % p == 0 && b % q == 0)
				{
					if ((a / p) == (b / q))
						cout << "1" << '\n' ;

					else
						cout << "2" << '\n' ;
				}
				else
					cout << "2" << '\n' ;


			}

		}


		else if (p != a && q != b && r != c)
		{

			if (a - p == b - q && a - p == c - r)
				cout << "1" << '\n' ;
			else if (a / p == b / q && a / p == c / r)
				cout << "1" << '\n' ;

			else if (a - p == b - q && a - p != c - r)
			{
				cout << "2" << '\n' ;

			}




			else if (a - p == c - r && a - p != b - q)
			{


				cout << "2" << '\n' ;



			}
			else if (b - q == c - r && a - p != b - q)
			{


				if (b / q == c / r )
					cout << "2" << '\n' ;


			}

			else if (b - q != c - r && b - q != a - p)
			{



				cout << "3" << '\n' ;
			}


		}






	}
	return 0;
}