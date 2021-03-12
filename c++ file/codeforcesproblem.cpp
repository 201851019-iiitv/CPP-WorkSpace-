
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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
       if(a==c)
       {
    
         if((b+d)==a)
         	std::cout<<"YES"<<endl;
         else
         	std::cout<<"NO"<<endl;



       }

       else if(b==c)
       {

     if((a+d)==b)
         	std::cout<<"YES"<<endl;
         else
         	std::cout<<"NO"<<endl;




       }
       else if(a==d)
       {

       	if((b+c)==a)
         	std::cout<<"YES"<<endl;
         else
         	std::cout<<"NO"<<endl;

       }
       else if(b==d)
       {

       	if((a+c)==b)
         	std::cout<<"YES"<<endl;
         else
         	std::cout<<"NO"<<endl;

       }

       else
       	std::cout<<"NO"<<endl;
        
    }
    return 0;
}