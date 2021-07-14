// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define foo(i, k, n) for (i = k; i < n; i++)
#define Fo(i, k, n) for (i = n - 1; i >= k; i--)
#define ll int
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
const int N = 1e5 + 5, maxN = 17;
//=================================================================================================================================//

//TODO:find and store level of each node globally.
//TODO:make adjacent list.
//TODO: make lca (longest common ancestor reference go to L03 and L04).
//TODO: calculate distance between two node using formula dist(a,b)=level[a]+level[b]-2*level[lca(a,b)];
//reference article https://www.youtube.com/watch?v=ZPa1Dwr9vAg

vector<ll> adj[N];
ll lvl[N];
ll lca[N][maxN];

void dfs(ll node, ll level, ll par)
{
  lvl[node]=level;
  lca[node][0]=par;

for(ll child: adj[node]){

  if(child!=par){
    dfs(child,level+1,node);
  }
}


}

void init(ll n)
{
ll i,j,par;
  dfs(1, 0, -1);
  for(i=1;i<=log2(n);i++){
    for(j=1;j<=n;j++){
      if(lca[j][i-1]!=-1){
        par=lca[j][i-1];
        lca[j][i]=lca[par][i-1];
      }
    }
  }
}

ll getLca(ll a,ll b,ll n){
  if(lvl[a]>lvl[b]) swap(a,b);

  ll d=lvl[b]-lvl[a];

while(d>0){
 ll i=log2(d);
  b=lca[b][i];
  d -=1<<i;
}

if(a==b) return a;

for(ll i=log2(n);i>=0;i--){
 if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i]){
   a=lca[a][i];
   b=lca[b][i];
 }
}

return lca[a][0];
}

ll getDist(ll a,ll b,ll n){
  ll lca=getLca(a,b,n);
  return lvl[a]+lvl[b]-2*lvl[lca];
}

void solve()
{
  ll i, j, n, k, q, u, v,d;

  cin >> n >> q;

  fo(i, n-1)
  {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(i=1;i<=n;i++){
    for(j=0;j<=log2(n);j++){
      lca[i][j]=-1;
    }
  }

  init(n);

while(q--){
  cin>>k>>d;

ll arr[k];
fo(i,k)
cin>>arr[i];

ll count=0;
for(i=0;i<k;i++)
{
  for(j=i+1;j<k;j++){
    if(lvl[arr[i]]+lvl[arr[j]]>=d){
    ll dist=getDist(arr[i],arr[j],n);
    if(dist==d)
    count++;
    }
  }
}

cout<<count<<"\n";
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
    solve();
  }

  return 0;
}
