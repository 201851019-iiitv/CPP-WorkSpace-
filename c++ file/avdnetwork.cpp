

    #include <iostream>
    #include <vector>
    #include <cstring>
    #include <algorithm>
    using namespace std;
    #define ll long long
    #define MAX 2000000
    #define P1 1361
    #define P2 10000019
    #define P3 107
    #define MOD 1000000007
    #define X 212072634227239451
    int fact[MAX + 5], ifact[MAX + 5];
    inline int mul(int x, int y) {
        ll z = 1LL * x * y;
        if (z >= MOD) {
            z %= MOD;
        }
        return z;
    }
    inline int add(int x, int y) {
        int z = x + y;
        if (z >= MOD) {
            z -= MOD;
        }
        return z;
    }
    inline int sub(int x, int y) {
        int z = x - y;
        if (z < 0) {
            z += MOD;
        }
        return z;
    }
    inline int fastExp(int x, int y) {
        int z = 1;
        while (y) {
            if (y & 1) {
                z = mul(z, x);
            }
            y >>= 1;
            x = mul(x, x);
        }
        return z;
    }
    void preCompute(int n) {
        fact[0] = ifact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = mul(fact[i - 1], i);
            ifact[i] = mul(ifact[i - 1], fastExp(i, MOD - 2));
        }
    }
    int getCategory(ll no) {
        if (no % X == 0) {
            return 3;
        } else if (no % P2 == 0) {
            return 2;
        } else if (no % P1 == 0) {
            return 1;
        }
        else if (no % P3 == 0) {
            return 0;
        }
        return -1;
    }
    int getWays(int n, int m) {
        return mul(fact[n + m], mul(ifact[n], ifact[m]));
    }
    int solveTask(vector<pair<int, int> > points) {
        int i, j, x, y, xx, yy, tot, k;
        int memoize[5005];
        k = points.size();
        for (i = 0; i < k; ++i) {
            x = points[i].first;
            y = points[i].second;
            tot = getWays(x - 1, y - 1); //Total no of ways to reach point (x,y)
            for (j = i - 1; j >= 0; --j) {
                xx = points[j].first;
                yy = points[j].second;
                if (yy <= y) {
                    //special point
                    tot = sub(tot, mul(memoize[j], getWays(x - xx, y - yy)));
                }
            }
            //tot = total no of ways to reach point (x,y) without visiting special points
            memoize[i] = tot;
        }
        return memoize[k - 1];
    }
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    //    freopen("in.txt", "r", stdin);
    //    freopen("out1.txt", "w", stdout);
        int n, m, k, w, i,j ,x, y, cat, catDest = -1, cnt[3];
       unsigned long long v;
        vector<pair<int, int> > points[4];
        cin >> n >> m ;
        for(j=1;j<=n;j++)
        {
        for (i = 1; i <= m; ++i) {
            cin >> v;
            if ((cat = getCategory(v)) != -1) {
                if (cat == 3) {
                    points[0].emplace_back(j, i);
                }
                if (cat == 2) {
                    points[1].emplace_back(j, i);
                }
                if (cat == 1) {
                    points[2].emplace_back(j, i);

                points[3].emplace_back(j, i);
            }
          }
            if (j == n and i== m) {
                catDest = getCategory(v);
            }
        }
        }
        preCompute(n + m);
        for (i = 0; i < 3; ++i) {
            if (catDest == -1 or (catDest != 2 and catDest == i)) {
                points[i].emplace_back(n, m);
            }
            sort(points[i].begin(), points[i].end());
        }
        cnt[2] = catDest == -1 ? solveTask(points[2]) : 0;
        cnt[1] = (catDest == 1 or catDest == -1) ? solveTask(points[1]) : 0;
        cnt[0] = (catDest == 0 or catDest == -1) ? solveTask(points[0]) : 0;
        cout << sub(add(cnt[0], cnt[1]), cnt[2]);
        return 0;
    }

