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



int getequal(vector<ll>v , ll x)
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

int gethalfindex(vector<ll>v, ll x)
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

bool allelement(vector<ll>v, ll x)
{


	if (v[v.size() - 1] <= x)
		return true;
	return false;
}


void print(vector<ll>v)
{

	int i;
	fo(i, v.size())
	cout << v[i] << " ";
	cout << '\n';

}

void solve() {
	ll i, n, m, x, count = 1;

	cin >> n >> x;
	vector<ll>v;

	fo(i, n)
	{
		cin >> m;

		v.push_back(m);


	}

	sortall(v);

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

			int p = getequal(v, x);
			int q = gethalfindex(v, x);
			if ( p != -1)
			{
				x *= 2;

				//deb2(v[p], count);
				v.erase(v.begin() + p );

				count++;


			}
			else if (q != -2)
			{
				x = v[q] * 2;
				//deb2(v[q], count);
				v.erase(v.begin() + q );
				count++;


			}
			else if (allelement(v, x))
			{

				count += v.size();
				v.clear();

			}

			else
			{

				count++;
				x *= 2;
			}
			//deb2(v.size(), x);
			//deb(count);
			//print(v);


		}

		cout << count - 1 << '\n' ;

	}

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





