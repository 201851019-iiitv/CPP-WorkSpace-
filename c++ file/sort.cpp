// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define ss(s)    scanf("%s",s)
#define pi(x)    printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>    pii;
typedef pair<ll, ll>    pl;
typedef vector<int>        vi;
typedef vector<ll>        vl;
typedef vector<pii>        vpii;
typedef vector<pl>        vpl;
typedef vector<vi>        vvi;
typedef vector<vl>        vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
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


int getMinDiff(int arr[], int n, int k) {
      
      
      vector<pair<int,int>>v1;
       vector<pair<int,int>>v2;
       
       int a1,a2;
       for(int i=0;i<n;i++)
       {
          a1=arr[i]+k;
          a2=arr[i]-k;
          v1.push_back(mp(a1,i));
          
          if(a2<0)
          v2.push_back(mp(a1,i));
          else
          v2.push_back(mp(a2,i));
          
           
       }
       
       
       sort(v1.begin(),v1.end());
       
       sort(v2.begin(),v2.end());
     
      
      int min1=v1[0].first;
      int max1=v1[n-1].first;
      
       int min2=v2[0].first;
      int max2=v2[n-1].first;
      
      
      int r1=min(min1,min2);
      int r2=min(max1,max2);
      
      
      
      return (r2-r1);
      
         
    }



void solve() {
  ll i, j, n, m;

int k;
cin>>k;
cin>>n;

int arr[n];

fo(i,n)
cin>>arr[i];


int k1=getMinDiff(arr,n,k);
deb(k1);


}







int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}





