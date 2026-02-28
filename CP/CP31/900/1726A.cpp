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

        vector<long long> arr(n);
   
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (n==1) {
            cout << 0 <<endl;
            continue;
        }

        long long ans = LLONG_MIN;

        ans = max(ans, *max_element(arr.begin()+1, arr.end()) - arr[0]);
        long long num = 1LL*(arr[n-1] - *min_element(arr.begin(), arr.end()-1));
        ans = max(ans, num);

        for (int i = 0; i < n-1; i++) {
            long long num = (arr[i]-arr[i+1]);
            ans = max(ans, num);
        }

        cout << ans <<endl;

    }    

    return 0;
}
