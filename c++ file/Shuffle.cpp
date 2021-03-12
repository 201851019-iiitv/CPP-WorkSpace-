
#include<bits/stdc++.h>
using namespace std;
#define  ll  long long  //define a macro variable of long long type
# define  loop(x,n)  for(int x = 0; x < n; ++x)  // define a for loop
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  //define a for loop with start a const
#define  revloop(x,a,n)  for(int x = a; x > n; x--) // rev for loop
//#define   vect vector<ll>  // define a vector of longlong type;



int  main() {

ios_base::sync_with_stdio(false);
   cin.tie(NULL);
int t;
cin>>t;
while(t--)
{
int n,k;
cin>>n;
int  arr[n];
vector<int> v;
int  p=k;
loop(i,n)
{

    cin>>arr[i];
}

loop(i,n)
{


    if(i==p)
    {

        v.push_back(arr[i]);
        p=i+k;
    }
}


for(int s:v)
{
    cout<<s<<" ";
}
cout<<endl;

sort(v.begin(),v.end());

arr[0]=v[0];
int d=k;
int j=1;
loop(i,n)
{
    if(i==d)
    {
        arr[i]=v[j];
        j++;
    }



}

bool flag=true;
loop(i,n-1)
{
    if(arr[i]>arr[i+1])
    {
        flag=false;
        break;
    }


}

if(flag)
    cout<<"yes"<<endl;
else
    cout<<"no"<<endl;





}


return 0;
}
