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


 vector<pair<ll,char>> lead;
        int n;
        cin>>n;
        ll player1[n];
        ll player2[n];
        loop(i,n)
        {
         cin>>player1[i]>>player2[i];

        }
       






for(int i=0;i<n;i++)
{


if(i==0)
{

ll s1=0;
if(player1[0]>player2[0])
{

s1=player1[0]-player2[0];
lead.push_back(make_pair(s1,'1'));

}
else if(player1[0]<player2[0])
{

	s1=player2[0]-player1[0];
	lead.push_back(make_pair(s1,'2'));
}
else
{

ll s=0;

lead.push_back(make_pair(s,'0'));

}


}
else
{
player1[i]=player1[i]+player1[i-1];

player2[i]=player2[i]+player2[i-1];

ll sum1=player1[i];
ll sum2=player2[i];

if(sum1>sum2)
{

   ll s=(int)sum1-sum2;
   lead.push_back(make_pair(s,'1'));

}

else if(sum1<sum2)
{

ll s=(int)sum2-sum1;
   lead.push_back(make_pair(s,'2'));

}


else
{

ll s=0;

lead.push_back(make_pair(s,'0'));

}


}

}

sort(lead.begin(),lead.end());







    cout<<lead[lead.size()-1].second<<" "<<lead[lead.size()-1].first<<"\n";
    return 0;
}