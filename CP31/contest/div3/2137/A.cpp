#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int k, x;
        cin >> k >> x;

        for (int j = 0; j < k; j++)
        {
            x*=2;
        }
        cout << x << endl;
    }
    return 0;
}
