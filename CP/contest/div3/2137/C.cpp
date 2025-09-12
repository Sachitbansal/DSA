#include <bits/stdc++.h>
using namespace std;


int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        long long a, b;
        cin >> a >> b;

        if (b%2==0){
            if (a*(b/2) %2==0) cout << a*(b/2) + 2 << endl;
            else cout << -1 << endl;
        } else {
            if (a*(b) %2==1) cout << a*(b) + 1 << endl;
            else cout << -1 << endl;
        }
    }
    return 0;
}
