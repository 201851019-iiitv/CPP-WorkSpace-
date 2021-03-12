// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0, lim - 1);
	return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1000000007;
const int N = 3e5, M = N;
//=================================================================================================================================//

vi g[N];
int a[N];


//declare a node ;
struct node {

	int val;
	struct node *left, *right;

};


//create a new Node;
struct node *newNode(int data)
{

	struct node *temp = new (struct node);


	temp->val = data;

	temp->right = temp->left = NULL;


	return temp;

}

//insert new value  in node;


struct node *insert(struct node *root, int val)
{

	if (root == NULL)
		return newNode(val);

	else if (root->val > val)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);



	return root;
}


//preorder traverse  (data,left,right);
//  post order traverse (left,right,data);
//inorder traverse (left ,data,right);

void print(struct node *root)
{


	if (root == NULL)
		return ;

	cout << root->val << '\n' ;
	print(root->left);

	print(root->right);



}

int findGetCloser(struct node *root , int val, int closest)
{

	struct node *current = root;

	while (current)
	{

		if (current->val - val == 0)
			return current->val;
		else if (abs(current->val - val) < abs(closest - val))
			closest = current->val;

		if (current->val > val)
			current = current->left;
		else if (current->val < val)
			current = current->right;


	}



	return closest;




}





int findCLosest(struct node * root, int val)
{




	return findGetCloser(root, val, 100000000);


}




void solve() {
	int i, j, n, m;

	cin >> n;
	cin >> m;
	struct node *root = NULL;
	root = insert(root, m);

	//deb(root->val);

	Fo(i, 1, n)
	{

		cin >> m;

		insert(root, m);


	}


	print(root);

	int val;
	cin >> val;

	int p = findCLosest(root, val);

	cout << p << '\n' ;


}







int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}





