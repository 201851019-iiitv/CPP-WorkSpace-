// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const ll mod = 998244353;
const int N = 3e5, M = N;
//=================================================================================================================================//

ll res[1005];
ll onebit[32];

long long binpow(long long a, long long b)
{

    long long res = 1;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
unsigned long long modInverse(unsigned long long n,
                              int p)
{
    return binpow(n, p - 2);
}

// Returns nCr % p using Fermat's little
// theorem.
long long nCrModPFermat(long long n,
                        ll r)
{
    ll p = mod;
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n]%p * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

ll fun(ll k, ll k2, ll n)
{

    ll res = 0;
    ll j = 1;
    for (int i = 0; i <30; i++)
    {

        if (onebit[i] < k || (n - onebit[i]) < k2);
        
        else
        {

            res += ((nCrModPFermat(onebit[i], k) % mod) * (nCrModPFermat(n - onebit[i], k2) % mod) * j%mod) % mod;

            res %= mod;
        }

        j *= 2;
    }

    return res % mod;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    ll i, j, n, m;

    cin >> n;

    ll arr[n];
    ll sum1 = 0;
    fo(i, n)
    {
        cin >> arr[i];
        sum1 = ((sum1 % mod) + (arr[i] % mod) % mod);
    }
    cin >> m;
    ll query[m], maxv = 0;
    fo(i, m)
    {
        cin >> query[i];
        maxv = max(maxv, query[i]);
    }

    ll count;
    for (i = 0; i <30; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            if ((arr[j] & (1 << i)) > 0)
                count++;
        }
        onebit[i] = count;
    }

    res[0] = 0;
    res[1] = sum1;

    for (i = 2; i <= maxv; i++)
    {

        res[i] = res[i - 1]%mod ;
        
         
        if (i % 2 == 0)
        {

            ll s = i - 1;

            while (s > 0)
            {

                ll k = s;
                ll k2 = i - s;

                ll k1 = fun(k, k2, n);

                res[i] = (res[i] % mod + k1 % mod) % mod;

                s -= 2;
            }
        }

        else
        {

            ll s = i;

            while (s > 0)
            {

                ll k = s;
                ll k2 = i - s;

                ll k1 = fun(k, k2, n);

                res[i] = (res[i] % mod + k1 % mod) % mod;
                s -= 2;
            }
        }
    }

    fo(i, m)
    {
        cout << res[query[i]] << "\n";
    }

    return 0;
}
