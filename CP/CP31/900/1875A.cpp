#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long t;
    cin >> t;

    for (long long i = 0; i < t; i++)
    {

        long long a, b, n;
        cin >> a >> b >> n;

        long long arr[n];
        for (long long j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        long long total = 0;
        total -= n;
        total += b;

        for (long long j = 0; j < n; j++)
        {
            total += min(arr[j] + 1, a);
        }
        cout << total << endl;
    }

    return 0;
}
