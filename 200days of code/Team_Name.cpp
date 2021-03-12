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
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define ss(s)    scanf("%s",s)
#define pi(x)    printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
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
typedef pair<int, int>    pii;
typedef pair<ll, ll>    pl;
typedef vector<int>        vi;
typedef vector<ll>        vl;
typedef vector<pii>        vpii;
typedef vector<pl>        vpl;
typedef vector<vi>        vvi;
typedef vector<vl>        vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
    uniform_int_distribution<int> uid(0,lim-1);
    return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1000000007;
const int N = 3e5, M = N;
//=================================================================================================================================//

void solve() {
  ll i, j, n, m;
  cin>>n;

string s,sub;

set<string>st;

fo(i,n)
{

cin>>s;

st.insert(s);

}

vector<pair<string,char>>v;

for(auto x:st)
{
   sub=x.substr(1,x.length());
   v.push_back(make_pair(sub,x[0]));

}

sortall(v);


// for(auto x:v)
// {
//   cout<<x.first<< " "<<x.second<<"\n";
// }

vector<vector<char>>dict;
vector<char>temp;
temp.push_back(v[0].second);
for(i=1;i<v.size();i++)
{
   if(v[i].first==v[i-1].first)
      temp.push_back(v[i].second);

   else
   {
     dict.push_back(temp);
     temp.clear();
     temp.push_back(v[i].second);
   }   
  


 
}


if(temp.size()!=0)
dict.push_back(temp);


ll res=0,k;

for(i=0;i<dict.size();i++)
{
  for(j=i+1;j<dict.size();j++)
  {
     sortall(dict[i]);
     sortall(dict[j]);
 
    vector<char> ss;
    vector<char>::iterator it, st;
 
    set_union(dict[i].begin(), dict[i].end(),dict[j].begin(),
                        dict[j].end(), back_inserter(ss));

    //deb2(ss.size(),dict[i].size());
    //deb(dict[j].size());
    res +=2*(ss.size()-dict[i].size())*(ss.size()-dict[j].size());

  }


  

}



cout<<res<<"\n";

}







int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}





