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


struct node {

	int val;
	struct node * next, *prev;

};


struct node *newNode(int data)
{

	struct node *temp = new(struct node);

	temp->val = data;
	temp->next = temp->prev = NULL;


	return temp;
}


struct node *addfront(struct node* head, int data)
{

	if (head == NULL)
		return newNode(data);

	struct node *temp = new(struct node);

	temp->val = data;

	temp->next = head;

	temp->prev = NULL;

	if (head != NULL)
		head->prev = temp;

	head = temp;


	return temp;


}


struct node *addEnd(struct node *head, int data)
{

	if (head == NULL)
		return newNode(data);

	struct node *temp = new(struct node);

	temp->val = data;

	struct node *curr = head;

	while (curr->next != NULL)
		curr = curr->next;


	curr->next = temp;
	temp->prev = curr;
	temp->next = NULL;




	return temp;

}


void print(struct node *head)
{

	struct node *curr = head;
	while (curr != NULL)
	{
		cout << curr->val << '\n' ;
		curr = curr->next;
	}



}

struct node *insert(struct node *prev , int data)
{

	if (prev == NULL)
		return newNode(data);

	struct node *temp = new(struct node);

	temp->val = data;

	temp->next = prev->next;
	temp->prev = prev;

	prev->next = temp;

	return temp;


}




void solve() {
	int i, n, m, val;
	cin >> n;


	struct node  *head = NULL;
	fo(i, n)
	{


		cout << "Enter the option :" << '\n' ;
		cout << "1.insert at front of DLL" << '\n' ;
		cout << "2.insert at end of DLL" << '\n' ;
		cout << "3.insert at  any index of DLL" << '\n' ;

		cin >> m;

		switch (m)
		{


		case 1:
		{

			cin >> val;
			addfront(head, val);
			cout << head->val << '\n' ;
			print(head);
			break;
		}
		case 2:
		{
			cin >> val;
			addEnd(head, val);
			print(head);
			break;
		}
		case 3:
		{
			cin >> val;
			addEnd(head->next, val);
			print(head);
			break;
		}
		default:
			cout << "Error Ocurred" << "\n";

		}

	}



}







int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}





