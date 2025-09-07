#include <bits/stdc++.h>
using namespace std;

vector<int> ans(map<int, int> counts, vector<int> arr)
{
    int num = 1;
    vector<int> ans(arr.size());
    for (auto hm : counts)
    {
        if (hm.second % hm.first != 0)
        {
            if (hm.second == 1 && hm.first != 1)
                return {-1};
        }
        if (hm.second % hm.first == 0)
            num++;

        for (int j = 0; j < arr.size(); j++)
        {

            if (hm.first == arr[j])
            {
                ans[j] = num;
                hm.second--;
            }
        }
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;
        vector<int> arr(n);
        map<int, int> counts;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
            counts[arr[j]]++;
        }

        vector<int> anss = ans(counts, arr);
        for (int j = 0; j < anss.size(); j++)
        {
            cout << anss[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
