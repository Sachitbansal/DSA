#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        long long n, w;
        cin >> n >> w;

        int ans = n/w;
   
        cout << n - ans << endl;


    }    

    return 0;
}
