#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string arr;
        cin >> arr;
        int count1 = 0;
        for (char x : arr)
        {
            if (x == '1')
                count1++;
        }
        int ans = 0;
        for (int j = n - 1; j >= n - count1; j--)
        {
            // cout << arr[j]<<" "<<j<<endl;
            if (arr[j] == '0')
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
