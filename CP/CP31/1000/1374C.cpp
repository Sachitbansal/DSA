#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        long long n;
        cin >> n;
        string st;
        cin >> st;

        long long total = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {

            if (st[i] == '(') {
                total--;
            } else total++;
            ans = max(ans, total);

        }


        cout << ans << endl;

    }    

    return 0;
}
