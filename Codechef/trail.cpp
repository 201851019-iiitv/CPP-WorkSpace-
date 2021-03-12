#include <bits/stdc++.h>
using namespace std;

//to check the filtered array
bool check(vector<int> v) {
    int n = v.size();
    if (n % 2 != 0)
        return false;

// to check that no of unique elements in the array are even

    for (int i = 0; i < n; i += 2) {
        if (v[i] != v[i + 1])
            return false;
    }
    return true;
}
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* a = new int[n];
        int* b = new int[n];
        unordered_map<int, int> p, q;

//taking input for array A in the array and tracking the count of unique elements

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (p.count(a[i]) == 1) {
                p[a[i]]++;
            }
            else {
                p[a[i]] = 1;
            }
        }
////taking input for array A in the array and tracking the count of unique elements

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (q.count(b[i]) == 1) {
                q[b[i]]++;
            }
            else {
                q[b[i]] = 1;
            }
        }
//finding the elements present in array A but not in B

        vector<int> v1, v2;
        for (int i = 0; i < n; i++) {
            if (q.count(a[i]) > 0) {
                q[a[i]]--;
                if (q[a[i]] == 0) {
                    q.erase(a[i]);
                }
            }
            else {
                v1.push_back(a[i]);
            }
        }
//finding the elements present in array B but not in A

        for (int i = 0; i < n; i++) {
            if (p.count(b[i]) > 0) {
                p[b[i]]--;
                if (p[b[i]] == 0) {
                    p.erase(b[i]);
                }
            }
            else {
                v2.push_back(b[i]);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

//checking the array and finding the minimum cost minimum cost is stored in ans1

        if (check(v1) == true && check(v2) == true && v1.size() == v2.size()) {
            long long int ans1 = 0;
            for (int i = 0; i < v1.size(); i += 2) {
                ans1 = ans1 + min(v1[i], v2[v1.size() - 1 - i]);
            }

            cout << ans1 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}