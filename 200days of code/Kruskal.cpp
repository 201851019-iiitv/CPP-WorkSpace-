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

struct Edge
{
  int intial, end, wt;
};

struct node
{
  int parent, rank;
};

bool sortfun(Edge &a, Edge &b)
{

  return a.wt < b.wt;
}

void update_Path_cost(vector<Edge> &edge, int a, int b, int weight)
{

  for (int i = 0; i < edge.size(); i++)
  {
    if ((edge[i].intial == a && edge[i].end == b) || (edge[i].intial == b && edge[i].end == a))
    {

      edge[i].wt = min(edge[i].wt, weight);
    }
  }
}
vector<Edge> mst;

int find_Absolute_Parent(int vertex, vector<node> &dsuf)
{
  if (dsuf[vertex].parent == -1)
    return vertex;

  return dsuf[vertex].parent = find_Absolute_Parent(dsuf[vertex].parent, dsuf);
}

void union_value(int a, int b, vector<node> &dsuf)
{

  if (dsuf[a].rank == dsuf[b].rank)
  {
    dsuf[a].parent = b;
    dsuf[b].rank += 1;
  }
  else if (dsuf[a].rank >dsuf[b].rank)
  {
    dsuf[b].parent = a;
  }
  else{
    dsuf[b].parent = a;
  }

}

bool fun(Edge &a,Edge &b)
{
  return a.intial<b.intial;
}

void printmst()
{
  sort(mst.begin(),mst.end(),fun);
  cout<<"============================================================\n";
	for(auto p: mst)
		cout<<"intial_vertex: "<<p.intial<<" end_vertex: "<<p.end<<"  wt: "<<p.wt<<"\n";
	cout<<"============================================================\n";
}


int main()
{

  int number_of_vertex, number_of_edge;

  cout << "Enter the number of vertex and number of edge:\n";
  cin >> number_of_vertex >> number_of_edge;

  vector<Edge> edge;                                    //it store cost as well as starting point and ending point;
  unordered_map<int, unordered_map<int, bool>> visited; // for remove of parallel edge and consider min cost between them.
  int a, b, c;
  cout << "Enter the start node end node (b/w 0-" << number_of_vertex - 1 << ")and weight \n";
  for (int i = 0; i < number_of_edge; i++)
  {

    cin >> a >> b >> c;

    if (a != b && (visited[a][b] || visited[b][a])) // indicates the parallel edge is there.
    {
      update_Path_cost(edge, a, b, c); //update cost with min edge.
    }
    else if (a != b) // remove self loop
    {
      edge.push_back({a, b, c});
      visited[a][b] = true;
    }
  }

  sort(edge.begin(), edge.end(), sortfun); // sort on basis of weight of edges.

  // for(int i=0;i<edge.size();i++)
  // cout<<edge[i].intial<<" "<<edge[i].end<<" "<<edge[i].wt<<"\n";

  vector<node> dsuf(number_of_vertex, {-1, 0}); //make track of absolute parent node as well as rank of a node.Intialize parent is -1 and rank 0.

  // max  edge in minimum spanning is only number_of_vertex-1

  int i = 0, count = 0;

  while (i < number_of_edge && count < (number_of_vertex - 1))
  {
    int absolut_Parent_of_intial = find_Absolute_Parent(edge[i].intial, dsuf);

    int absolut_Parent_of_end = find_Absolute_Parent(edge[i].end, dsuf);

    if (absolut_Parent_of_intial != absolut_Parent_of_end) // if both absolute parent are same then they will form a cycle
    {
      union_value(absolut_Parent_of_intial, absolut_Parent_of_end, dsuf);
      count++;
      mst.push_back(edge[i]);
    }
    i++;
  }


  printmst();
}

/*
Test Case 1:
6 12
0 1 4 
1 2 6 
0 2 6
1 3 3
1 4 4
2 3 1
4 5 7
4 3 2
3 5 3
0 0 1
3 3 4
3 4 1
------
Test Case 2:
6 11
0 1 7
0 2 8
1 2 3
1 3 6
1 3 8
3 5 5
2 4 3
2 3 4
4 5 2
4 3 2
5 5 1

-------
Test Case 3:

6 10
0 1 1
1 3 1
2 4 1
0 2 2
3 4 2
2 3 2
1 2 3
1 4 3
3 5 4
4 5 3

*/
