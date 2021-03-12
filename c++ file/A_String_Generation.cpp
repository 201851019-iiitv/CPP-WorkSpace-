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

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;

        string s="";

 for(int i=0;i<k;i++)
 s +='a';

 for(int j=0;j<n-k;j++)
 {
    if(j%3==0)
    s+='b';
    else if(j%3==1)
    s+='c';
    else
    {
        s+='a';
    }
    



 }



cout<<s<<"\n";
        
    }
    return 0;
}