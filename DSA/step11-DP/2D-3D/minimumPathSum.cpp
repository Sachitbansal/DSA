class Solution {
public:

    int f(vector<vector<int>>& grid, int x, int y, vector<vector<int>> &dp) {
        if (x < 0 || y < 0) return INT_MAX;
        if (x==0 && y == 0) return grid[0][0];

        if (dp[x][y] != -1) return dp[x][y];
        
        return dp[x][y] = grid[x][y] + min(f(grid, x-1, y, dp), f(grid, x, y-1, dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = grid[0][0];

        // return f(grid, grid.size()-1, grid[0].size()-1, dp);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j==0 && i==0) continue;
                int left = INT_MAX;
                int right = INT_MAX;

                if (i>0) left = dp[i-1][j];
                if (j>0) right = dp[i][j-1];
                dp[i][j] = grid[i][j] + min(left, right);
            }
        }
        return dp[m-1][n-1];
    }
};