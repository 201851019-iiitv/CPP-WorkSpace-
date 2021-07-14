/*
----------------------------------------------------------------------------
        Name:Ambesh Kumar
        StudentID:201851019
----------------------------------------------------------------------------
*/



#include <bits/stdc++.h>

/// This define function used only for debugging purpose
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;


bool check(vector<bool> v)
{
	for (int i = 0; i < v.size(); i++)
	{

		if (!v[i])
			return false;
	}

	return true;
}

int findmin(vector<int> v, vector<bool> processed)
{

	int index = -1, minv = INT_MAX;

	for (int i = 0; i < v.size(); i++)
	{
		if (!processed[i] && v[i] < minv)
		{
			minv = v[i];
			index = i;
		}
	}

	return index;
}

int main()
{

  int n;

  vector<int>v;

  cin>>n;

int a;

for(int i=0;i<n;i++)
{
cin>>a;

v.push_back(a);


}

	int adjacent[n][n];


	memset(adjacent, 0, sizeof(adjacent));


for(int i=0;i<n;i++)
{

  if(v[i]!=-1)
   adjacent[v[i]][i]=i;


}


int maxsum=-1,index=-1,sum;

for(int i=0;i<n;i++)
{
  sum=0;
for(int j=0;j<n;j++)
{

sum +=adjacent[i][j];

}

if(sum>maxsum)
{
  maxsum=sum;
  index=i;
}


}




cout<<index<<"\n";



}
