// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

const ll x=212072634227239451;


struct triplet{
ll index1,index2,count,product;


};


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


    ios::sync_with_stdio(0);
    cin.tie(0);

   
        int n,m;
        cin>>n>>m;

     ll mat[m][n];
     
     loop(i,n)
     {
    loop(j,m){

  cin>>mat[i][j];
    }

   

vector<triplet>v;
for(int i=0;i<n;i++)
{
	triplet data;
   if(mat[0][i]%x==0)
   {
   data.index1=0;
   data.index2=0;
   data.count=0;
   if(i!=0)
   data.product=mat[0][i]*mat[0][i-1];


   }



}



     }  
        
      return 0;
}