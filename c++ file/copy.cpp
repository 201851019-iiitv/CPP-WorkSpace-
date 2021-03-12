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
	freopen("output.txpt","w",stdout);
#endif


    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--){
        int x,y,l,k;
        cin>>x>>y>>l>>k;
      int res=x-y;  
//vector<pair<int,int>>vp;

for(int i=0;i<k;i++)
{

int a,b;
cin>>a>>b;

if(a>=res && l>=b)
{
	res=0;
  
}




}

if(res<=0)
{
cout<<"LuckyChef"<<"\n";

} 
else
cout<<"UnluckyChef"<<"\n";











        
    }
    return 0;
}
