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
        ll g;
        cin>>g;
       while(g--) {
        ll n;
        cin>>n;
        ll a,b,c;
        cin>>a>>b>>c;
ll counth=0,countt=0;
        if(a==1)
        {

      counth=b/2;
      countt=n-b/2;


        }
        else
        {
    
    countt=b/2;
      counth=n-b/2;


        }

        if(c==1)
        {

            cout<<counth<<"\n";
        }
        else
            cout<<countt<<"\n";
        

    }
}
    return 0;
}
