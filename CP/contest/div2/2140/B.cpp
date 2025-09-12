#include <bits/stdc++.h>
using namespace std;

long long getPow10(long long j)
{
    if (j < 10)
        return 10;
    else if (j < 100)
        return 100;
    else if (j < 1000)
        return 1000;
    else if (j < 10000)
        return 10000;
    else if (j < 100000)
        return 100000;
    else if (j < 1000000)
        return 1000000;
    else if (j < 10000000)
        return 10000000;
    else if (j < 100000000)
        return 100000000;
    else
        return 1000000000;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long x;
        cin >> x;

        for (long long j = 1; j < 1e9; j++)
        {
            long long res = getPow10(j);
            if (((x * res) + j) % (x + j) == 0)
            {
                cout << j << "\n";
                break;
            }
        }
    }
    return 0;
}
