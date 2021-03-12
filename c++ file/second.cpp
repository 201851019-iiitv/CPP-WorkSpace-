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
    int n;
    while(cin>>n){
       
       // int n;
       // cin>>n;

     int p1=(n/2);
     int p2=(n/3);
     int p3=(n/4);
     int max=Int_MIN;

while(p1>max)
{

  int a1=(p1/2);
  int a2=(p1/3);
  int a3=(p1/4);

  p1=a1+a2+a3;
if(p1>max)
{

	max=p1;
}


}


     long sum=p1+p2+p3;

     if(sum>n)
     {


     	cout<<sum<<"\n";
     }
     else
     	cout<<n<<"\n";



    }
    return 0;
}