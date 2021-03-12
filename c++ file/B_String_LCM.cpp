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

vi g[N];
int a[N];




ll gcd(ll n1, ll n2)
{
    if (n2 != 0) return gcd(n2, n1%n2);
    else return n1;
}


ll lcm(ll a,ll b)
{


    if(a>=b)
    return (a*b)/(gcd(a,b));
    return (a*b)/(gcd(b,a));
}

int countFreq(string &pat, string &txt) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 
    int res = 0; 
    
    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) 
    {  
        /* For current index i, check for  
           pattern match */
        int j; 
        for (j = 0; j < M; j++) 
            if (txt[i+j] != pat[j]) 
                break; 
   
        // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
        if (j == M)   
        { 
           res++; 
           j = 0; 
        } 
    } 
    return res; 
} 


void res(string s,string s1)
{
 ll i=0;

int n1=s.length(),n2=s1.length();

string ss="";
bool a=false,b=false;
while(i<min(n1,n2) && s[i]==s1[i])
{
 ss +=s[i];

 if(s[i]=='a')
 a=true;
 else
 {
     b=true;
 }
 

  i++;
}





if(a && b)
{

int count=countFreq(s,ss)+1;
int count1=countFreq(s1,ss)+1;

cout<<n1<<" ";

if(count*ss.length()==n1 && count1*ss.length()==n2)
{

ll c=lcm(count,count1);
fo(i,c)
cout<<ss;

cout<<"\n";

}
else
{
    cout<<-1<<"\n";
}

}
else if(a || b)
{

    string d3="";
     d3+=ss[0];
int count=countFreq(s,d3);
int count1=countFreq(s1,d3);


if(count==n1 && count1==n2)
{

ll c=lcm(count,count1);
fo(i,c)
cout<<ss;

cout<<"\n";

}
else
{
    cout<<-1<<"\n";
}
 


}

else
{
    cout<<-1<<"\n";
}





}






void solve() {
  ll i, j, n, m;

  string s1,s2;

  cin>>s1>>s2;

  res(s1,s2);


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





