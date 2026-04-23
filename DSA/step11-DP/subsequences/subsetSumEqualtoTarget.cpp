class Solution {
  public:
  
    bool f(vector<int> &arr, int sum, int index, vector<vector<int>> &dp) {
        if (sum == 0) return true;
        if (index == arr.size()) return false;
        
        if (dp[index][sum] != -1) return dp[index][sum];
        
        bool one = f(arr, sum, index+1, dp);
        bool two = false;;
        if (sum >= arr[index]) {
            two = f(arr, sum - arr[index], index+1, dp);
        }
        
        return dp[index][sum] = one || two;
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        // vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
        // return f(arr, sum, 0, dp);
        
        
        
        // vector<vector<bool>> dp(arr.size(), vector<bool>(sum+1, 0));
        // for (int i = 0; i < arr.size(); i++) {
        //     dp[i][0] = true;
        // }
        // dp[0][arr[0]] = true;
        // for (int i = 1; i<arr.size(); i++) {
        //     for (int j = 1; j <= sum; j++) {
        //         bool one = dp[i-1][j];
        //         bool two = false;
        //         if (arr[i] <= j) two = dp[i-1][j - arr[i]];
        //         dp[i][j] = one || two;
        //     }
        // }
        // return dp[arr.size()-1][sum];
        
        vector<bool> prev(sum+1, 0);
        vector<bool> curr(sum+1, 0);
        prev[0] = curr[0] = true;
        prev[arr[0]] = true;
        
        for (int i = 1; i < arr.size(); i++) {
            for (int j = 1; j <= sum; j++) {
                bool one = prev[j];
                bool two = false;
                if (arr[i] <= j) two = prev[j - arr[i]];
                curr[j] = one || two;
            }
            prev = curr;
        }
        return prev[sum];
        
        
    }
};