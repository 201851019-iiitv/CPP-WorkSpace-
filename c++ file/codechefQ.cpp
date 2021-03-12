#include <iostream>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	 long long int t,N,p;
	long long int l,K;
	cin>>t;
	for(int i=0;i<t;i++)
    {
        p=l=0;
        cin>>N>>K;
        int a[N];
        for(int j=0;j<N;j++)
        {
            cin>>a[j];
        }
        for(int k=0;k<N;k++)
        {
            if(a[k]>=K)
            {
               l=a[k]-K;
            }
            else
            {
                if(a[k]+l>=K)
                {
                    l= l+a[k]-K;
                }
                else
                {
                    cout<<"NO ";
                    cout<<k+1<<endl;
                    p++;
                }
            }
            if(p>0)
                break;
        }
        if(p==0)
        {
            cout<<"YES"<<endl;

        }
    }
    return 0;
}

