// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

struct interval
{
	int sell,buy;
};




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
    int arr[n];
    loop(i,n)
    {
    	cin>>arr[i];
    }

std::vector<interval> v;
int count=0;

loop(i,n-1)
{

 while(i<n-1 && arr[i+1]<=arr[i])
 	i++;
 if(i==n-1)
 	break;

v[count].buy=i++;

while(i<n && arr[i+1]>=arr[i])
  i++;

if(i==n)
	break;

v[count].sell=i-1;
   

count++;



}

if(count==0)
	cout<<"0" <<'\n' ;
else
{
	ll profit=0;
for(auto x:v)
{

profit +=(x.sell-x.buy);


}
cout<<profit<<"\n";



}







    }
    return 0;
}