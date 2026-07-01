#include<bits/stdc++.h>
using namespace std;

int f(int w, int h, vector<vector<int>> &dp) {

    if (w==h)return 0;
    if (dp[h][w] != -1) return dp[h][w];
    int ans = 1e9;
    for (int i = 1; i < w; i++) {
        ans = min(ans, 1 +f(w - i, h, dp) + f(i, h, dp));
    }
    for (int i = 1; i < h; i++) {
        ans = min(ans, 1 +f(w, h-i, dp) + f(w, i, dp));
    }
    return dp[h][w] = ans;
}

int main () {

    int w, h;
    cin >> w >> h;

    //vector<vector<int>> dp(h+1, vector<int>(w+1, -1));
    //cout << f(w, h, dp);

    vector<vector<int>> dp(h+1, vector<int>(w+1, 1e9));
    
    for (int a = 0; a <= w; a++) {
        for (int b = 0; b <= h; b++) {
            if (a==b) dp[b][a] = 0;
        }
    }

    for (int a = 1; a <= w; a++) {
        for (int b = 1; b <= h; b++) {

            for (int i = 1; i < a; i++) {
                dp[b][a] = min(dp[b][a], 1 + dp[b][a-i] + dp[b][i]);
            }
            for (int i = 1; i < b; i++) {
                dp[b][a] = min(dp[b][a], 1 +dp[b-i][a] + dp[i][a]);
            }
        }
    }
    cout << dp[h][w]<<endl;

    return 0;
}