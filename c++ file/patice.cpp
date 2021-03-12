// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

int power(int x, int y) {  
   if (y == 0) 
      return 1; 
   else if (y%2 == 0) 
      return power(x, y/2)*power(x, y/2); 
   else
      return x*power(x, y/2)*power(x, y/2);    
} 


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

    	//cout<<t<<" t"<<endl;
        ll n,k;
        cin>>n>>k;

      
ll p1=n/k;

bool y=true;
ll res=p1*(k-1);
ll res1=(p1-1)*(k-1);
ll d=n-res;
ll d1=n-res1;

if(p1%2!=0  && p1>0)
{

if(d%2!=0)
{
	y=false;
	cout<<"YES"<<endl;

	loop(i,k-1)
	{

cout<<p1<<" ";



	}

	cout<<d<<"\n";
}




}
else
{

if(p1>0 &&d%2==0)
{
	y=false;
	cout<<"YES"<<endl;

	loop(i,k-1)
	{

cout<<p1<<" ";



	}

	cout<<d<<"\n";
}


}


if((p1-1)%2!=0 && y && (p1-1)>0)
{
if(d1%2!=0)
{
	y=false;
	cout<<"YES"<<endl;

	loop(i,k-1)
	{

cout<<(p1-1)<<" ";



	}

	cout<<d1<<"\n";
}

}
else
{
if(y &&(p1-1)>0)
{
if(d1%2==0)
{
	y=false;
	cout<<"YES"<<endl;

	loop(i,k-1)
	{

cout<<(p1-1)<<" ";



	}

	cout<<d1<<"\n";
}
}

}
if(y)
cout<<"NO"<<endl;



        
    }
    return 0;
}