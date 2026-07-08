#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n;
int f(vector<string> &grid, int rowIndex, int rowNumber, vector<vector<int>> &dp) {
    if (grid[rowNumber][rowIndex] == '*') return 0;
    if (rowIndex == n-1 && rowNumber == n-1) return 1;

    if (dp[rowNumber][rowIndex] != -1) return dp[rowNumber][rowIndex];

    int ans = 0;
    if (rowIndex +1 < n) ans =(ans + f(grid, rowIndex+1, rowNumber, dp)) % MOD;
    if (rowNumber + 1 < n) ans = (ans + f(grid, rowIndex, rowNumber +1, dp)) % MOD;

    return dp[rowNumber][rowIndex] = ans;
}

int main() {

    //int n;
    cin >> n;
    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    //vector<vector<int>> dp(n, vector<int>(n, -1));

    //cout << f(grid, 0, 0, dp) <<endl;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    if (grid[n-1][n-1] == '.') dp[n-1][n-1] = 1;

    for (int rowIndex = n-1; rowIndex >= 0; rowIndex--) {
        for (int rowNumber = n-1; rowNumber >= 0; rowNumber--) {
            if (grid[rowNumber][rowIndex] == '*') continue;
            if (rowNumber + 1 < n) dp[rowNumber][rowIndex] =(dp[rowNumber][rowIndex] + dp[rowNumber+1][rowIndex]) % MOD;
            if (rowIndex + 1 < n) dp[rowNumber][rowIndex] =(dp[rowNumber][rowIndex] + dp[rowNumber][rowIndex+1]) % MOD;
        }
    }
    cout << dp[0][0] <<endl;
    return 0;
}