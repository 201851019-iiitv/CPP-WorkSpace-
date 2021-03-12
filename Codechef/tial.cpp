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


int twoCost(int a, int b, int p, int q)
{

	if (a == p && b == q)
		return 0;
	else if (a - p == b - q)
		return 1;
	else if ( p != 0 && q != 0 && a % p == 0 && b % q == 0 && a / p == b / q)
		return 1;


	return 2;
}







void solve() {
	int i, count = 0, minc = 5;

	int a[3], b[3];

	fo(i, 3)
	cin >> a[i];
	fo(i, 3)
	cin >> b[i];


//-------------- trial first and count---------------------------------------------

	int diff1 = b[0] - a[0];
	if (diff1 != 0)
	{
		count = 1 + twoCost(b[1], b[2], a[1], a[2]);
		minc = min(minc, count);

		count = 1 + twoCost(b[1], b[2], a[1] + diff1, a[2] + diff1);
		minc = min(minc, count);
		//deb2(minc, count);
		count = 1 + twoCost(b[1], b[2], a[1] + diff1, a[2]);
		minc = min(minc, count);
		//deb2(minc, count);
		count = 1 + twoCost(b[1], b[2], a[1] , a[2] + diff1);
		minc = min(minc, count);

	}
	else
	{
		count = twoCost(b[1], b[2], a[1], a[2]);
		minc = min(minc, count);
		//deb2(minc, count);

	}

	if (a[0] != 0 && b[0] % a[0] == 0)
	{

		int mul = b[0] / a[0];

		if (mul != 1)
		{
			count = 1 + twoCost(b[1], b[2], a[1] * mul, a[2] * mul);
			minc = min(minc, count);
			//deb2(minc, count);
			count = 1 + twoCost(b[1], b[2], a[1] * mul, a[2] );
			minc = min(minc, count);
			//deb2(minc, count);
			count = 1 + twoCost(b[1], b[2], a[1] , a[2] * mul);
			minc = min(minc, count);
			//deb2(minc, count);
		}






	}

//-------------------------------------------------------------------------
	int diff2 = b[1] - a[1];
	if (diff2 != 0)
	{
		count = 1 + twoCost(b[0], b[2], a[0], a[2]);
		minc = min(minc, count);
		//deb2(minc, count);
		count = 1 + twoCost(b[0], b[2], a[0] + diff2, a[2] + diff2);
		minc = min(minc, count);
		//deb2(minc, count);
		count = 1 + twoCost(b[0], b[2], a[0] + diff2, a[2]);
		minc = min(minc, count);
		//deb2(minc, count);
		count = 1 + twoCost(b[0], b[2], a[0] , a[2] + diff2);
		minc = min(minc, count);
		//deb2(minc, count);

	}
	else
	{
		count = twoCost(b[0], b[2], a[0], a[2]);
		minc = min(minc, count);
		//deb2(minc, count);
	}

	if (a[1] != 0 && b[1] % a[1] == 0)
	{

		int mul = b[1] / a[1];

		if (mul != 1)
		{
			count = 1 + twoCost(b[0], b[2], a[0] * mul, a[2] * mul);
			minc = min(minc, count);
			//deb2(minc, count);
			count = 1 + twoCost(b[0], b[2], a[0] * mul, a[2] );
			minc = min(minc, count);
			//deb2(minc, count);
			count = 1 + twoCost(b[0], b[2], a[0] , a[2] * mul);
			minc = min(minc, count);
			//deb2(minc, count);
		}




	}

//-------------------------------------33--------------------

	int diff3 = b[2] - a[2];
	if (diff3 != 0)
	{
		count = 1 + twoCost(b[0], b[1], a[0], a[1]);
		minc = min(minc, count);
		count = 1 + twoCost(b[0], b[1], a[0] + diff3, a[1] + diff3);
		minc = min(minc, count);
		count = 1 + twoCost(b[0], b[1], a[0] + diff3, a[1]);
		minc = min(minc, count);
		count = 1 + twoCost(b[0], b[1], a[0] , a[1] + diff3);
		minc = min(minc, count);

	}
	else
	{
		count = twoCost(b[0], b[1], a[0], a[1]);
		minc = min(minc, count);
	}

	if (a[2] != 0 && b[2] % a[2] == 0)
	{

		int mul = b[2] / a[2];

		if (mul != 1)
		{
			count = 1 + twoCost(b[0], b[1], a[0] * mul, a[1] * mul);
			minc = min(minc, count);
			count = 1 + twoCost(b[0], b[1], a[0] * mul, a[1] );
			minc = min(minc, count);
			count = 1 + twoCost(b[0], b[1], a[0] , a[1] * mul);
			minc = min(minc, count);
		}




	}

	//deb(minc);

	int l1, k1, l2, k2, l3, k3;
	if (a[0] != 0)
	{
		l1 = b[0] / a[0];

		k1 = b[0] - (a[0] * l1);

		if (b[0] == ((a[0]*l1) + k1) && b[1] == (a[1]*l1 + k1) && b[2] == (a[2]*l1 + k1))
		{
			count = 2;
			//cout << "hell1" << '\n' ;
		}


		minc = min(minc, count);
	}
	if (a[1] != 0)
	{
		l2 = b[1] / a[1];

		k2 = b[1] - (a[1] * l1);

		if (b[0] == (a[0]*l2 + k2) && b[1] == (a[1]*l2 + k2) && b[2] == (a[2]*l2 + k2))
		{
			count = 2;
			//cout << "hell2" << '\n' ;
		}



		minc = min(minc, count);

	}
	if (a[2] != 0)
	{
		l3 = b[2] / a[2];

		k3 = b[2] - (a[2] * l1);

		if (b[0] == (a[0]*l3 + k3) && b[1] == (a[1]*l3 + k3) && b[2] == (a[2]*l3 + k3))
		{
			count = 2;
			//cout << "hell3" << '\n' ;
		}


		minc = min(minc, count);

	}


	cout << minc << '\n' ;




}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

