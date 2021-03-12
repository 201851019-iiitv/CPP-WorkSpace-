// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;



struct Test 
{ 
   ll f, s,third; 
}; 



int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif


    ios::sync_with_stdio(0);
    cin.tie(0);
ll t;
cin>>t;
while(t--)
{
   ll n;
   ll k;
   cin>>n>>k;
   ll arr[n+1];
   arr[0]=0;

  map<ll,ll>m;

   vector<Test> v;
  for(ll i=1;i<=n;i++)
  {
  cin>>arr[i];
   m[arr[i]]=i;
  }

ll i1,i2,i3;
ll count=0;
for(ll i=1;i<=n-2;i++)
{

    if(arr[i]!=i)
    {
  
       i1=i;
       i3=m[i];
       i2=m[i3];
       ll s=i2;
       while(s==m[arr[s]])
       {
        
        s++;


       }
       i2=s;
   
    //cout<<i1<<" "<<i2<<" "<<i3<<endl;


      if(i1!=i2  && i2!=i3 && i1!=i3)
      {
     v.push_back({i1, i2, i3});

      m[i]=i1;
      m[arr[i1]]=i2;
      m[arr[i2]]=i3;


     int a=arr[i1];
     arr[i1]=arr[i3];
     arr[i3]=arr[i2];
     arr[i2]=a;
    


   count++;

    }

else
{

ll j=i;
while(arr[j]==j ||j==i1 || j==i3)
{

  j++;
}

if(j!=0 && j<n)
i2=j;


v.push_back({i1, i2, i3});

      m[i]=i1;
      m[arr[i1]]=i2;
      m[arr[i2]]=i3;



     ll a=arr[i1];
     arr[i1]=arr[i3];
     arr[i3]=arr[i2];
     arr[i2]=a;
    


   count++;



}

cout<<"arr bcome"<<" "<<i<<" ";
  loop(j,n+1)
{

 cout<<arr[j]<<" ";
}

cout<<endl;


}



  }
  











bool y=true;
for(ll i=1;i<=n;i++)
{
   if(arr[i]!=i)
   {

    y=false;
    break;
   }

}

if(y &&count<=k)
{
cout<<count<<" \n";
 for(auto p:v)
 {

cout<<p.f<<" "<<p.s<<" "<<p.third<<" \n";


 }

}
else
  cout<<"-1"<<endl;




   }

    return 0;
}