// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a ;
        b >>= 1;
    }
    return res;

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
      ll n,k;
      cin>>n>>k ;

unsigned ll res1=n*(n+1)/2;

ll nth=n/k;

cout<<nth<<" "<<res1<<"\n";

ll sum1=nth*(2*k+(nth-1)*k);
 sum1 /=2;

res1 -=sum1;

ll res2=((k-1)*k)/2;

res2++;

unsigned ll res3=nth*res2;
nth  *=k;


cout<<sum1<<" "<<res1<<"\n";

res1 +=res3;

cout<<res1<<"\n";


    }
    return 0;
}