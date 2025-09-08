#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int k, x;
        cin >> k >> x;

        int c = pow(2, k);
        int v = pow(2, k);
        bool doubled = false;
        vector<int> ans;
        if (x % 2 != 0 || c > x)
        {
            x *= 2;
            doubled = true;
        };
        while (c != x)
        {
            if (c < x)
            {
                if (v % 2 == 0)
                {
                    c *= 2;
                    v /= 2;
                    ans.push_back(2);
                }
                else
                {
                    c /= 2;
                    v *= 2;
                    ans.push_back(1);
                }
            }
            else if (c > x)
            {
                if (c % 2 == 0)
                {
                    c /= 2;
                    v *= 2;
                    ans.push_back(1);
                }
                else
                {
                    c *= 2;
                    v /= 2;
                    ans.push_back(2);
                }
            }
            else
            {
                if (doubled)
                {
                    ans.push_back(1);
                }
                cout << ans.size() << endl;
                for (int x : ans)
                {
                    cout << x << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
