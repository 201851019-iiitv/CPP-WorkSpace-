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
        string s;
        cin>>s;

       int zero=0,one=0;
       
       int n=s.length();
       loop(i,n)
       {
             if(s[i]=='0')
             	zero++;
             else
             	one++;

       } 
        
       if(zero==1 &&(s[0]=='0' ||s[n-1]=='0'))
       	cout<<"0" <<'\n' ;
       else if(one==1 &&(s[0]=='1' ||s[n-1]=='1'))
       	cout<<"0" <<'\n' ;
       else
       {

       	  int res=min(zero,one);

       	  cout<<res <<'\n' ;
       }


    }
    return 0;
}