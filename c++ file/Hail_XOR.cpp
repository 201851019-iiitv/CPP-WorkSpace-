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


long long binpow(long long a, long long b) {
   
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a ;
        b >>= 1;
    }
    return res;
}



void solve()
{
  ll i, j, n, x;

  cin >> n >> x;

  ll arr[n];

  fo(i, n)
  {
    cin >> arr[i];
  }

  i = 0, j = 0;

  ll k1=0, k2=0;

  while (i < n - 1 && x>0)
  {

    while (i < n - 1 && arr[i] == 0)
              i++;

      if(arr[i]!=0)
      k1 = log2(arr[i]);

      
    
    for(j=i+1;j<n-1;j++)
    {
        
     k2= arr[j]^(ll)binpow(2, k1);
     
     if(k2<arr[j])
       break;
    
    
        
    }

    if (i < n - 1 && j <n )
    {
     
      arr[i] ^= (ll)binpow(2, k1);
      arr[j] ^=(ll)binpow(2, k1);
     
      x--;
    }
      
    //deb2(i,x);
    
  }




//deb(x);
if(n==2 &&x>0 && x%2!=0)
{
  arr[n-2] ^=1;
  arr[n-1]^=1;
}

  fo(i, n)
  {
    cout << arr[i] << " ";
  }

  cout << "\n";
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
