#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
long long f(int x, vector<int> &coins, vector<int> &dp) {
    if (x == 0) return 1;

    if (dp[x] != -1) return dp[x];
    int ways = 0;
    for (int i : coins) {
        if (x >= i) {
            ways = (ways + f(x - i, coins, dp)) % MOD;
        }
    }
    return dp[x] = ways;    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >>x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    //vector<int> dp(x+1, -1);
    //long long ans = f(x, coins, dp);
    //cout << ans % MOD<<endl;

    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for (int j = 1; j <= x; j++) {
       
        for (int i : coins) {
            if (j >= i) {
                dp[j] = (dp[j] + dp[j-i]) % MOD;
            }
        }
     
    }
    cout << dp[x] % MOD <<endl;

    return 0;
}