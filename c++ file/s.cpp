#include "bits/stdc++.h"
#define  ll  long long  
using namespace std;

int power(ll a,ll b)
{

ll r=1;
while(b>0)
{

if(b&1)
	r=r*a;

a=a*a;

b=b/2;

}

int p1=r%10;
return p1;
}
int main()
{ int t;cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
     int res=power(a,b); cout<<res<<"\n";     
    }
    return 0;
}