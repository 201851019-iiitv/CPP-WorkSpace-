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
int t;
cin>>t;
while(t--)
{
   ll n,k;
   cin>>n>>k;
   ll arr[n+1];
   arr[0]=0;

 vector<pair<ll,ll>>vp;

   vector<Test> v;
  for(int i=1;i<=n;i++)
  {
  cin>>arr[i];
   if(arr[i]!=i)
    {

  vp.push_back(make_pair(arr[i],i));

    }
  }





ll i1,i2,i3,j=0;
ll count=0;
for(auto it=vp.begin();it!=vp.end();it++)
{

    i1=it->second;
    i3=vp[i1].second;
    i2=vp[i3].second;

    cout<<i1<<" "<<i2<<" "<<i3<<endl;

    if(i1!=i2 && i2!=i3 && i1!=i3)
    {

      v.push_back({i1, i2, i3});
      ll a=arr[i1];
     arr[i1]=arr[i3];
     arr[i3]=arr[i2];
     arr[i2]=a;
     count++;

    }
    else
    {

    it++;
  i2=it->second;
  v.push_back({i1, i2, i3});
      ll a=arr[i1];
     arr[i1]=arr[i3];
     arr[i3]=arr[i2];
     arr[i2]=a;
     count++;





    }

    vp.erase(vp.begin()+i1);
    vp.erase(vp.begin()+i2);
    vp.erase(vp.begin()+i3);

    cout<<"arr bcome"<<" "<<j<<" ";
  loop(j,n+1)
{

  cout<<arr[j]<<" ";
}

cout<<endl;
j++;

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