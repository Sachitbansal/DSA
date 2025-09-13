#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        map<int, int> mp;
        int key, value;

        for (int j = 0; j < n; j++)
        {
            cin >> key >> value;
            mp[key] = value;
        }
        int points = 0;
        int pos = 0;

        auto it = mp.begin();
        if (it->first % 2 == 0)
        {
            if (it->second == 0)
            {

                points += (it->first);
            }
            else
            {
                pos = 1;
                points += (it->first - 1);
            }
        }
        else
        {
            if (it->second == 0)
            {
                points += (it->first - 1);
            }
            else
            {
                pos = 1;
                points += (it->first);
            }
        }
        // cout << points;

        for (auto it = next(mp.begin()); it != mp.end(); ++it)
        {
            // cout << "Current -> " << it->first << " " << it->second << "\n";
            auto prev_it = prev(it); // move one step back
            // cout << "Previous -> " << prev_it->first << " " << prev_it->second << "\n";
            if ((it->first - prev_it->first) % 2 == 0)
            {
                if (pos == it->second)
                {
                    points += (it->first - prev_it->first);
                }
                else
                {
                    pos = 1 ? (pos == 0) : 0;
                    points += (it->first - prev_it->first - 1);
                }
                // cout<<points;
            }
            else
            {
                // cout<<"rnak";
                if (pos == it->second)
                {
                    points += ((it->first - prev_it->first) - 1);
                }
                else
                {
                    pos = 1 ? (pos == 0) : 0;
                    points += (it->first - prev_it->first);
                }
                // cout<<points;
            }
        }

        auto last = prev(mp.end());
        if (last->first != m)
            points += (m - last->first);

        cout << points << endl;
    }

    return 0;
}
