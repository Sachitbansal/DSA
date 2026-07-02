#include<bits/stdc++.h>
using namespace std;

long long f(int n, int curr, vector<int> dp) {
    if (curr == n) return 1LL;
    if (dp[curr] != -1) return dp[curr];
    long long ans = 0LL;
    for (int i = 1; i <=6; i++) {
        if (i + curr <= n) {
            ans += f(n, curr+i, dp);
        } else break;
    }

    return dp[curr] = ans;
}

int main() {

    int n;
    cin >> n;
    // vector<int> dp(n+1, -1);
    // long long ans = f(n, 0, dp);
    int MOD = 1e9 + 7;
    // cout << ans % MOD<<endl;

    vector<long long> dp(n+1, 0);
    dp[n] = 1LL;

    for (int j = n-1; j >= 0; j--) {
        for (int i = 1; i <=6; i++) {
            if (i + j <= n) {
                dp[j] = (dp[i+j] + dp[j]) % MOD;
            } else break;
        }
    }
    cout << dp[0]%MOD<<endl;

    return 0;
}