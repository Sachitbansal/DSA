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
        int cost = n;
        int count0 = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
            if (arr[j] == j + 1)
                cost--;
            else if (arr[j] == 0)
                count0++;
        }
        // cout << cost;

        int index = 0;
        long long total = n * (n + 1) / 2;

        if (count0 == 1)
        {
            if (cost == 1)
            {
                cout << 0 << endl;
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (arr[j] == 0)
                    {
                        index = j;
                    }
                    total -= arr[j];
                }
                if (index == (total - 1))
                {
                    cost--;
                }
                cout << cost << endl;
            }
        }
        else
        {
            cout << cost << endl;
        }
    }

    return 0;
}
