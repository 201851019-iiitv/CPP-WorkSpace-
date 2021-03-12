// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x >=n; x--) 

using namespace std;

 ll arr[500005];


int main()
{

for (int i = 0; i <500005 ; ++i)
{
	arr[i]=0;
}


#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<n<<'\n' ;
        

int i=3;
while(arr[n]==0)
{


int mid=i/2;
  arr[i]=(ll)((4*i-4)*mid)+arr[i-2];

  i+=2;
//cout<<arr[n]<<"\n";
}


cout<<arr[n]<<"\n";

   
    }
    return 0;
}