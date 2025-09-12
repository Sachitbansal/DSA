#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string arr;
        cin >> arr;

        while (arr.front() != arr.back() && arr.size() > 1)
        {
            arr.erase(arr.begin());

            arr.pop_back();
        }

        cout << arr.size() << endl;
    }
    return 0;
}
