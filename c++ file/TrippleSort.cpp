// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

struct triple{
int first,second,third;

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
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n+1];
        arr[0]=0;
        map<ll,ll>m;

 for(int i=1;i<=n;i++)
 {

    cin>>arr[i];
   
   m[arr[i]]=i;

 }

ll count=0;


vector<triple>res;
for(int i=1;i<=n;i++)
{

if(arr[i]==i)
{

int i1=i;
int i3=m[i];
int i2=m[arr[i]];

if(i1!=i3 && i1!=i2 && i2!=i3)
{

res.push_back({i1,i2,i3});




m[arr[i1]]=i2;
m[arr[i2]]=i3;
m[arr[i3]]=i1;



ll d=arr[i1];

arr[i1]=arr[i3];
arr[i3]=arr[i2];
arr[i2]=d;



count++;


}
else
{

      i1=i;
      i3=m[i];
      i2=m[i3];
   
    //cout<<i1<<" "<<i2<<" "<<i3<<endl;
     res.push_back({i1, i2, i3});

      m[arr[i3]]=i1;
      m[arr[i2]]=i3;
      m[arr[i1]]=i2;


     int a=arr[i1];
     arr[i1]=arr[i3];
     arr[i3]=arr[i2];
     arr[i2]=a;
    


   count++;

    } //else condition




} // if condition





}  // for loop finish





        
    }
    return 0;
}