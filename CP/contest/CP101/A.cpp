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

        int countOdd = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] % 2 == 1)
            {
                countOdd++;
            }
        }

        if (countOdd % 2 == 1)
        {
            cout << "Adnan" << endl;
        }
        else
            cout << "Draw" << endl;
    }
    return 0;
}
