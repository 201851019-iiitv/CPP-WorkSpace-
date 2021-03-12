// Created by  Ambesh kumar
#include "bits/stdc++.h"

#define  ll  long long  
# define  loop(x,n)  for(int x = 0; x < n; ++x)  
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  
#define  revloop(x,a,n)  for(int x = a; x > n; x--) 

using namespace std;

std::vector<int> binary(ll n)
{

vector<int> v;

while(n>0)
{

int rem=n%2;
v.push_back(rem);

n /=2;


}


reverse(v.begin(),v.end());


return v;

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
      ll x,y,l,r;
      cin>>x>>y>>l>>r;

vector<int>vx1=binary(x);
vector<int>vy1=binary(y);
vector<int> vr1=binary(r);
ll res;

int max1=max(vy1.size(),vx1.size());

if(vr1.size()>max1)
{

    res=x|y;


}


else if (max1==vr1.size())
{

for(int i=0;i<max1;i++)
{

if(vr1[i]=='1' && vx1[])


}



}




        
    }
    return 0;
}