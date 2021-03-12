// Created by  Ambesh kumar
#include "bits/stdc++.h"

//I already compile this file in my computer system to save the time
//if get the compiler error then you should change this header to
// #include "bits/stdc++.h"  ---> #include <bits/stdc++.h>

#define ll long long
#define loop(x, n) for (int x = 0; x < n; ++x)
#define constloop(x, a, n) for (int x = a; x < n; ++x)
#define revloop(x, a, n) for (int x = a; x > n; x--)

// ------- above define macros---------------------//

using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t = 1;
    //cin>>t;
    while (t--)
    {
        ll n;
        cin >> n;

        if (n % 2 != 0)
            cout << "NO"
                 << "\n";

        else
        {
            int p = n - 2;
            if (p % 2 == 0 && p > 0)
                cout << "YES"
                     << "\n";
            else
            {
                cout << "NO"
                     << "\n";
            }
        }
    }
    return 0;
}