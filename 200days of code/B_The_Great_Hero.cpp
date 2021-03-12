#include <bits/stdc++.h>
using namespace std;
int FastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
const int mxn = 1e6;

vector<int> primes;
void makeSieve()
{
    bitset<mxn> sieve(0);
    for (int i = 3; i < sqrt(mxn) + 1; i += 2)
        if (not sieve[i])
            for (int j = i * i; j < mxn; j += i)
                sieve[j] = true;
    primes.push_back(2);
    for (int i = 3; i < mxn; i += 2)
        if (not sieve[i])
            primes.push_back(i);
}

void solve()
{
    int x, y, p;
    cin >> x >> y;
    auto it = upper_bound(primes.begin(), primes.end(), x);
    if (it == primes.begin())
        p = 0;
    else
        p = (--it - primes.begin());
    cout << (p < y ? "Chef" : "Divyam") << '\n';
}

signed main()
{
    makeSieve();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}