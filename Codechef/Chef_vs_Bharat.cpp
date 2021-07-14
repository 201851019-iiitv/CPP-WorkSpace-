// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define foo(i, k, n) for (i = k; i < n; i++)
#define Fo(i, k, n) for (i = n - 1; i >= k; i--)
#define ll long long
#define in(x) cin >> x
#define prt(x) cout << x << "\n"
#define prt2(x, y) cout << x << " " << y << "\n"
#define prt3(x, y, z) cout << x << " " << y << " " << z << "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define pr make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define setv(x) memset(x, -1, sizeof(x))
#define tot(arr) arr, arr + sizeof(arr)
#define set(x) memset(x, -1, sizeof(x))
#define sortall(x) sort(all(x))
#define sorttot(arr) sort(tot(arr))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef unordered_map<ll, ll> mp;
typedef unordered_map<char, ll> mc;
typedef unordered_map<ll, bool> mb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}

const ll mod = 1000000007;
const int N = 3e5, M = N;
//=================================================================================================================================//

// n means nth position.
//TODO:Implement number of digit store in nth position globally  (reference article http://oeis.org/A055642) d(n) ;
//TODO:Implement reverse order in nth position globally  (reference article http://oeis.org/A004086)  r(n) ;
//TODO:Implement odd length palindrome globally. (reference article http://oeis.org/A056525) called as p(n) ;

// Formula  p(n)=floor[n/10]*10^d(n)+r(n).

long long binpow(long long a, long long b)
{

    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll modpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res%m;
}

ll reverse(ll n)
{

    ll reversev = 0, rem;

    while (n > 0)
    {

        rem = n % 10;

        reversev = reversev * 10 + rem;
        n /= 10;
    }

    return reversev;
}

void solve()
{
    ll i, j, q, L, R;

    ll p[100005], d[100005], r[100005],sum[100005];
    p[0] = 0, d[0] = 1, r[0] = 0,sum[0]=0;

    //store digits
    for (i = 1; i < 100005; i++)
    {
        d[i] = log10(i) + 1;
    }

    // store reverse order.
    for (i = 1; i < 100005; i++)
    {
        r[i] = reverse(i);
    }

    // calculate p;
    for (i = 1; i < 100005; i++)
    {

        p[i] = ((i / 10) * binpow(10, d[i])) + r[i];
        sum[i] =sum[i-1]+p[i];
        //cout<<p[i]<<" ";
    }

ll locals;
    cin >> q;
    while (q--)
    {

     cin>>L>>R;

   locals=sum[R]-sum[L];

  ll res=modpow(p[L],locals,mod);
   
   cout<<res%mod<<"\n";

    }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int test = 1;
    //cin >> test;
    while (test--)
    {
        solve();
    }

    return 0;
}
