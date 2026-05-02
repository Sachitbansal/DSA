class Solution {
  public:
  
    int f(vector<int> &height, int index, vector<int>& dp) {
        if (index == 0) return 0;
     
        if (dp[index] != -1) return dp[index];
        
        int left = f(height, index-1, dp) + abs(height[index] - height[index-1]);
        int right = INT_MAX;
        if (index > 1) right = f(height, index-2, dp) + abs(height[index] - height[index-2]);
        
        dp[index] = min(right, left);
        
        return dp[index];
    }
  
    int minCost(vector<int>& height) {
        // Code herei
        int n = height.size();
        vector<int> dp(n, INT_MAX);
        
        dp[0] = 0;
        int prev = 0;
        int prevS = INT_MAX;
        
        for (int i = 1; i < n; i++) {
            
            int right = INT_MAX;
            if (i>1) {
                // right = dp[i-2] + abs(height[i] - height[i-2]);
                right = prevS + abs(height[i] - height[i-2]);
            }
            // int left = dp[i-1] + abs(height[i] - height[i-1]);
            int left = prev + abs(height[i] - height[i-1]);
            prevS = prev;
            prev = min(left, right);
        }
        
        return prev;
    }
};
