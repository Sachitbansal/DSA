class Solution {
  public:
  
    int f(vector<int> &arr, int target, int index, int curr, vector<vector<int>> &dp) {
        if (index == -1) {
            if (target == 0) return 1;
            return 0;
        }
        
        if (dp[index][target]!= -1) return dp[index][target];
        
        int notTake = f(arr, target, index-1, curr, dp);
        int take = 0;
        if (target >= arr[index]) {
            take = f(arr, target - arr[index], index-1, curr, dp);
        }
        
        return dp[index][target] = notTake + take;
    }
  
    int perfectSum(vector<int>& arr, int target) {
        
        // vector<vector<int>> dp(arr.size(), vector<int>(target+1, -1));
        
        // return f(arr, target, arr.size()-1, 0, dp);
        
        vector<vector<int>> dp(arr.size(), vector<int>(target+1, 0));
        
        if (arr[0] <= target) dp[0][arr[0]] = 1;
        dp[0][0] = arr[0] == 0 ? 2 : 1;
        
        for (int i = 1; i < arr.size(); i++) {
            for (int j = 0; j <= target; j++) {
                int notTake = dp[i-1][j];
                int take = 0;
                if (j >= arr[i]) take = dp[i-1][j - arr[i]];
                dp[i][j] = take + notTake;
            }
        }
        return dp[arr.size()-1][target];
    }
};






