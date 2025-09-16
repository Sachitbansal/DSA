#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int arr[n];
        int minmod = 99999;

        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
            if (arr[j] % k == 0)
            {
                minmod = 0;
            }
            else if (k - (arr[j] % k) < minmod)
            {
                minmod = k - (arr[j] % k);
            }
        }
        // if (minmod != 0)
        //     cout << k - minmod << endl;
        // else
        cout << minmod << " " << k << endl;
    }

    return 0;
}
