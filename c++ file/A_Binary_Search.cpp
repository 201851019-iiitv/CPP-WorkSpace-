// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

#define  ll  long long
# define  loop(x,n)  for(int x = 0; x < n; ++x)
#define   constloop(x,a,n) for(int x = a; x < n; ++x)
#define  revloop(x,a,n)  for(int x = a; x > n; x--)

// ------- above define macros---------------------//


using namespace std;

int bs(ll arr[],ll x,ll n)
{

int low=0,high=n-1,mid;

while(low<=high)
{

mid=(low+high)/2;

if(arr[mid]==x)
return 1;

if(arr[mid]>x)
high=mid-1;
else
{
    low=mid+1;
}





}


return 0;
}


int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    // ll t;
    // //cin>>t;

        ll n,k;
        cin>>n>>k;

        ll arr[n];

        loop(i,n)
        cin>>arr[i];

 ll queries[k];

 loop(i,k)
 cin>>queries[i];

loop(i,k)
{

 if(!bs(arr,queries[i],n))
 cout<<"NO"<<"\n";
 else
 {
     cout<<"YES"<<"\n";
 }
 

}

        
  
    return 0;
}