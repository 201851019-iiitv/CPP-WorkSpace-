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
const int N = 100005, M = N;
//=================================================================================================================================//


 bool arr[N];
void seive()
{

   
    memset(arr, true, sizeof(arr));
    arr[0]=false;
    arr[1]=false;

    for (ll i = 2; i<= N; i++)
    {

        if (arr[i])
        {
            for (ll j = i * i; j <= N; j*=i)
            {

                arr[j] = false;
            }
        }
    }

   
}

ll number(ll n, ll k)
{

    ll p = 1, count = 0;
    while (p < n)
    {
        p *= k;

        count++;
    }

    if (n == p)
        return count;
    return count - 1;
}

void solve()
{
    ll i, j, n, m;
    in(n);

    ll res, count = 0;
    for (i = 2; i * i <= n; i++)
    {
        if(arr[i])
        {
        m= number(n, i);
        m--;
        count +=m;
        //deb2(m,i);
        }
    }

    res = n - count;

    prt(res);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int test = 1;
    //cin >> test;
    while (test--)
    {
        seive();
        solve();
    }

    return 0;
}