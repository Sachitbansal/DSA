#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        c -= a;
        d -= b;
        int poss = false;
        int count = 0;
        if (d >= 0 && c <= d)
        {
            poss = true;
            count += d;
            count += abs(c - d);
        }
        if (poss)
            cout << count << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
