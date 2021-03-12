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
       int n,m;
       cin>>n>>m;
       int arr[n];
       loop(i,n)
       cin>>arr[i];

    sort(arr,arr+n);

int count=0,sum;
    for(int i=0;i<n;i++)
    {
      sum=arr[i];
   for(int j=0;j<n;j++)
   {
   if(i!=j)
   sum +=arr[j];

   if(sum==m)
   	count++;
   else if(sum>m)
   	break;

    
cout<<sum<<"\n";

   }

    }


      cout<<count<<'\n' ;  
    }
    return 0;
}