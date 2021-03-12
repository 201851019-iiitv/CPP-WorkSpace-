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
    ll i, j, n, m;
    in(n);

    ll arr[n];
    fo(i, n)
            cin >>
        arr[i];
   


ll res=0,sum=0;
   vector<ll>v;
   fo(i,n)
   {
       sum=0;
     while(i<n && arr[i]>=0)
     {
         sum +=arr[i];
         i++;
     }

      if(sum>0)
	  {
     v.push_back(sum);
	 i--;
	  }

   }  

   for(auto x:v)
   cout<<x<<" ";
   cout<<"\n";

if(v.size()==0)
cout<<0<<"\n";
else if(v.size()==1)
cout<<v[0]<<"\n";
else
{
    
    ll max,second_max;
if(v[0] > v[1]) {
 second_max = v[1];
 max = v[0];
} else {
 second_max = v[0];
 max = v[1];
}
for(int i = 2; i <v.size(); i++){  
    if(v[i] >= max){  
        second_max=max;
        max=v[i];          
    }
    else if(v[i] > second_max){
        second_max=v[i];
    }
}
res=max+second_max;
cout<<res<<"\n";
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
