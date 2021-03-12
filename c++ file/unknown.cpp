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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n,k;
		cin >> n >>k;
		vector<string>v;
		string s;
		loop(i, n)
		{

			cin >> s;
			v.push_back(s);
		}

		set<string>Set;

		while(k--)
		{

        int p;
        cin>>p;
        for(int i=0;i<p;i++)
        {

          cin>>s;
          Set.insert(s);


        }

		}

//bool y=true;
   for(int i=0;i<n;i++)
   {

     auto it=Set.find(v[i]);
     if(it==Set.end())
     {
       
     	cout<<"NO" <<" ";
     	
     }
     else
     	cout<<"YES" <<' ' ;



   }
  

cout<<endl;




	}
	return 0;
}