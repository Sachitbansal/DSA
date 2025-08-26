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

        vector<int> pos;
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == 0)
            {
                if (!pos.empty())
                {
                    if (j - pos.back() == 1)
                    {
                        continue;
                    }
                    else
                        pos.push_back(j);
                }
                else
                    pos.push_back(j);
            }
        }

        int sizee = pos.size();
  

        bool checked = false;
        for (int j : arr)
        {
            if (j != 0)
            {
                checked = true;
                break;
            }
        }
        if (!checked)
        {
            cout << 0 << endl;
            continue;
        }
        if (sizee == 0)
        {
            cout << 1 << endl;
        }
        else if (sizee == 1)
        {
            if (pos[0] == 0)
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        else if (pos[0] == 0 && arr[pos.back()] == 0)
        {
            cout << sizee - 1 << endl;
        }
        else if (pos[0] != 0 && pos[sizee] != 0)
        {
            cout << sizee + 1 << endl;
        }
        else
            cout << sizee << endl;
    }

    return 0;
}
