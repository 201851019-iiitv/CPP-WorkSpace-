// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

using namespace std;
#define fo(i,n) for(i=0;i<n;i++)
#define foo(i,k,n) for(i=k;i<n;i++)
#define Fo(i,k,n) for(i=n-1;i>=k;i--)
#define ll long long
#define in(x)    cin>>x
#define prt(x)    cout<<x<<"\n"
#define prt2(x,y)    cout<<x<<" "<<y<<"\n"
#define prt3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define pr make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define set(x) memset(x,-1,sizeof(x))
#define tot(arr) arr,arr+sizeof(arr)
//#define set(x) memset(x, -1, sizeof(x))
#define sortall(x) sort(all(x))
#define sorttot(arr) sort(tot(arr))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>    pi;
typedef pair<ll, ll>    pl;
typedef vector<int>        vi;
typedef vector<ll>        vl;
typedef unordered_map<ll,ll>   mp;
typedef unordered_map<char,ll>   mc;
typedef unordered_map<ll,bool>   mb;
typedef vector<pi>        vpi;
typedef vector<pl>        vpl;
typedef vector<vi>        vvi;
typedef vector<vl>        vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}

const ll mod = 1000000007;
//const int N = 3e5, M = N;
//=================================================================================================================================//

void maxo(vector<ll>&v)
{

ll k=v[1]/2;
k=min(k,v[0]);

ll res=k*v[4];

v[0]-=k;


v[1] -=k*2;

v[3]+=res;


}

void  cm(vector<ll>&v)
{
// deb("Helllo");
// deb2(b,N);
ll k=v[2]/3;

k=min(k,v[0]);

ll res=k*v[5];

v[0] -=k;


v[2] -=k*3;
v[3] += res;

}

void ck(vector<ll>&v)
{

ll k=min(v[1],v[2]);
k=min(k,v[0]);

ll res=k*v[6];

v[0] -=k;
v[1] -=k;
v[2] -=k;

v[3]+=res;
}

void solve() {
  ll i, j, n, egg,bar,a,b,c;


cin>>n>>egg>>bar>>a>>b>>c;

vector<ll>v={n,egg,bar,0,a,b,c};
//vector<ll>v1={n,egg,bar,0,a,b,c};

ll minres=INT_MAX;

// let maxo ->1 and cm ->2 ck ->3
    maxo(v);cm(v);ck(v);

  if(v[0]==0)
  {
      minres=min(minres,v[3]);
  }

v={n,egg,bar,0,a,b,c};
maxo(v);ck(v);cm(v);    //132

  if(v[0]==0)
  {
      minres=min(minres,v[3]);
  }

  v={n,egg,bar,0,a,b,c};
cm(v);maxo(v);ck(v);    //213

  if(v[0]==0)
  {
      minres=min(minres,v[3]);
  }


 v={n,egg,bar,0,a,b,c};
cm(v);ck(v);  maxo(v);  //231

  if(v[0]==0)
  {
      minres=min(minres,v[3]);
  }

  v={n,egg,bar,0,a,b,c};
ck(v);  maxo(v); cm(v);  //312

  if(v[0]==0)
  {
      minres=min(minres,v[3]);
  }


 v={n,egg,bar,0,a,b,c};
ck(v);  cm(v); maxo(v);   //321

  if(v[0]==0)
  {
      minres=min(minres,v[3]);
  }



if(minres==INT_MAX)
cout<<-1<<"\n";
else
cout<<minres<<"\n";




}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int test = 1;
    cin >> test;
    while(test--) {
      solve();
    }

    return 0;
}





