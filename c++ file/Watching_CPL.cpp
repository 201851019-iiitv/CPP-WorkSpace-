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

ll t[4005][4020];
ll totalsum[4020];

ll getcount(ll sum1, ll k, ll n, ll arr[])
{

    //deb2(sum1,(totalsum[n-1]-sum1));
    if (n <= 0)
        return ((sum1 >= k) && ((totalsum[n - 1] - sum1) >= k)) ? 0 : INT_MAX;

    if (sum1 >= k && (totalsum[n - 1] - sum1) >= k)
        return 0;

    if (t[n][sum1] != -1)
        return t[n][sum1];

    return t[n][sum1] = min(1 + getcount(sum1 + arr[n - 1], k, n - 1, arr), 1 + getcount(sum1, k, n - 1, arr));
}

void solve()
{
    ll i, j, n, k;

    cin >> n >> k;

    ll arr[n];

    fo(i, n)
            cin >>
        arr[i];

    sort(arr, arr + n);
    totalsum[n - 1] = arr[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        totalsum[i] = totalsum[i + 1] + arr[i];
    }



fo(i,n+5)
{

    fo(j,totalsum[0]+5)
    t[i][j]=-1;
}
    // fo(i,n)
    // deb(totalsum[i]);

    // reverse(arr, arr + n);

    ll count = getcount(0, k, n, arr);

    //deb(count);
    if (count < INT_MAX)
        cout << count + 1 << "\n";
    else
    {
        cout << "-1"
             << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int test = 1;
    cin >> test;
    while (test--)
    {
        //memset(t, -1, sizeof(t));
        //memset(totalsum,0,sizeof(totalsum));
        solve();
    }

    return 0;
}
