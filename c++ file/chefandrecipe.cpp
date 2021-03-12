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

     int arr[n];
    vector<int> v;
       loop(i,n)
       {
       cin>>arr[i];
        if(arr[i]==1)
        	v.push_back(i);

      }
      int len=v.size();
   
   if(len==0)
   	cout<<"0"<<"\n";
   else if(len==1)
   		cout<<"-1"<<"\n";
   else
   {

   ll res=0;


   res += abs(v[0] - v[1]); 
   res += abs(v[len-1] - v[len-2]); 



   for(int i=2;i<(len-2);i++)
   {
//cout<<i<<" "<<len-1 <<'\n' ;

int a=abs(v[i] - v[i-1]);
int b=abs(v[i] - v[i+1]);
       if(b<=a)
       {
         res +=b;
         i++;

       }
       else
       	res +=a;




   }

if(len==2)
	res /=2;
   cout<<res<<"\n";


   }

      

    }
    return 0;
    }
