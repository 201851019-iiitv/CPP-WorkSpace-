
#include <bits/stdc++.h>

/// This define function used only for debugging purpose
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl


using namespace std;


/// Global declarations


/// INFINTY
int INFINITE = 0;

vector<pair<pair<int, int>, int>>cost;

///this  vector represent the cost between two nodes.


/// check where all node are proccessed or not

bool check(vector<bool>v)
{
  for (int i = 0; i < v.size(); i++)
  {

    if (!v[i])
      return false;


  }


  return true;


}

/// finding minimum distance node and it was not visited also.

int findmin(vector<int>v, vector<bool>processed)
{

  int index = -1, minv = INT_MAX;

  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] <= minv && !processed[i])
    {
      minv = v[i];
      index = i;
    }


  }




  return index;

}


/// finding cost between node a and node b.

int Find_cost(int a, int b)
{


  for (auto x : cost)
  {

    if (x.first.first == a && x.first.second == b )
      return x.second;

    if (x.first.first == b && x.first.second == a )
      return x.second;



  }


  return  INFINITE;

}



int main()
{


/// n is number of vertex we assume that are all vertex start with 0 to n-1 .
  int n;
  cin >> n;

  int number_of_edges;
  cin >> number_of_edges;

  vector<vector<int>>edges(number_of_edges);
/// this vector represent the edge between two nodes.


  int a, b, c;
  for (int i = 0; i < number_of_edges; i++)
  {

    cin >> a >> b >> c;


/// we add edges between a and b
/// these edges are undirected
    edges[a].push_back(b);
    edges[b].push_back(a);


/// add cost of this edges

    cost.push_back(make_pair(make_pair(a, b), c));


    INFINITE += c;


  }


/// tracking of visited or proccesed node;
  vector<bool>visited(n);

  int src = 0;
/// assume src node or start node is 0;



////this is minimum cost calculate
/// intially  it is infinte or INT_MAX or sum of weight;
  vector<int>min_reach_cost(n, INFINITE);



  min_reach_cost[src] = 0;
  while (!check(visited))
  {

/// find the node minimum distance from src node and it was not visited also.

    int index = findmin(min_reach_cost, visited);

    for (int i = 0; i < edges[index].size(); i++)
    {

      int node = edges[index][i];
      int weight_of_node = Find_cost(index, node);

      min_reach_cost[node] = min(min_reach_cost[node], min_reach_cost[index] + weight_of_node);

    }

    visited[index] = true;



  }


  cout << "src_node" << " " << "dest_node" << " " << "min_dist" << "\n";

  for (int i = 0; i < min_reach_cost.size(); i++)
    cout << src << " \t \t" << i << "\t \t" << min_reach_cost[i] << "\n ";








}

