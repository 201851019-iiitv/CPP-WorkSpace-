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


void solve() {
  ll i, j, n, k;
   in(n);

ll res=0;

if(n>=4)
{



   if(n%4==0)
   {
   res +=11*n+16;
   cout<<res<<"\n";
   return ;
   }

  //deb2(n,res);
    if(n%4==1)
    {
     res +=11*(n-1)+32;

    }
   else if(n%4==2)
   res +=11*(n-2)+44;
  else
   res +=11*(n-3)+55;



cout<<res<<"\n";
}
else{

  if(n==1)
  prt(20);
  else if(n==2)
  prt(36);
  else if(n==3)
  prt(51);


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





