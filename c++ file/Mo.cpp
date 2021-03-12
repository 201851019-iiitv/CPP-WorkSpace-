
#include<bits/stdc++.h>
using namespace std;
#define  ll  long long  //define a macro variable of long long type
# define  loop(x,n)  for(int x = 0; x < n; ++x)  // define a for loop
#define   constloop(x,a,n) for(int x = a; x < n; ++x)  //define a for loop with start a const
#define  revloop(x,a,n)  for(int x = a; x > n; x--) // rev for loop
//#define   vect vector<ll>  // define a vector of longlong type;

//const int MAX = 1000000;

// Variable to represent block size. This is made
// global so compare() of sort can use it.
int block;

// Structure to represent a query range and to store
// index and result of a particular query range
struct Query {
    int L, R, index, result;
};

// Function used to sort all queries so that all queries
// of same block are arranged together and within a block,
// queries are sorted in increasing order of R values.
bool compare(Query x, Query y)
{
    // Different blocks, sort by block.
    if (x.L / block != y.L / block)
        return x.L / block < y.L / block;

    // Same block, sort by R value
    return x.R < y.R;
}

// Function used to sort all queries in order of their
// index value so that results of queries can be printed
// in same order as of input
bool compare1(Query x, Query y)
{
    return x.index < y.index;
}

// calculate distinct elements of all query ranges.
// m is number of queries n is size of array a[].
void queryResults(int arr[], int n, Query query[], int q,int happy[],int m)
{
    // Find block size
    block = (int)sqrt(n);

    // Sort all queries so that queries of same
    // blocks are arranged together.
    sort(query, query +q, compare);

    // Initialize current L, current R and current
    // different elements
		set<int>s;
    int currL = 0, currR = 0;
    //int curr_Diff_elements = 0;

    // Initialize frequency array with 0

    // Traverse through all queries
    for (int i = 0; i < q; i++) {

        // L and R values of current range
        int L = query[i].L, R = query[i].R;

       if(currL<L)
       {
       	
       	if(!s.empty())
       	{
       		
       		int a=arr[currL];
       		set.erase(a);
		
		   }
       	
       	currL++;
	   }
	   if()


if(d==m)
query[i].result =1;
else
query[i].result =0;

    }
}

// print the result of all range queries in
// initial order of queries
void printResults(Query query[], int m)
{
    sort(query, query + m, compare1);
    for (int i = 0; i < m; i++) {
        cout << "Number of different elements" <<
               " in range " << query[i].L << " to "
             << query[i].R << " are " << query[i].result << endl;
    }
}


int  main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);  ///using for  fast input
int n,m;
cin>>n>>m;
int arr[n];
loop(i,n)
{
  cin>>arr[i];
}
int happy[m];
loop(j,m)
{
cin>>happy[j];
}
int q;
cin>>q;
Query query[q];
loop(i,q)
{
  int a,b;
cin>>a>>b;
query[i].L=a;
query[i].R=b;
query[i].index=i;
query[i].result=0;

}

queryResults(arr, n, query, q,happy,m);

printResults(query, q);



return 0;
}

