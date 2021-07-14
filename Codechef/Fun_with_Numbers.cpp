// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define foo(i, k, n) for (i = k; i < n; i++)
#define Fo(i, k, n) for (i = n - 1; i >= k; i--)
#define ll long long
#define in(x) cin >> x
#define prt(x) cout << x << "\n"
#define prt2(x, y) cout << x << " " << y << "\n"
#define prt3(x, y, z) cout << x << " " << y << " " << z << "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define pr make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define setv(x) memset(x, -1, sizeof(x))
#define tot(arr) arr, arr + sizeof(arr)
#define set(x) memset(x, -1, sizeof(x))
#define sortall(x) sort(all(x))
#define sorttot(arr) sort(tot(arr))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef unordered_map<ll, ll> mp;
typedef unordered_map<char, ll> mc;
typedef unordered_map<ll, bool> mb;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
   uniform_int_distribution<int> uid(0, lim - 1);
   return uid(rang);
}

const ll mod = 1000000007;
const int N = 3e5, M = N;
//=================================================================================================================================//

void solve()
{
   ll i, j, n, k;
   in(n);

   string s;

   cin >> s;

   ll z, o, t;
   cin >> z >> o >> t;

   ll cz[n];
   ll co[n];
   ll ct[n];
   cz[0] = 0;
   co[0] = 0;
   ct[0] = 0;

   if (s[0] == '0')
      cz[0] = 1;
   else if (s[0] == '1')
      co[0] = 1;
   else
      ct[0] = 1;

   for (i = 1; i < n; i++)
   {
      cz[i] = cz[i-1];
      co[i] = cz[i-1];
      ct[i] = cz[i-1];

      if (s[i] == '0')
         cz[i] = cz[i - 1] + 1;
      else if (s[i] == '1')
         co[i] = co[i - 1] + 1;
      else
         ct[i] = ct[i - 1] + 1;
   }

   // fo(i, n)
   //     deb2(i, cz[i]);

   ll res = 0;

   ll c0, c1, c2;


   ll i=n-1,j=0;

 while(j<=i)
      {

        //deb2(cz[i],cz[j]);
         c0 = cz[i] - cz[j];
         c1 = co[i] - co[j];
         c2 = ct[i] - ct[j];

         if (s[j] == '0')
            c0 = c0 + 1;
         else if (s[j] == '1')
            c1 = c1 + 1;
         else
            c2 = c2 + 1;

         // deb2(c0,c1);
         // deb2(c2,res);

         if (c0 <= z && c1 <= o)
         {
            res = max(res, i - j + 1);
            break;
         }
         else if (c0 <= z && c2 <= t)

         {
            res = max(res, i - j + 1);
            break;
         }

         else if (c2 <= t && c1 <= o)
         {
            res = max(res, i - j + 1);
            break;
         }
      }
   }

   prt(res);
}
int main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   srand(chrono::high_resolution_clock::now().time_since_epoch().count());

   int test = 1;
   cin >> test;
   while (test--)
   {
      solve();
   }

   return 0;
}
