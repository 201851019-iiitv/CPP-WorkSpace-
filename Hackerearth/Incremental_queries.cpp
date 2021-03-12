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

void solve()
{
    ll i, j, n, q;
    in(n);
    in(q);


unordered_map<ll, ll> mp;
    ll arr[n];
    fo(i, n)
    {
         in(arr[i]);
         mp[arr[i]]++;

    }


    // ll maxoccur[n];

    // maxoccur[0]=0;
    // foo(i,1,n)
    // {

    // if(mp[maxoccur[i-1]]>=mp[arr[i]])
    //    maxoccur[i]=maxoccur[i-1];
    // else
    //    maxoccur[i]=i;


    // }

    // for(auto x:mp)
    // {
    //     cout<<x.first<<" "<<x.second<<"\n";
    // }

   priority_queue<ll,ll>pq; 
    int qtype;
    ll l, r;
    fo(i, q)
    {
        cin >> qtype;
        in(l);
        in(r);

        if (qtype == 1)
        {
            mp[arr[l-1]]--;
            arr[l - 1] = r;
            mp[r]++;
        }
        else
        {
            ll count = 0;
            ll maxv = 0;
            for (auto &x : mp)
            {
                maxv = max(maxv, x.second);
            }
            ll k1 = r - l + 1;

            count = k1 - maxv;

            prt(count);
        }
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
