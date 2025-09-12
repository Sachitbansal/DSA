#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        int arr[n];
        for (int j = 0; j < n; j++)
            cin >> arr[j];

        int opp = arr[0];
        for (int j = 1; j < n; j++)
            opp ^= arr[j];
        if (n % 2 == 0 && opp != 0)
            cout << -1 << endl;
        else
            cout << opp << endl;
    }
    return 0;
}
