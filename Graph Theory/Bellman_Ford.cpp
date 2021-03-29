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

int inf=0;
using namespace std;

struct edge
{
  int intial,end,weight;
  

};

int main()
{

int n,e,src;//number of vertex and edges and src

//cout << "Enter the number of vertex and number of edge and src :\n";

cin>>n>>e>>src;

vector<edge>v;

int a,b,c;

 //cout << "Enter the start node end node (b/w 1-" << n << ")and weight \n";

for(int i=0;i<e;i++)
{
  
 cin>>a>>b>>c;
   v.push_back({a,b,c});
   
   if(c>0)
   inf +=c;

}


vector<int>dist(n+1,inf);

dist[src]=0;

for(int i=1;i<=n;i++)
{
    for(int j=0;j<e;j++)
    {

       if(dist[v[j].intial]!=inf && dist[v[j].intial]+v[j].weight<dist[v[j].end])
       {

           dist[v[j].end]=dist[v[j].intial]+v[j].weight;
       }


    }


}


// If negative cycle exist.
for(int j=0;j<e;j++)
    {

       if(dist[v[j].intial]!=inf && dist[v[j].intial]+v[j].weight<dist[v[j].end])
       {
         cout<<"Graph Contains negative weight cycle"<<"\n";
         return 0;
           
       }


    }





//cout << "src_node" << " " << "dest_node" << " " << "min_dist" << "\n";

cout<<"Output :"<<"\n";
  for (int i = 1; i <=n; i++)
  {
  if(i!=src)
  {
    cout << src << " " << i << " " <<dist[i] << "\n";

  }
  }

}

/*
Test Case #1:
5 8 1
1 2 -1
1 3 4
2 3 3
2 4 2
2 5 2
4 2 1
4 3 5
5 4 -3

Output:
1 2 -1
1 3 2
1 4 -2
1 5 1

Test Case #2:
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


Output:
1 2 5
1 3 5
1 4 6
1 5 9
1 6 7
1 7 9
1 8 8

*/