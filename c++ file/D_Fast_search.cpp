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

int higherindex(ll arr[], ll x, ll n)
{

    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else
        {
            low = mid + 1;
        }
    }

    return low + 1;
}

int getlower(ll arr[], ll x, ll n)
{

    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return high + 1;
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll arr[n];
    loop(i, n)
            cin >>
        arr[i];

    ll t;
    cin >> t;

    sort(arr, arr + n);

    while (t--)
    {
        ll l, r;

        cin >> l >> r;

        ll lower = getlower(arr, l, n);
        //cout << lower << " lloo "<<t<<" ";
        ll higher = higherindex(arr, r, n);

        ll res = abs(lower - higher)-1;

        cout << res << " ";
    }

    cout << "\n";
    return 0;
}