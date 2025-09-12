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

        vector<int> arr(n);
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        int ans = 0;

        map<int, int> count;
        for (int num : arr)
        { 
            count[num]++;
        }


        for (const auto& pair : count)
        {
            if (pair.second < pair.first) {
                count.erase(pair.first);
                arr.erase(remove(arr.begin(), arr.end(), pair.first), arr.end());
            }
            count[pair.first] = 0;
        }

        if (arr.empty()) {
            cout << 0 << endl;
            continue;
        }

        // count the number of spaces between 2 same integers in the map count

        for (int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;

    }

    return 0;
}
