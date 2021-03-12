#include <bits/stdc++.h>

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

bool fun(pair<ll, ll>&a , pair<ll, ll>&b)
{

	return a.first == b.first;
	return a.first == b.second ;
	return  a.second == b.first ;
	return  a.second == b.second;



}

void solve() {
	int i, j, n, m, p;

	cin >> n;


	bool vis[n + 1];
	memset(vis, false, sizeof(vis));

	ll arr[n + 1];
	for (i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> p;

	vector<pair<ll, ll>>v;

	fo(i, p)
	{
		cin >> m >> j;

		v.push_back(mp(m, j));
	}


	sort(v.begin(), v.end(), fun);

	for (i = 0; i < p; i++)
		cout << v[i].first << " " << v[i].second << "\n";

	vector<vector<ll>>vv;




	vv.push_back({v[0].first, v[0].second});
	vis[v[0].first] = true;
	vis[v[0].second] = true;

	int k = 0;
	for (i = 1; i < p; i++)
	{

		if (v[i - 1].first == v[i].first)
		{
			if (!vis[v[i].second])
			{
				vv[k].push_back(v[i].second);
				vis[v[i].second] = true;

			}


		}
		else if (v[i - 1].first == v[i].second)
		{
			if (!vis[v[i].first])
			{
				vv[k].push_back(v[i].first);
				vis[v[i].first] = true;


			}


		}
		else  if (v[i - 1].second == v[i].first)
		{
			if (!vis[v[i].second])
			{
				vv[k].push_back(v[i].second);
				vis[v[i].second] = true;


			}


		}

		else  if (v[i - 1].second == v[i].second)
		{
			if (!vis[v[i].first])
			{
				vv[k].push_back(v[i].first);
				vis[v[i].first] = true;

			}


		}
		else
		{
			vv.push_back({v[i].first, v[i].second});
			k++;
		}


	}


	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			vv.push_back({i});



	}

	// for (i = 0; i < vv.size(); i++)
	// {

	// 	for (j = 0; j < vv[i].size(); j++)
	// 	{
	// 		cout << vv[i][j] << " ";

	// 	}

	// 	cout << "\n";

	// }





	ll cost, maxcost = 0;
	for (i = 0; i < vv.size(); i++)
	{
		cost = 0;
		for (j = 0; j < vv[i].size(); j++)
		{
			cost += arr[vv[i][j]];

		}

		maxcost = max(cost, maxcost);
	}



	cout << maxcost << "\n";


}







int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}










