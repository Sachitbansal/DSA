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

        int arr1[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr1[j];
        }
        int arr2[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr2[j];
        }

        vector<int> ans(n);
        ans[n - 1] = arr2[n - 1];

        for (int j = n - 1; j >= 1; j--)
        {
            int temp = arr2[j] - arr1[j];
            if (temp < arr2[j - 1])
            {
                ans[j - 1] = temp;
            }
            else
            {
                ans[j - 1] = arr2[j - 1];
            }
        }

        for (int j : ans)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
