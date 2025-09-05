#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        long long n, k;
        cin >> n >> k;
        bool found = false;

        if ((n) % 2 == 0)
            found = true;
        else if ((n % k) % 2 == 0)
            found = true;
        else if ((n - k) % 2 == 0)
            found = true;
        if (found)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
