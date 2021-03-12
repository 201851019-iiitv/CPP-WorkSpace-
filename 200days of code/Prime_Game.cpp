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
const int N = 1000005;
//=================================================================================================================================//
vector<ll> prime;

ll binary(ll n)
{
ll low=0,high=prime.size()-1,mid;

while(low<=high)
{
  mid=(low+high)/2;

  if(prime[mid]==n)
  return mid;
  
  else if(prime[mid]>n)
  high=mid-1;
  else
  low=mid+1;


}


return high;

}


void seive()
{

    ll i, j;
    prime.push_back(1);

    vector<bool> checkprime(N, true);

    for (i = 2; i * i <= N; i++)
    {
        if (checkprime[i])
        {

            for (j = i * i; j <= N; j += i)
                checkprime[j] = false;
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (checkprime[i])
            prime.push_back(i);
    }
}

void solve()
{
    ll i, j, n, m;
    cin >> n >> m;

ll value=binary(n); // occurance total prime number

  if(value<=m)
  cout<<"Chef"<<"\n";
  else
  cout<<"Divyam"<<"\n";
   

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    seive();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
