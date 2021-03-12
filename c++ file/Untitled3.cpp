#include<bits/stdc++.h>

using namespace std;

const int MAX = 1000000;




int main()
{
	
	int n,m;
	cin>>n>>m;

vector<vector<int> > vec; 

	
int arr[n];

for(int i=0;i<n;i++)
{
	
	cin>>arr[i];
	
	
	
	
}

int h[m];

for(int i=0;i<m;i++)
{
	
	cin>>h[i];
}
	int q;
	cin>>q;
	
	Query query[q];    //declare a query
for(int j=0;j<q;j++)	
	{
	int l,r;
	cin>>l>>r;
	query[j].L=l;
	query[j].R=r;
	query[j].index=j;
		
	query[j].result=0;	
	}
	
