// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;



struct Test 
{ 
   int f, s,third; 
}; 



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
while(t--)
{
   int n,k;
   cin>>n>>k;
   int arr[n+1];
   arr[0]=0;

  map<int,int>m;

   vector<Test> v;
  for(int i=1;i<=n;i++)
  {
  cin>>arr[i];
   m[arr[i]]=i;
  }

int i1,i2,i3;
int count=0;
for(int i=1;i<=n-2;i++)
{

    if(arr[i]!=i)
    {
  
       i1=i;
       i3=m[i];
       i2=m[i3];
   
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
if((i+1)!=arr[i])
i2=m[i+1];
else
i2=m[i+2];

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

cout<<"arr bcome"<<" "<<i<<" ";
  loop(j,n+1)
{

	cout<<arr[j]<<" ";
}

cout<<endl;


}



  }
  











bool y=true;
for(int i=1;i<=n;i++)
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