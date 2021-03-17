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

void dfs(int src, vector<bool> &visited,vector<vector<int>>&adjacent)
{
    visited[src]=true;
    if(adjacent[src].size()==0)
    return ;


   for(int i=0;i<adjacent[src].size();i++)
   {
     if(!visited[adjacent[src][i]])
       {
           dfs(adjacent[src][i],visited,adjacent);
           //y=false;
       }  


   }
   



    
}

    int main()
    {

        int number_of_vertex, number_of_edge;

        cout << "Enter the number of vertex and number of edge:\n";
        cin >> number_of_vertex >> number_of_edge;

        /// Assume Node index from 0 to n-1;
        /// This is list of adjacent nodes;

        vector<vector<int>> adjacent(number_of_vertex);

cout << "Enter the start node end node (b/w 0-" << number_of_vertex - 1 << ") \n";
        int src, dest;
        for (int i = 0; i < number_of_edge; i++)
        {

            cin >> src >> dest;
            adjacent[src].push_back(dest);
            adjacent[dest].push_back(src);
        }

        vector<bool>visited(number_of_vertex,false);

        int number_of_connected_Component=0;

    for(int i=0;i<number_of_vertex;i++)
    {

      if(!visited[i])
      {
        
        dfs(i,visited,adjacent);
        number_of_connected_Component++;

      }
       
          

    }


cout<<"number_of_connected_Component :" <<"  "<<number_of_connected_Component<<"\n";

        return 0;
    }

/*
   Test 1:

7 5
0 1
0 2 
1 3 
4 5
5 6
 ------------------
 Test 2:
4 3 
0 1
1 2
2 3

 ------------------
 Test 3:
6 3 
0 1
1 2
3 4
------------------
 Test 4:
5 3 
0 1
1 2
3 4
 Test 4:
5 3 
0 1
1 0
3 3

*/