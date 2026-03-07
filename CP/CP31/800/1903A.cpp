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
        vector<int> arr(n);
        cin >> arr[0];
        bool sorted = true;
        for (int i = 1; i < n; i++) {
            cin >> arr[i];
            if (arr[i] < arr[i-1]) sorted = false;
        }


        if (k == 1 && !sorted) {
            cout << "NO" << endl;
        } else cout << "YES" << endl;

    }
    return 0;
}

