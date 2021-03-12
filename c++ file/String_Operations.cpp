// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
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

void print(vector<string> vv)
{

        for (int j = 0; j < vv.size(); j++)
        {

            cout << vv[j] << " ";
        }
        cout<<"\n";
}

ll onecount(string s)
{
    ll count = 0;

    ll i;
    fo(i, s.length())
    {
        if (s[i] == '1')
            count++;
    }

    return count % 2 == 0 ? true : false;
}

vector<int> evencount(string s)
{

    ll evenc = 0;
    ll oddc = 0;

    int i = 0;

    ll ones = 0;
    while (i < s.length())
    {

        
        if (s[i] != '0')
        {
            ones++;
            
        }
        else
        {
          if (ones % 2 == 0)
            evenc++;
        else
        {
            oddc++;
        }
        }
        
        

        i++;
    }

    vector<int> v;

    v.push_back(evenc);
    v.push_back(oddc);

    return v;
}

void solve()
{
    ll i, j, n, m;

    string s;

    cin >> s;

    n = s.length();
    set<string> str;

    for (int i = 0; i < n; i++)
    {
        for (int len = 1; len <= n - i; len++)
            str.insert(s.substr(i, len));
    }

    vector<string> v;

    for (auto x : str)
        v.push_back(x);

    ll count = 0;


print(v);


    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < v.size(); i++)
    {

        //deb2(i,v.size());
        if (onecount(v[i]))
        {
            for (j = 0; j < v.size() && i != j; j++)
            {

                if (onecount(v[j]))
                {
                    v1 = evencount(v[i]);
                    v2 = evencount(v[j]); 

                    
                    if (v[i].length() == v[j].length() && v1[0] == v2[0] && v1[1] == v2[1])
                    {

                        // deb2(v[i],v[j]);
                        // deb2(v1[0],v1[1]);
                        // deb2(v2[0],v2[1]);
                        v.erase(v.begin() + j);
                        j--;
                    }

                    v1.clear();
                    v2.clear();
                }
            }
        }

        count++;
    }

    cout<<count<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
