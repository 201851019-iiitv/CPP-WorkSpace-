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
#define setv(x) memset(x,-1,sizeof(x))
#define tot(arr) arr,arr+sizeof(arr)
#define set(x) memset(x, -1, sizeof(x))
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
const int N = 3e5, M = N;
//=================================================================================================================================//
ll findc(ll n,ll egg,ll bars,ll a,ll b,ll c)
{
    if(n<=0)
    return 0;

  ll r1=0,minres=LONG_MAX;

// only make omlets for n people
  if(2*n<=egg)
  {

    r1=n*a;
    minres=min(minres,r1);

  }

  
// only make chocolate milkshake for n people
  if(3*n<=bars)
  {
      r1=n*b;
      minres=min(r1,minres);

  }
  
 // only make  chocolate cake for n peoples
  if(n<=egg && n<=bars)
  {
      r1=n*c;
       minres=min(r1,minres);
  }

//let make x omlets and n-x chocolate milkshake for n peoples
// min 1 omlets and 1 chocolate milkshake then min 2 egg and 3 bars needed.


if((egg/2 >=1) && ((n - egg/2)*3 <= bars))
{
 
 ll k1=ceil((3*n-bars)/3.0);
 ll k2=egg/2;
ll temp ;
  if(a<b)
  temp=min(n-1,k2);
  else
  temp=max(1ll,k1);

r1=temp*a+(n-temp)*b;

minres=min(r1,minres);

}
  

//deb(minres);
//let make x omlets and n-x chocolate cake for n peoples
// min 1 omlets and 1 chocolate cake then min 3 egg and 1 bars needed.
if((egg-n)>=1 && (2*n-egg)<=bars)
{
ll  k1=n-bars;
ll  k2=egg-n;
ll temp ;
  if(a<c)
  temp=min(n-1,k2);
  else
  temp=max(1ll,k1);

r1=temp*a+(n-temp)*c;

minres=min(r1,minres);

}

 //deb(minres);


//let make x chocolate milkshake and n-x chocolate cake for n peoples
// min 1 chocolate milkshake and 1 chocolate cake then min 3 bars and 1 egg needed.
if(((bars-n)/2)>=1 && ((bars-n)/2)>=(n-egg))
{
ll k1=n-egg;
ll k2=(bars-n)/2;
ll temp ;
if(b<c)
  temp=min(n-1,k2);
  else
  temp=max(1ll,k1);

r1=temp*b+(n-temp)*c;

minres=min(r1,minres);
}

//deb(minres);

///All three are included 
// min 1 omlete ,1 chocolate milkshake ,1 chocolate bars then min 3 egg and 4 bars needed

if(n>=3 && egg>=3 && bars>=4)
{

 r1=a+b+c+findc(n-3,egg-3,bars-4,a,b,c);
minres=min(minres,r1);


}



return minres;


}




void solve() {
  ll i, j, n,egg,bars,a,b,c;

  cin>>n>>egg>>bars>>a>>b>>c;

 ll res=  findc(n,egg,bars,a,b,c);

if(res!=LONG_MAX)
cout<<res<<"\n";
else
{
    cout<<-1<<"\n";
}

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





