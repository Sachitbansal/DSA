#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int maxAppoearences = 0;
        vector<int> result(n);
        // count maximum '1's that appear together
        int currentCount = 0;
        for (char c : s)
        {
            if (c == '1')
            {
                currentCount++;
                maxAppoearences = max(maxAppoearences, currentCount);
            }
            else
            {
                currentCount = 0;
            }
        }

        if (maxAppoearences >= k)
        {
            cout << "No\n";
            continue;
        } 
        else
        {
            int temp_n = 1;
            int counter = n;

            for (int j = 0; j < n; j++)

            {

                if (s[j] == '1')
                {
                    result[j] = temp_n;
                    temp_n++;
                }
                else
                {
                    result[j] = counter;
                    counter--;
                }
            }
        }
        cout << "Yes\n";
        // Print the string
        for (int j = 0; j < n; j++)
        {
            cout << result[j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
