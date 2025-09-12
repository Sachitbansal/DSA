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

        int num = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            cout << n - num + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
