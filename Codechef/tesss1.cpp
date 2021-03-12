#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, q;
	cin >> n >> q;
	long long h[n ];
	for (int i = 1; i <= n; i++)
	{
		cin >> h[i];
		cout << h[i] << ' ' ;
	}
	long long a[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int p = 1; p <= q; p++)
	{
		vector<long long> v;
		vector<long long> v1;
		int l, ans = 0, flag = 0;
		cin >> l;
		if (l == 1)
		{
			int b, k;
			cin >> b;
			cin >> k;
			a[b] = k;
		}
		else
		{
			int b, c, x;
			cin >> b >> c;  //src b dest c
			if (h[b] <= h[c])
			{
				if (b == c)
				{
					cout << a[b] << endl;
					continue;
				}
				else
				{
					cout << "-1" << endl;
					continue;
				}

			}

			if (b > c)
			{
				//for(int g=1;g<=n;g++)
				//  cout<<h[g]<<" ";
				for (int i = b - 1; i > c; i--)
				{
					if (h[i] > h[c] && h[i] < h[b])
					{
						v.push_back(i);
					}
					else if (h[i] >= h[b])
					{
						cout << "-1" << endl;
						flag = 1;
						break;
					}
				}
				//cout<<flag<<endl;
				// cout<<v.size()<<" ";
				int q[v.size()];
				for (int w = 0; w < v.size(); w++)
				{
					q[w] = v.at(w);
				}
				//  for(int e=0;e<v.size();e++)
				//        std::cout<<q[e]<<" ";
				for (int m = 1; m < v.size(); m++)
				{
					if (h[q[m]] < h[q[m - 1]])
						continue;
					else if (h[q[m]] == h[q[m - 1]])
						q[m - 1] = 0;
					else if (h[q[m]] >= h[b])
					{
						cout << "-1" << endl;
						flag = 1;
						break;
					}
					else
					{
						x = m;
						while (h[q[m]] > h[q[x - 1]] && x - 1 >= 0)
						{
							cout << h[q[x - 1]] << endl;
							q[x - 1] = 0;
							x--;
						}

					}

				}
				//  for(int e=0;e<v.size();e++)
				//        cout<<q[e]<<" ";
				//  cout<<flag<<endl;
				if (flag == 0)
				{
					ans = a[b] + a[c];
					for (int e = 0; e < v.size(); e++)
						if (q[e] == 0)
							continue;
						else
							ans += a[q[e]];
					cout << ans << endl;
				}


			}
			else
			{

				if (b + 1 == c)
				{
					cout << a[b] + a[c] << endl;
					continue;
				}
				//cout<<endl;
				for (int g = 1; g <= n; g++)
					cout << h[g] << " ";
				for (int i = b + 1; i < c; i++)
				{
					if (h[i] > h[c] && h[i] < h[b])
					{
						v1.push_back(i);
					}
					else if (h[i] >= h[b])
					{
						cout << "-1" << endl;
						flag = 1;
						break;
					}
				}
				if (flag == 1)
					continue;
				// cout<<v1.size()<<" ";
				int q1[v1.size()];
				for (int w = 0; w < v1.size(); w++)
				{
					q1[w] = v1[w];
				}
				//   for(int e=0;e<v1.size();e++)
				//         std::cout<<q1[e]<<" ";
				for (int m = 1; m < v1.size(); m++)
				{
					if (h[q1[m]] < h[q1[m - 1]])
						continue;
					else if (h[q1[m]] == h[q1[m - 1]])
						q1[m - 1] = 0;
					else if (h[q1[m]] >= h[b])
					{
						cout << "-1" << endl;
						flag = 1;
						break;
					}
					else
					{
						x = m;
						while (h[q1[m]] > h[q1[x - 1]] && x - 1 >= 0)
						{
							cout << h[q1[x - 1]] << endl;
							q1[x - 1] = 0;
							x--;
						}

					}
				}
				// cout<<flag<<endl;
				//for(int e=0;e<v1.size();e++)
				// cout<<q1[e]<<" ";
				if (flag == 0)
				{
					ans = a[b] + a[c];
					for (int e = 0; e < v1.size(); e++)
						if (q1[e] == 0)
							continue;
						else
							ans += a[q1[e]];
					cout << ans << endl;
				}


			}
		}
	}
}