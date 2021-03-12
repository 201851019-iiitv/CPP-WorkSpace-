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

long long binpow(int a, int b) {

	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = (long long)res * a ;
		a = a * a ;
		b = b / 2;
	}
	return res;




}




int solve() {
	int i, j, n, m;

	cin >> n;



	ll arr[21];
	arr[0] = 0;

	ll d1 = 2;
	for (int i = 1; i < 21; i++)
	{



		cout << "1" << " " << d1 << endl;


		fflush(stdout);


		cin >> m;
		arr[i] = m;

		d1 *= 2;

	}

	d1 /= 2;
	ll res = 0;

	arr[20] = arr[20] - n * d1;
	ll maxv = arr[20];

	d1 /= 2;
	for (int i = 19; i >= 1; i--)
	{

		ll p = ((abs(arr[i] - maxv)) / d1);

		if (maxv <= arr[i])
		{


			arr[i] = (n - p) / 2;


		}

		else
		{
			arr[i] = (n + p) / 2;


		}

		d1 /= 2;


	}

	if (arr[20] & 1)
	{

		res++;
	}

	for (int i = 19; i >= 1; i--)
	{

		if (arr[i] & 1)
			res += binpow(2, i);




	}


	cout << "2" << " " << res << endl ;

	fflush(stdout);



	cin >> m;

	return m;




}







int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t = 1;
	cin >> t;
	while (t--) {
		if (solve() == -1)
			break;

		fflush(stdout);
	}

	return 0;
}





