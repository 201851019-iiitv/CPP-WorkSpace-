/*
----------------------------------------------------------------------------
        Name:Ambesh Kumar(201851019)
        Name:Ankur Chanderia(201851023)
        Name:Deepak Bethamalla(201851033)
----------------------------------------------------------------------------
*/

#include <bits/stdc++.h>
#define ll long long

/// This define function used only for debugging purpose
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;

struct Edge
{
  ll intial, end, wt;
};

struct node
{
 ll  parent, rank;
};

bool sortfun(Edge &a, Edge &b)
{

  return a.wt < b.wt;
}


vector<Edge> mst;

ll find_Absolute_Parent(int vertex, vector<node> &dsuf)
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

  ll number_of_vertex, number_of_edge;

  //cout << "Enter the number of vertex and number of edge:\n";
  cin >> number_of_vertex >> number_of_edge;

  vector<Edge> edge;                                    //it store cost as well as starting point and ending point;
  //unordered_map<int, unordered_map<int, bool>> visited; // for remove of parallel edge and consider min cost between them.
  int a, b, c;
  //cout << "Enter the start node end node (b/w 0-" << number_of_vertex - 1 << ")and weight \n";
  for (int i = 0; i < number_of_edge; i++)
  {

    cin >> a >> b >> c;


   a--;b--;
      edge.push_back({a, b, c});
    
  }

  sort(edge.begin(), edge.end(), sortfun); // sort on basis of weight of edges.

  // for(int i=0;i<edge.size();i++)
  // cout<<edge[i].intial<<" "<<edge[i].end<<" "<<edge[i].wt<<"\n";

  vector<node> dsuf(number_of_vertex, {-1, 0}); //make track of absolute parent node as well as rank of a node.Intialize parent is -1 and rank 0.

  // max  edge in minimum spanning is only number_of_vertex-1

  ll i = 0, count = 0;

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
  unordered_map<ll,bool>mp;

  for(i=0;i<mst.size();i++)
  {

      mp[mst[i].intial]=true;
      mp[mst[i].end]=true;

  }

  for(i=0;i<number_of_vertex;i++)
  {
      if(mp[i])
      cout<<"all"<<"\n";
      else
      cout<<"none"<<"\n";


  }


 


}

