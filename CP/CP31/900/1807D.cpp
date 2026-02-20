#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n, q;
        cin >> n >> q;

        vector<int> arr(n);
        long long sum = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            mp[i] = sum;
        }
    

        int l,r,k;
        for (int i = 0; i < q; i++ ) {
            cin >> l >> r >> k;
            long long total = sum;
            total += (1LL*(r-l+1)*k);
            if (l==1) {
                total -= mp[r-1];
            } else total -= mp[r-1] - mp[l-2];
           
            if (total %2 == 1) {
                cout << "YES" << endl;
            } else cout << "NO" << endl;
           
        }
    }    

    return 0;
}
