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
#define prt(x) cout << x << "\n";
#define prt2(x, y) cout << x << " " << y << "\n";
#define prt3(x, y, z) cout << x << " " << y << " " << z << "\n";
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define pr make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
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

ll getnumber(vi v)
{

    ll pow = 1;
    ll res = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {

        res += v[i] * pow;

        pow *= 10;
    }

    return res;
}

ll f(ll n)
{
    vi v1, v2;
    int rem;

    int i;
    while (n > 0)
    {
        rem = n % 10;
        v1.push_back(rem);
        n /= 10;
    }

    sortall(v1);
    v2 = v1;
    reverse(v1.begin(), v1.end());

    ll n1 = getnumber(v1);
    ll n2 = getnumber(v2);

    return n1 - n2;
}

void solve()
{
    ll i, j, n, m;
    in(n);

    in(m);

    if (m == 0)
    {
        cout << n << "\n";
        return;
    }
    ll res, k = n;
    for (i = 1; i <= m; i++)
    {
        res = f(k);

        if (res == 0)
        {
            cout << 0 << "\n";
            return;
        }

     k=res;

    }


    cout<<res<<"\n";
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
