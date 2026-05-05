class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        
        int total = 0;
        for (int i : arr) total += i;
        
        int target;
        if ((total + diff ) % 2 == 0) target = (total + diff)/2;
        else return 0;
        
        vector<vector<int>> dp(arr.size(), vector<int>(target+1, 0));
        
        for (int i = 0; i < arr.size(); i++) {
            dp[i][0] = 1;
        }
        dp[0][arr[0]] = 1;
        if (arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        
        for (int i = 1; i < arr.size(); i++) {
            for (int j = 0; j <= target; j++) {
                int notTake = dp[i - 1][j];
                int take = 0;
                if (j >= arr[i]) take = dp[i-1][j - arr[i]];
                dp[i][j] = take + notTake;
            }
        }
        
        return dp[arr.size()-1][target];
    }
};