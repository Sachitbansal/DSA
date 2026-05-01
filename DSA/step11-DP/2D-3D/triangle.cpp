class Solution {
public:

    int f(vector<vector<int>>& triangle, int level, int index, vector<vector<int>>& dp) {
        if (index >= triangle[level].size()) return INT_MAX;
        if (dp[level][index] != -1) return dp[level][index];
        if (level == triangle.size()-1) return triangle[level][index];
        
        return dp[level][index] = triangle[level][index] + min(f(triangle, level+1, index, dp), f(triangle, level+1, index+1, dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        vector<vector<int>> dp;
        for (int i = 0; i < triangle.size()-1; i++) {
            vector<int> dp1(triangle[i].size(), -1);
            dp.push_back(dp1);
        }
        dp.push_back(triangle[triangle.size()-1]);

        // return f(triangle, 0, 0, dp);

        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                // if (j == triangle[i].size()-1) {
                //     dp[i][j] = triangle[i][j] + dp[i+1][j];
                //     continue;
                // }
                dp[i][j] = triangle[i][j] + min(dp[i+1][j], dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};