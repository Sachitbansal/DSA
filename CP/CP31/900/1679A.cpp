#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        long long n;
        cin >> n;

        long long min = 0;
        long long max = 0;

        if (n < 4 || n % 2 == 1) {
            cout << -1 <<endl;
            continue;
        } else {
            min = (n+5)/6;
            max = n/4;
        }

        cout << min << " " << max <<endl;

    }

    return 0;
}
