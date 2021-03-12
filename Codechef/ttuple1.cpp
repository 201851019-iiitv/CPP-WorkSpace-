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

		ll diff1 = a - p, diff2 = b - q, diff3 = c - r;
		ll mul1 = 0, mul2 = 0, mul3 = 0;

		if (p != 0  && a % p == 0)
			mul1 = a / p;
		else
			mul1 = X;
		if (q != 0 &&  b % q == 0)
			mul2 = b / q;
		else
			mul2 = X;
		if (r != 0 &&  c % r == 0)
			mul3 = c / r;
		else
			mul3 = X;



		/*---------------************* for result 0 *************---------------------------------*/

		if (p == a && q == b && c == r)
			cout << "0" << '\n' ;


		/*---------------************* for result 1 *************---------------------------------*/
		else if (p == a && b == q)
			cout << "1" << '\n' ;
		else if (p == a && c == r)
			cout << "1" << '\n' ;
		else if (b == q && c == r)
			cout << "1" << '\n' ;

		//**********************//


		else if (diff1 == diff2  && diff1 == diff3)
			cout << "1" << '\n' ;

		else if (diff1 == diff2  && c == r)
			cout << "1" << '\n' ;
		else if (diff1 == diff3  && b == q)
			cout << "1" << '\n' ;
		else if (diff3 == diff2  && a == p)
			cout << "1" << '\n' ;


		//**********************//
		else if (mul1 != X && mul1 == mul2 && mul1 == mul3)
			cout << "1" << '\n' ;

		else if (mul1 != X  && mul1 == mul2 && c == r)
			cout << "1" << '\n' ;

		else if (mul2 != X  && mul2 == mul3 && a == p)
			cout << "1" << '\n' ;

		else if (mul1 != X  && mul1 == mul3 && b == q)
			cout << "1" << '\n' ;


		/*---------------************* for result 2 *************---------------------------------*/

		else if (p == a )
			cout << "2" << '\n' ;
		else if (b == q )
			cout << "2" << '\n' ;
		else if (c == r )
			cout << "2" << '\n' ;

		//**********************//

		else if (diff1 == diff2)
			cout << "2" << '\n' ;

		else if (diff2 == diff3)
			cout << "2" << '\n' ;

		else if (diff1 == diff3)
			cout << "2" << '\n' ;

		else if ((diff1 + diff2 == diff3) || (diff1 + diff3 == diff2) || diff2 + diff3 == diff2)
			cout << "2" << '\n' ;


		//**********************//

		else if (mul1 != X && mul1 == mul2 )
			cout << "2" << '\n' ;
		else if (mul1 != X  && mul1 == mul3 )
			cout << "2" << '\n' ;
		else if (mul2 != X  && mul2 == mul3 )
			cout << "2" << '\n' ;




		/*---------------************* for result 2 *************---------------------------------*/

		else
			cout << "3" << '\n' ;



		//cout << mul1 << " " << mul2 << " " << mul3;



	}
	return 0;
}
