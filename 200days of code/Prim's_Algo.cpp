
#include <bits/stdc++.h>

/// This define function used only for debugging purpose
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

using namespace std;


bool check(vector<bool> v)
{
    for (int i = 0; i < v.size(); i++)
    {

        if (!v[i])
            return false;
    }

    return true;
}

int findmin(vector<int> v, vector<bool> processed)
{

    int index = -1, minv = INT_MAX;

    for (int i = 0; i < v.size(); i++)
    {
        if (!processed[i] && v[i] < minv)
        {
            minv = v[i];
            index = i;
        }
    }

    return index;
}


void print(vector<int> v)
{

    cout << "\n mincost\n";

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}
void print(vector<bool> v)
{

    cout << "\n proc\n";

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << "\n";
}


int main()
{

    int number_of_vertex, number_of_edge;

    cin >> number_of_vertex >> number_of_edge;


// ------------------ This part is only making Adjacent_matrix --------------------------

    /// Assume Node index from 0 to n-1;
    /// This is list of adjacent nodes;
    int adjacent_matrix[number_of_vertex][number_of_vertex];

    /// intialized value as infinite.
    memset(adjacent_matrix, 0, sizeof(adjacent_matrix));

    int src, dest, cost;
    for (int i = 0; i < number_of_edge; i++)
    {

        cin >> src >> dest >> cost;

        /// we ignore the self loop case;
        if (src != dest)
        {
            /// if parallel edges are there .so we consider only min cost  edge b/w then.
            if (adjacent_matrix[src][dest] != 0)
            {

                adjacent_matrix[src][dest] = min( adjacent_matrix[src][dest], cost);
                /// because  graph is undirected.
                adjacent_matrix[dest][src] = min( adjacent_matrix[src][dest], cost);

            }
            else
            {
                adjacent_matrix[src][dest] = cost;
                /// because  graph is undirected.
                adjacent_matrix[dest][src] = cost;
            }

        }
    }

    // for (int i = 0; i < number_of_vertex; i++)
    // {
    //     for (int j = 0; j < number_of_vertex; j++)
    //         cout << adjacent_matrix[i][j] << " ";

    //     cout << "\n";
    // }

    // ------------------------------------------------------------------------------------

    int parent[number_of_vertex]; // parent track of each node.

    int src_node;
    //cout << "Choose the src node b/w " << 0 << "-" << number_of_vertex - 1 << "\n";
    cin >> src_node;

    parent[src_node] = -1; // Assume src node have no parent i.e it is root node.

    /// mincost of each node to it's parent;

    vector<int> min_cost(number_of_vertex, INT_MAX); /// intialized all cost is infinty;

    min_cost[src_node] = 0; //Src node min cost=0;

    /// track of processed node or added in mst;
    vector<bool> proc(number_of_vertex, false); /// intialized all proccesed node is false;

    /// running loop while all nodes are not processed.
    while (!check(proc))
    {
        int vertex = findmin(min_cost, proc);

        //deb(vertex);
        /// when vertex is not connected .i.e no adjacent vertex are there .
        if (vertex == -1)
        {
            for (int i = 0; i < number_of_vertex; i++)
            {
                if (!proc[i])
                {
                    parent[i] = src_node;
                    adjacent_matrix[parent[i]][i] = INT_MAX;

                }
            }
            break;
        }

        for (int i = 0; i < number_of_vertex; i++)
        {

            /*
             If condinition check :-
            1.vertex are connected
            3.this vertex is not proccessed.
            4.cost of edge weight is lesser than the it's already calculated weight.

            */
            if (adjacent_matrix[vertex][i] != 0 && !proc[i] && adjacent_matrix[vertex][i] < min_cost[i])
            {
                min_cost[i] = adjacent_matrix[vertex][i];
                parent[i] = vertex;


            }

        }


        proc[vertex] = true; // set as proccessed.

        //print(proc);
        //print(min_cost);
    }

    for (int i = 0; i < number_of_vertex; i++)
    {
        if (parent[i] != -1)
            cout << parent[i] << "->" << i << "  cost = " << adjacent_matrix[parent[i]][i] << "\n";
    }


}
