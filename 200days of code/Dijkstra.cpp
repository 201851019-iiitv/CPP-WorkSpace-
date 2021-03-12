#include <bits/stdc++.h>

/// This define function used only for debugging purpose
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl


using namespace std;




int main()
{

	cin >> n >> m;
	vector < vector<int>edges(m);

	unordered_map<pair<int, int>, int>mp;


	int a, b, c;

	for (int i = 0; i < m; i++)
	{

		cin >> a >> b >> c;

		edges[a].push_back(b);
		edges[b].push_back(a);

		mp[ {a, b}] = c;



	}

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>mq; // mq.push()  ,mq.pop() ,mq.top();

	mq.push({0, 0});














}