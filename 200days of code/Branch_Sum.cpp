// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error thhen you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

#define  ll  long long
# define  loop(x,n)  for(int x = 0; x < n; ++x)
#define   constloop(x,a,n) for(int x = a; x < n; ++x)
#define  revloop(x,a,n)  for(int x = a; x > n; x--)

// ------- above define macros---------------------//


using namespace std;

struct node {
	int  val;
	struct node *left, *right;


};


struct node *newnode(int data)
{

	struct node *temp = new (struct node);
	temp->val = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}


struct node *insert(struct node*root, int data)
{

	if (root == NULL)
		return newnode(data);

	if (root->val > data)
		root->left = insert(root->left, data);
	else
		root->right = insert(root->right, data);

	return root;

}




void sumhelper(struct node *root, int running_sum, vector<int>&sum)
{

	if (root == NULL)
		return ;


	int newRunning_Sum = root->val + running_sum;

	if (root->left == NULL  && root->right == NULL)
	{

		sum.push_back(newRunning_Sum);
		return ;
	}



	sumhelper(root->left, newRunning_Sum, sum);
	sumhelper(root->right, newRunning_Sum, sum);



}



void print(vector<int>sum)
{


	for (int i = 0; i < sum.size(); i++)
		cout << sum[i] << ' ' ;

	cout << '\n' ;

}





void getBranch_Sum(struct node *root)
{


	vector<int>sum;

	sumhelper(root, 0, sum);

	print(sum);



}



// print tree

void traversal(struct node *root)
{

	if (root == NULL)
		return;

	cout << root->val << " " ;
	traversal(root->left);
	traversal(root->right);


}



int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;

		struct node *root = NULL;

		cin >> m;

		root = insert(root, m);



		for (int i = 1; i < n; i++)
		{

			cin >> m;

			insert(root, m);


		}


		//traversal(root);
		getBranch_Sum(root);





	}
	return 0;
}