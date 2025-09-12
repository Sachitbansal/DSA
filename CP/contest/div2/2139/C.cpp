#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long long k, x;
        cin >> k >> x;

        long long c = 1LL << k;
        
        long long total = 1LL << (k + 1);
        vector<int> ans;

        while (x != c)
        {
            if (c < x)
            {
                long long neww = 2 * x - total;
                if (neww > x)
                {
                    ans.push_back(1);
                }
                else
                {
                    ans.push_back(2);
                }
                x = neww;
            }
            else
            {
                x *= 2;
                ans.push_back(1);
            }
        }

        cout << ans.size() << endl;
        for (int z = ans.size() - 1; z >= 0; z--)
        {
            cout << ans[z] << " ";
        }
        cout << endl;
    }
    return 0;
}
