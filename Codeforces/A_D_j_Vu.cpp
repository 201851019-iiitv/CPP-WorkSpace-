/*
----------------------------------------------------------------------------
        Name:Ambesh Kumar(201851019)
        Name:Ankur Chanderia(201851023)
        Name:Deepak Bethamalla(201851033)
----------------------------------------------------------------------------
*/

#include <bits/stdc++.h>

/// This define function used only for debugging purpose
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

int main()
{

	int n, e; //number of vertex and edges.

	cin >> n >> e;

	int dp[n][n]; // precomputed table for dist.

	// intialize all value as infinite.

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)

			if (i == j)
				dp[i][j] = 0;
			else
				dp[i][j] = INT_MAX;

	}


	int src, dest, cost;

	for (int i = 0; i < e; i++)
	{

		cin >> src >> dest >> cost;

		dp[src][dest] = cost;
	}

	//Time Complexity O(N^3)
	// Space Complexity O(N^2)

	for (int k = 0; k < n; k++)
	{

		for (int i = 0; i < n; i++)
		{

			for (int j = 0; j < n; j++)
			{
				/*
				* find min dist from i to j
				* dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j])
				*/

				if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}


//Check Negative weight cycle :

	for (int i = 0; i < n; i++)
	{
		if (dp[i][i] < 0)
		{
			cout << "There is a negative weight cycle " << "\n";
			return 0;
		}


	}


// Otherwise print min weight of each pair of nodes.

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] == INT_MAX)
				cout << "INF" << " ";
			else
				cout << dp[i][j] << " ";

		}

		cout << "\n";

	}




}