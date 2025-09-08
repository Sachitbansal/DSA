#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a == b)
        {
            cout << 0 << endl;
        }

        else if (b % a == 0 || a % b == 0)
        {
            cout << 1 << endl;
        }
        else
            cout << 2 << endl;
    }
    return 0;
}
