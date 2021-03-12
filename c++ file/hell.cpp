// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

bool check(ll x,int k ,int n)
{

int s1=(x/k)*(x%k);

if(s1==n)
	return true;
return false;


}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


    ios::sync_with_stdio(0);
    cin.tie(0);

        int n,k;
        cin>>n>>k;
ll res=INT_MAX;
       for(int i=1;i<=n;i++)
       {

        if(n%i==0)
        {
   int a=n/i;
   int b=i;

   ll p=(ll)(a*k+b);

   ll q=(ll)(b*k+a);
   ll p1=(ll)(a*k-b);
   ll q1=(ll)(b*k-a);

if(check(p,k,n))
res =min(res,p);
if(check(q,k,n))
res =min(res,q);
if(check(p1,k,n))
res =min(res,p1);
if(check(q1,k,n))
res =min(res,q1);



        }



       }


       cout<<res <<'\n' ;
        
  
    return 0;
}