#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (long long i = 0; i < t; i++)
    {
        long long n;
        cin >> n;

        long long odd = 0LL;
        long long count = 0LL;

        vector<long long> dand;
        for (long long j = 0LL; j < n; j++)
        {
            long long in;
            cin >> in;
            if (in % 2 == 0)
            {
                count += in;
            }
            else
            {
                dand.push_back(in);
                odd++;
            }
        }
        // cout << count<<endl;

        sort(dand.begin(), dand.end());
        // cout<<dand[odd-1]<<endl;
        // cout<<odd<<endl;

        if (odd == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            count += dand[odd - 1];
            for (long long j = odd - 2; j > ((odd-2) / 2); j--)
            {
                count += dand[j];
            }
            cout << count << endl;
        }
    }

    return 0;
}
