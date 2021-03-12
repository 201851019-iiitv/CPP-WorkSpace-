
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
        int n;
        cin>>n;
        int arr[n],even=0,odd=0;
        loop(i,n)
        {
        cin>>arr[i] ;
        if(arr[i]%2==0)
        	even++;
        else
        	odd++;
        }
        
if(n%2!=0)
	cout<<"NO" <<'\n' ;
else if((even%2)!=(odd%2))
     cout<<"NO" <<'\n' ;	
else
{
 

    




}


    }
    return 0;
}