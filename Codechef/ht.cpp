#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{

	long t, n, m, x, y, temp, a;

	// long k, temp;
	// vector<long> dist;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> x >> y;
		if (m == 1 && n == 1)
		{
			cout << x << endl;
			continue;
		}
		if (y < x)
			x = 0;	// y is max  x is min
		else
		{
			y = y - x;
			a = x;
			temp = max(y, x);
			x = min(y, x);
			y = temp;
			if (y > a)
				y = a;

		}
		temp = ((int((m + 1) / 2) * y) + (int(m / 2) * x)) * int((n + 1) / 2);

		temp = temp + ( ((int((m + 1) / 2) * x) + (int(m / 2) * y)) * int(n / 2));
		cout << temp << endl;
	}
	return 0;
}
