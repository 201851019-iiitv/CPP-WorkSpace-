#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, x, count = 1, k = 0;
        cin >> n >> x;
        long long int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);




        if (x >= a[n - 1])
        {
            cout << n << endl;
            continue;
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == x)
            {
                k = i;
            }
        }
        long long int i = k;

        while (x < a[n - 1])
        {
            if (a[i] > x)
            {
                x *= 2;
                //cout<<x<<endl;
            }
            else if (a[i] == x)
            {
                x *= 2;
                i++;
                //cout<<x<<endl;
            }
            else if (x / 2 > a[i])
            {

                x *= 2;
                k++;

                i++;
                //cout<<x<<endl;
            }
            else
            {
                x = a[i] * 2;
                i++;
                //cout<<x<<endl;
            }
            count++;
        }
        long long int ans = 0;
        if (i == n - 1)
        {
            ans = count + k;
            cout << ans << endl;
        }
        else
        {
            ans = count + k + n - 1 - i;
            cout << ans << endl;
        }

    }
}