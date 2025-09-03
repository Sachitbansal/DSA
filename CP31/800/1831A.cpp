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
        {
            cin >> arr[j];
        }

        int arrf[n];

        for (int j = 0; j < n; j++)
        {
            arrf[j] = n - arr[j] + 1;
        }

        for (int j = 0; j < n; j++)
        {
            cout << arrf[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
