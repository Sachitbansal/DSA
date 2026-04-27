class Solution {
public:

    int f(int m, int n, int x, int y, vector<vector<int>> &dp) {
        if (x < 0 || y < 0) return 0;
        if (dp[x][y] != -1) return dp[x][y];

        return dp[x][y] = f(m, n, x - 1, y, dp) + f(m, n, x, y-1, dp);
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;

        // return f(m,n,m-1,n-1, dp);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j==0 && i == 0) continue;
                int left = 0;
                int right = 0;
                if (i > 0) left = dp[i-1][j];
                if (j > 0) right = dp[i][j-1];
                
                dp[i][j] = left + right;
            }
        }
        return dp[m-1][n-1];

    }
};