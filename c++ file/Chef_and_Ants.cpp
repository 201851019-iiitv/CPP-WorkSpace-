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

const int mod = 1000000007;
const int N = 3e5, M = N;
//=================================================================================================================================//

vi g[N];
int a[N];

void solve()
{
    ll i, j, n, m;

    cin >> n >> m;

    ll arr[m];

    ll nn = 0, kk = 0;

    fo(i, m)
    {
        cin >> arr[i];

        if (arr[i] > 0)
            nn++;
        else if (arr[i] < 0)
            kk++;
    }

    //deb2(nn,kk);

    ll res;

    if (nn > 0 && kk > 0)
    {

        if (nn <= kk)
        {
            ll r1 = nn * (nn - 1) / 2;
            r1 += nn;
            ll r2 = (nn * (2 * kk - nn - 1)) / 2;

            res = r1 + r2;
            cout << res << "\n";
        }
        else
        {

            swap(nn, kk);
            ll r1 = nn * (nn - 1) / 2;
            r1 += nn;
            ll r2 = (nn * (2 * kk - nn - 1)) / 2;
            // deb2(r1,r2);
            // deb2(nn,kk);
            res = r1 + r2;
            cout << res << "\n";
        }
    }
    else
        cout << 0 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
