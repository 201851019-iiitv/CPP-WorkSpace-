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

ll calc(ll n, int colour, vector<ll> lines[]) {


	vector<ll>v = lines[colour];


	for (ll i = 0; i < v.size() && n > 0 ; i++) {

		ll temp = min(v[i], n);
		v[i] = v[i] - temp;
		n = n - temp;

	}

	if (n > 0) {
		return 0;
	}


	ll sum = 0, i;
	ll  m = v.size();
	fo(i, m)
	sum += v[i];

	ll sum1 = 0;
	ll temp[m + 1];
	fo(i, m)
	{
		temp[i] = v[i] * (sum - v[i]);
		sum1 += temp[i];
	}
	sum1 /= 2;

	ll sum2 = 0;
	fo(i, m)
	sum2 += v[i] * (sum1 - temp[i]);
	sum2 /= 3;

	return sum2;
}








void solve() {
	int i, j, n, c, k;


	cin >> n >> c >> k;

	map<long long int, int> pencils[c + 1];


	vector<long long int> lines[c + 1];


	ll slope, cont, colour;


	Fo(i, 1, n + 1) {

		cin >> slope >> cont >> colour;

		//a is the slope
		pencils[colour][slope]++;
	}

	ll cost[c + 1] = {0};
	Fo(i, 1, c + 1)
	{
		cin >> cost[i];
	}


	Fo(i, 1, c + 1)
	{
		vector<ll> samecolour;
		for (auto it : pencils[i]) {
			samecolour.push_back(it.second);
		}
		sortall(samecolour);
		lines[i] = samecolour;
	}

	ll total[k + 1][c + 1];
	ll store[k + 1][c + 1];
	fo (i, k + 1) {
		fo (j, c + 1) {
			total[i][j] = INT_MAX;
			if (j == 0) {
				total[i][j] = 0;
			}

			store[i][j] = -1;
		}
	}
	ll d = 0;

	fo(i, k + 1) {

		Fo (j, 1, c + 1) {
			ll rem = i / cost[j];
			fo (d, rem + 1) {
				ll val = d * cost[j];
				if (store[d][j] == -1) {
					store[d][j] = calc(d, j, lines);

				}

				total[i][j] = min(total[i][j] , total[i - val][j - 1] + store[d][j] );

			}
		}
	}

	cout << total[k][c] << endl;

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





