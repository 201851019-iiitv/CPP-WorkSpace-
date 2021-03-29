#include<bits/stdc++.h>
using namespace std;

struct edge{
	int src,dst,wt;
};
int V,E;

void bellmanFord(vector<edge>& Edges,int src)
{
	int parent[V+1];		//Stores Shortest Path Structure
	int cost_parent[V+1];	//Cost of the node to parent edge weight
	vector<int> value(V+1,INT_MAX);	//Keeps shortest path values to each vertex from source
	
	//Assuming start point as Node-0
	parent[src] = -1;	//Start node has no parent
	value[src] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	bool updated;
	for(int i=1;i<=V;++i)
	{
		updated = false;
		for(int j=0;j<E;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V])
			{
				value[V] = value[U]+wt;
				parent[V] = U;
				cost_parent[V] = value[V];
				updated = true;
			}
		}
		if(updated==false)
			break;
	}
	//Now check by relaxing once more if we have a negative edge cycle
	for(int j=0;j<E and updated==true;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(value[U]!=INT_MAX and value[U]+wt<value[V])
			{
				cout<<"Graph has -VE edge cycle\n";
				return;
			}
		}
	//Print Shortest Path Graph
	for(int i=1;i<=V;++i)
	{
		if(src!=i)
		cout<<src<<" "<<i<< " "<<value[i]<<"\n";
	}
}

int main()
{

	int src;
	cin>>V>>E>>src;	//Enter no of Vertices and Edges
	vector<edge> Edges(E);

	//Now input all E edges
	int in,dst,wt;
	for(int i=0;i<E;++i)
	{
		cin>>in>>dst>>wt;
		Edges[i].src = in;
		Edges[i].dst = dst;
		Edges[i].wt = wt;
	}

	bellmanFord(Edges,src);	
	return 0;
}
8 11 1
1 2 10
3 2 1
3 4 1
4 5 3
5 6 -1
7 6 -1
8 7 1
1 8 8
7 2 -4
2 6 2
6 3 -2