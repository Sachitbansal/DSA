class Solution {
  public:
  
    int f(vector<int> & val, vector<int> &wt, int capacity, int index, vector<vector<int>> &dp) {
        if (index == 0) {
            if (wt[index] <= capacity) return val[index] * (capacity / wt[index]);
            return 0;
        }
        
        if (dp[index][capacity] != -1) return dp[index][capacity];
        
        int take = 0;
        if (capacity >= wt[index]) take = val[index] + f(val, wt, capacity - wt[index], index, dp);
        
        int notTake = f(val, wt, capacity, index-1, dp);
        
        return dp[index][capacity] = max(take, notTake);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        // vector<vector<int>> dp(val.size(), vector<int>(capacity+1, -1));
        
        // return f(val, wt, capacity, wt.size()-1, dp);
        
        // vector<vector<int>> dp(val.size(), vector<int>(capacity+1, 0));
        
        // for (int i = 0; i <=capacity; i++) {
        //     if (i >= wt[0]) dp[0][i] = val[0] * (i / wt[0]);
        // }
        
        // for (int i = 1; i < val.size(); i++) {
        //     for (int j = 0; j <= capacity; j++) {
        //         int notTake = dp[i-1][j];
        //         int take = 0;
        //         if (j >= wt[i]) take = val[i] + dp[i][j - wt[i]];
        //         dp[i][j] = max(take, notTake);
        //     }
        // }
        // return dp[val.size()-1][capacity];
        
        vector<int> prev(capacity+1, 0);
        vector<int> curr(capacity+1, 0);
        
        for (int i = 0; i<= capacity; i++) {
            if (i >= wt[0]) prev[i] = val[0] * (i / wt[0]);
        }
        
        for (int i = 0; i < val.size(); i++) {
            for (int j = 0; j <= capacity; j++) {
                int notTake = prev[j];
                int take = 0;
                if (j >= wt[i]) take = val[i] + curr[j - wt[i]];
                curr[j] = max(take, notTake);
            }
            prev = curr;
        }
        return prev[capacity];
    }
};






