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

            return {-1};
        }

        for (int j = 0; j < arr.size(); j++)
        {
            if (hm.first == arr[j])
            {
                ans[j] = num;
                hm.second--;
                if (hm.second % hm.first == 0)
                {
                    num++;
                }
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
