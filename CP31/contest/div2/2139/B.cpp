#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;

    for (long long i = 0; i < t; i++)
    {
        long long n, m;
        cin >> n >> m;

        long long arr[n];
        for (long long j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        sort(arr, arr + n);
        long long count = 0;
        if (m > n)
        {
            count += (m - n) * (accumulate(arr, arr + n, 0LL));

            for (long long j = 0; j < n; j++)
            {
                count += (j + 1) * arr[j];
            }
            cout << count << endl;
        }
        else
        {
            for (long long j = m; j > 0; j--)
            {
                count += (j)*arr[n + (j - m - 1)];
            }
            cout << count << endl;
        }
    }
    return 0;
}
