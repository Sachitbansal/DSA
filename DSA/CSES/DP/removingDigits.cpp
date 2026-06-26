#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<long long> &dp) {
    if (n == 0) return 0;

    int copy = n;
    int ans = 1e8;
    if (dp[n] != -1) return dp[n];
    while(copy) {
        int last = copy % 10;
        if (last != 0) ans = min( 1 +f(n - last, dp), ans);
        copy = copy / 10;
    }
    return dp[n] = ans;
}

int main() {

    int n;
    cin >> n;
   // vector<long long> dp(n+1, -1);
   // cout << f(n, dp) <<endl;
    vector<long long> dp(n+1, 1e8);
    dp[0] = 0;

    for (int i = 0; i <= n; i++) {
        int copy = i;
        while (copy) {
            int last = copy % 10;
            if (last != 0) dp[i] = min(1 + dp[i - last], dp[i]);
            copy = copy / 10;
        }
    }

    cout << dp[n]<<endl;
    return 0;
}