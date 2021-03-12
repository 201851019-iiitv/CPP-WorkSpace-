#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<bitset>
#include<cstring>
#include<stack>
#include<queue>
#include<set>
#include<chrono>
#include<list>
#include<climits>
#include<iomanip>
#include<bits/stdc++.h>
#define arrsize 100001
#define dpsize 1001
#define vpp vector<PP>
#define vll vector<ll>
#define vcc vector<char>
#define endl "\n"
#define vbb vector<bool>
#define w(t) while(t--)
#define PP pair<ll,ll>
#define test(x) ll t; cin>>t; w(t) x()
#define __lb lower_bound
#define __ub upper_bound
#define szs(x) x.length()
#define szv(x) x.size()
#define INF 1999999996000000010
#define ll long long int
#define takeINP(arr,n) for(long long int i=0;i<n;i++) cin>>arr[i];
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define mem(arr) memset(arr,0,sizeof(arr));
#define MOD 1000000007
#define rsz(x,n) x.resize(n)
#define rsr(x,n) x.reserve(n) 
#define mp(a,b) make_pair(a,b)
#define float long long double
#define pb push_back
#define print(arr,s,e) f(i,s,e) cout<<arr[i]<<" "; cout<<endl;
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define vll vector<ll>
#define triplet pair<ll,pair<ll,ll> >
#define MITR(a,b) map<a,b>::reverse_iterator 
using namespace std;
using namespace chrono;

ll dp[4020][4020];
ll pref[4020];

ll Dfn(ll idx,ll taken,ll n,ll k,vll &arr){
    if(taken>=k and (pref[idx]-taken>=k)) return 0;
    else if(idx>=n)  return 1e10;
    else if(dp[idx][taken]!=-1) return dp[idx][taken];

    ///so now two choice again
    ll c1 = Dfn(idx+1,min(taken+arr[idx],pref[idx]-taken),n,k,arr);
    ll c2 = Dfn(idx+1,min(pref[idx]-taken+arr[idx],taken),n,k,arr);

    return dp[idx][taken] = 1+min(c1,c2);
}

ll givemedp(vll &arr,ll n,ll k){
    f(i,0,n/2) swap(arr[i],arr[n-i-1]);
    cf(i,0,n+10){
        pref[i]=0;
        cf(j,0,k+10) dp[i][j]=-1;
    }
    cf(i,1,n) pref[i]=pref[i-1]+arr[i-1];

   for(int i=0;i<=n;i++)
    cout<<pref[i]<<"\n";


    ll ans = Dfn(0,0,n,k,arr);
    return ans>1e9?-1:ans;
}

void solve(){
    ll n,k; cin>>n>>k;
    vll arr(n,0);
    takeINP(arr,n);
    sort(all(arr));
    if(n==1){
        cout<<"-1"<<endl;
        return;
    }
    cout<<givemedp(arr,n,k)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //auto start1 = high_resolution_clock::now();
    // solve();
    test(solve);
}