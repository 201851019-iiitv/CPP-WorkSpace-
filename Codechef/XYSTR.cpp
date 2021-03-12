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
		string s;
		cin >> s;

		int n = s.length(), count = 0;

		for (int i = 0; i < n - 1; i++)
		{

			if (s[i] == 'x' && s[i + 1] == 'y')
			{
				count++;
				i++;
			}
			else  if (s[i] == 'y' && s[i + 1] == 'x')
			{
				count++;
				i++;
			}
		}


		cout << count << '\n' ;

	}
	return 0;
}