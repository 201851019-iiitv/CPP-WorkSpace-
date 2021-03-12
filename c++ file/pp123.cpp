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
        ll n,k;
        cin>>n>>k;

if(k<n)
{

cout<<k<<" \n";


}
else
{

//ll count=k;
ll s=1;

for(ll i=n+1;i<10000000000;i +=n)
{

  s +=n-1;

if(k<=s)
{

for(int j=i;j>=0;j--)
{

if(j%n!=0)
	s--;

if(s==k)
{
	cout<<j<<"\n";
	break;
}

}


break;



}

}


}

        
    }
    return 0;
}