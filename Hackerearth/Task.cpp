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


struct Edge
{
 ll intial, end;
};

struct node
{
 ll parent, rank;
};


ll find_Absolute_Parent(ll vertex, vector<node> &dsuf)
{
  if (dsuf[vertex].parent == -1)
    return vertex;

  return dsuf[vertex].parent = find_Absolute_Parent(dsuf[vertex].parent, dsuf);
}

void union_value(ll a, ll b, vector<node> &dsuf)
{


// a = find_Absolute_Parent(a, dsuf);

//    b = find_Absolute_Parent(b, dsuf);
 

//deb2(a,b);

  if (dsuf[a].rank == dsuf[b].rank)
  {
    dsuf[a].parent = b;
    dsuf[b].rank += 1;
  }
  else if (dsuf[a].rank >dsuf[b].rank)
  {
    dsuf[b].parent = a;
  }
  else{
    dsuf[b].parent = a;
  }

}




void solve()
{
    ll i, j, n, k, m;
  cin >> n>>m;

  vector<Edge> edge;    

vector<node>dsuf;

dsuf.resize(n+1);
	for(int i=1;i<=n;++i)	
	{
		dsuf[i].parent=-1;
		dsuf[i].rank=0;
	}

fo(i,m)
{

    cin>>j>>k;

 edge.push_back({j,k});
    
}

 i = 0;

  while (i < m )
  {
     
    ll absolut_Parent_of_intial = find_Absolute_Parent(edge[i].intial, dsuf);

    ll absolut_Parent_of_end = find_Absolute_Parent(edge[i].end, dsuf);

    

    if (absolut_Parent_of_intial != absolut_Parent_of_end) // if both absolute parent are same then they will form a cycle
    {
      //deb2(edge[i].intial,edge[i].end);
      union_value(absolut_Parent_of_intial, absolut_Parent_of_end, dsuf);
      //deb2(absolut_Parent_of_intial,absolut_Parent_of_end);
    
    }
    
    i++;
  }

 //deb(i);



for(i=1;i<=n;i++)
{
    //deb(i);
   find_Absolute_Parent(i,dsuf);
//dsuf[i].parent=k;

}




for(i=1;i<=n;i++)
{

   if(dsuf[i].parent==-1)
   dsuf[i].parent=i;

}


// for(i=1;i<=n;i++)
// {

//   cout<<dsuf[i].parent<<" ";

// }
// cout<<"\n";


unordered_map<ll,ll>mp;

for(i=1;i<=n;i++)
{

   mp[dsuf[i].parent]++;

}

ll res=0;

for(auto &x:mp)
{

for(auto &y:mp)
{
  if(x.first!=y.first)
  {
   res +=x.second*y.second;

  }


}

}

cout<<res<<"\n";



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
