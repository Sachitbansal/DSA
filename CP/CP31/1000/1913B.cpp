#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        string arr;
        cin >> arr;

        int count0 = 0;
        int count1 = 0;
        int cost = arr.size();

        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] == '1')
                count1++;
            else
                count0++;
        }
        // cout << count0<<" "<<count1<<endl;

        if (count0 == count1)
        {
            cout << 0 << endl;
        }
        else
        {
            int idx = 0;
            while (count0 >= 0 && count1 >= 0)
            {
                if (arr[idx] == '1')
                {
                    count0--;
                }
                else
                {
                    count1--;
                }
                if (count0 >= 0 && count1 >= 0)
                {
                    cost--;
                }
                idx++;
            }
            cout << cost << endl;
        }
    }

    return 0;
}
