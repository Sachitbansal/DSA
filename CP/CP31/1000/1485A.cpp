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

        long long a, b;
        cin >> a >> b;

        long long total = 0;
        if (a == b)
        {
            cout << 2 << endl;
            continue;
        } else if (a < b) {
            cout << 1 << endl;
            continue;
        }
        if (b == 1)
        {
            total += 2;
            b++;
            a /= b;
        }

        while (a > 0)
        {
            long long first = ans(a, b);
            long long second = ans(a, b + 1);
            if (first > second)
            {
                total += 2;
                b++;
                a /= b;
            }
            else
            {
                total += 1;
                a /= b;
            }
        }
        cout << total << endl;
    }

    return 0;
}
