class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    } else if (dp[i] == 1 + dp[j]) {
                        count[i]+= count[j];
                    }
                }
            }
            ans = max(ans, dp[i]);
        }

        int final = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == ans) final += count[i];
        }
        return final;
        
    }
};