// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0, lim - 1);
	return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1000000007;
const int N = 3e5, M = N;
//=================================================================================================================================//

vi g[N];
int a[N];

void solve() {
	ll i, j, n, m;

	cin >> n;


	ll free_ai[n], paid[n], cost[n];

	fo(i, n)
	cin >> free_ai[i];

	fo(i, n)
	cin >> paid[i];
	fo(i, n)
	cin >> cost[i];


	ll minccost = 0;

	ll maxval;


	if (free_ai[0] <= paid[0])
	{

		maxval = free_ai[0];


	}
	else
	{
		minccost = cost[0];
		maxval = paid[0];
	}



	bool y = false;

	ll t1 = INT_MAX, t2 = INT_MAX, t3 = INT_MAX;

	for (i = 1; i < n - 1; i++)
	{

		if (maxval <= free_ai[i] && maxval <= paid[i])
		{

			if (free_ai[i] <= free_ai[i + 1])
			{


				maxval = free_ai[i];

			}
			else
			{


				if (free_ai[i] <= paid[i + 1])
					t1 = cost[i + 1];
				if (paid[i] <= free_ai[i + 1])
					t2 = cost[i];
				if (paid[i] <= paid[i + 1])
					t3 = cost[i] + cost[i + 1];

				if (t1 == INT_MAX && t2 == INT_MAX && t3 == INT_MAX)
				{

					y = true;
					cout << "-1" << '\n' ;
					break;

				}
				else
				{

					ll mnv = min(t1, t2);
					mnv = min(mnv, t3);


					if (mnv == t1)
						maxval = free_ai[i];
					else
						maxval = paid[i];


					minccost += mnv;



				}





			}


		}
		else if (maxval <= free_ai[i])
		{

			maxval = free_ai[i];

		}

		else if (maxval <= paid[i])
		{

			minccost += cost[i];
			maxval = paid[i];

		}
		else
		{
			y = true;
			cout << "-1" << '\n' ;
			break;
		}








	}




	if (maxval <= free_ai[n - 1])
		minccost += 0;
	else if (maxval <= paid[n - 1])
		minccost += cost[n - 1];
	else
	{
		y = true;
		cout << "-1" << '\n' ;

	}




	if (!y)
		cout << minccost << '\n' ;




}








int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}





