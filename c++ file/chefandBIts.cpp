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
      //  ll arr[n];
        

set<int> s;
int p;
loop(i,n)
{


cin>>p;
s.insert(p);


}


vector<int>v;

for(int x:s)
{
    
    v.push_back(x);
    
}

int count=1,maxcount=0,k;

for(int i=1;i<v.size();i++)
{
    
     k=v[i]-v[i-1];
    if(k==1)
    count++;
    else
    count=1;
    
    maxcount=max(count,maxcount);
    
    
    
}


if(maxcount==0)
  maxcount++;



cout<<maxcount<<"\n";


        
    }
    return 0;
}