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

void dfs(int src, vector<bool> &visited,vector<vector<int>>&adjacent,vector<int>&res)
{
    visited[src]=true;
   for(int i=0;i<adjacent[src].size();i++)
   {
     if(!visited[adjacent[src][i]])
       {
           dfs(adjacent[src][i],visited,adjacent,res);
           
       }  


   }
   
 


       res.push_back(src);
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
           
        }

        vector<bool>visited(number_of_vertex,false);

       vector<int>res;

    for(int i=0;i<number_of_vertex;i++)
    {

      if(!visited[i])
      {
        
        dfs(i,visited,adjacent,res);
        

      }
       
          

    }


    cout<<"Topological order: ";

    for(int i=res.size()-1;i>=0;i--)
    {
     cout<<res[i]<<" ";

    }

    cout<<"\n";


        return 0;
    }

/*
   Test 1:
6 7
0 2
4 1
5 0
3 1
4 2
5 2
0 3
Output: 5 4 0 3 1 2 
 ------------------
 Test 2:
6 6
5 2
5 0
4 0
4 1
2 3
3 1

Output: 5 4 2 3 1 0 
 --------------------
*/