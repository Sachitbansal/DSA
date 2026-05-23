class Solution {
  public:
  
    int f (vector<vector<int>> &mat, int day, int last, vector<vector<int>> &dp) {
        
        if (dp[day][last] != -1) return dp[day][last];
        
        if (day == 0) {
            int big = 0;
            for (int i = 0; i < 3; i++) {
                if (i!= last) {
                    big = max(big, mat[0][i]);
                }
            }
            return dp[day][last] = big;
        }
        
        int big = 0;
        
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                big = max(big, f(mat, day-1, i, dp) + mat[day][i]);
            }
        }
        return dp[day][last] = big;
        
    }
    int maximumPoints(vector<vector<int>>& mat) {
        vector<vector<int>> dp(mat.size(), vector<int>(4, -1));
       
        // return f(mat, 0, 3, dp);   
        
        // for (int i = 0; i < 4; i++) {
        //     int big = 0;
        //     for (int j = 0; j <4; j++){
        //         if (j!=i) {
        //             big = max(big, mat[0][j]);
        //         }
        //     }
        //     dp[0][i] = big;
        // }
        
        // for (int i = 1; i < mat.size(); i++) {
            
        //     // for ith day 
        //     for (int j = 0; j < 4; j ++){
        //         int big = 0;
        //         for (int k = 0; k < 3; k ++) {
        //             if (k != j) {
        //                 big = max(big, dp[i-1][k] + mat[i][k]);
        //             }
        //         }
        //         dp[i][j] = big;
        //     }
            
        // }
        // return dp[mat.size()-1][3];
        
        
        
        vector<int> prev(4, -1);
        vector<int> prevS(4, -1);
        
        for (int last = 0; last < 4; last++) {
            int big = 0;
            for (int task = 0; task < 4; task++) {
                if(last != task) {
                    big = max(big, mat[0][task]);
                }
            }
            prev[last] = big;
        }
        
        for (int day = 1; day < mat.size(); day++) {
            
            for (int i = 0; i < 4; i ++) prevS[i] = prev[i];
            
            for (int last = 0; last < 4; last++) {
                int big = 0;
                for (int task = 0; task < 3; task++) {
                    if (task != last) {
                        big = max(big, prevS[task] + mat[day][task]);
                    }
                }
                prev[last] = big;
            }
        }
        return prev[3];
        
        
        
    }
};