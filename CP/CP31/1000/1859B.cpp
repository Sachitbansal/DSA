#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{

    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> arr(n);

        for (ll j = 0; j < n; j++)
        {
            ll num;
            cin >> num;
            vector<ll> vec(num);
            for (ll k = 0; k < num; k++)
            {
                cin >> vec[k];
            }
            ll min1 = LLONG_MAX;
            ll min2 = LLONG_MAX;
            for (ll k = 0; k < num; k++)
            {
                if (vec[k] < min1)
                {
                    min2 = min1;
                    min1 = vec[k];
                }
                else if (vec[k] < min2)
                {
                    min2 = vec[k];
                }
            }
            arr[j] = {min1, min2};
        }

        sort(arr.begin(), arr.end(), [](auto &a, auto &b)
             { return a.second < b.second; });

        ll min = LLONG_MAX;
        ll beauty = 0;

        if (n > 1)
        {
            for (auto &p : arr)
            {
                beauty += p.second;
                if (min > p.first)
                    min = p.first;
            }
            // cout << min << endl;

            auto p = arr[0];
            // cout << p.first << " " << p.second << endl;
            beauty -= p.second;
            beauty += min;
        }
        else
        {
            auto &p = arr[0];
            beauty = p.first;
        }
        cout << beauty << endl;
    }

    return 0;
}
