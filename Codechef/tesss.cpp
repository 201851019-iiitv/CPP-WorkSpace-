
#include <bits/stdc++.h>


#define  ll  long long
# define  loop(x,n)  for(int x = 0; x < n; ++x)
#define   constloop(x,a,n) for(int x = a; x < n; ++x)
#define  revloop(x,a,n)  for(int x = a; x > n; x--)

// ------- above define macros---------------------//


using namespace std;


int checkEqual(vector<ll>v , ll x)
{

	int low = 0, high = v.size() - 1, mid;
	while (low <= high)
	{

		mid = (low + high) / 2;

		if (v[mid] == x)
			return mid;
		else if (v[mid] > x)
		{
			high = mid - 1;
		}
		else
			low = mid + 1;



	}




	return -1;

}

int lesshalf(vector<ll>v, ll x)
{


	int low = 0, high = v.size() - 1, mid;

	while (low <= high)
	{
		mid = (low + high) / 2;

		if (v[mid] >= ceil(x / (double)2) && v[mid] < x)
			return mid;
		else if (v[mid] < ceil(x / (double)2))
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}

	}

	return -2;

}

bool LessElements(vector<ll>v, ll x)
{


	if (v[v.size() - 1] <= x)
		return true;
	return false;
}



int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		ll i, n, m, x, count = 0;

		cin >> n >> x;
		vector<ll>v;

		loop(i, n)
		{
			cin >> m;

			v.push_back(m);


		}

		sort(v.begin(), v.end());

		if (v[v.size() - 1] <= x)
		{
			cout << n << '\n' ;

		}
		else
		{
			while (v[0] > x)
			{

				count++;
				x = x * 2;
				//deb(count);
			}
			//print(v);

			while (v.size() != 0)
			{

				int p = checkEqual(v, x);
				int q = lesshalf(v, x);
				if ( p != -1)
				{
					x *= 2;
					v.erase(v.begin() + p );

					count++;


				}
				else if (q != -2)
				{
					x = v[q] * 2;
					v.erase(v.begin() + q );
					count++;


				}
				else if (LessElements(v, x))
				{

					count += v.size();
					v.clear();

				}

				else
				{

					count++;
					x *= 2;
				}



			}

			cout << count  << '\n' ;

		}

	}
	return 0;
}