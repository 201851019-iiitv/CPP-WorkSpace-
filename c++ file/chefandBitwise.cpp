// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif


    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        ll x,y,l,r;
        cin>>x>>y>>l>>r;

 ll res=(x&r)|(y&r);
 cout<<res<<"\n";
        
    }
    return 0;
}