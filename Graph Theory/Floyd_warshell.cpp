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

	
    // intialize of dp.

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

cout<<"distance of every pair of nodes :\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dp[i][j] == INT_MAX)
				cout << "INF" << "\t";
			else
				cout << dp[i][j] << "\t";

		}

		cout << "\n";

	}




}

/*
* Test Case 1:
4 4
0 3 10
0 1 5
2 3 1
1 2 3


* Output:
0 5 8 9 
INF 0 3 4 
INF INF 0 1 
INF INF INF 0 

------
* Test Case 2:
4 6
0 3 5
0 1 3
1 0 2
2 1 1
3 2 2
1 3 8


* Output:
0 3 7 5
2 0 9 7
3 1 0 8
5 3 2 0

*/