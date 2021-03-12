// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

ll min(ll a,ll b,ll c,ll d)
{

 if(a<=b &&a<=c && a<=d)
 	return a;
 else if(b<=a && b<=c && b<=d)
 	return b;
 else if(d<=a && d<=c && d<=b)
 	return d;
 else
 	return c;


}

ll A,B,C,D;

ll mincost(int n)
{
    if(n==0)
    	return 0;
    if(n==1)
    	return D;
    
cout<<n <<'\n' ;
  
    return  min(A+mincost(n/2),B+mincost(n/3),C+mincost(n/5),D+mincost(n-1));

}

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
       ll n ,a,b,c,d;
        cin>>n>>a>>b>>c>>d;

        A=a,B=b,C=c,D=d;
        ll res =mincost(n);
        cout<<res <<'\n' ;
        
    }
    return 0;
}