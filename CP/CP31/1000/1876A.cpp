#include <bits/stdc++.h>
using namespace std;

long long ans(int c, int d)
{
    long long total = 0LL;
    while (c > 0)
    {
        c /= d;
        total++;
    }
    return total;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long long n, p;
        cin >> n >> p;

        vector<pair<long long, long long>> arr(n);

        for (long long j = 0LL; j < n; j++)
        {
            cin >> arr[j].first; // ai
        }
        for (long long j = 0LL; j < n; j++)
        {
            cin >> arr[j].second; // bi
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b)
             { return a.second < b.second; });

        long long cost = p;
        long long total = 1LL;
        long long current = 0LL;

        while (total < n)
        {
            if (arr[current].second < p)
            {
                for (long long j = 0; j < arr[current].first; j++)
                {
                    if (total < n)
                    {
                        total++;
                        cost += arr[current].second;
                    }
                }
            }
            else
            {
                cost += p;
                total++;
            }
            current++;
        }

        cout << cost << endl;
    }

    return 0;
}
