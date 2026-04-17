class Solution {
public:

    int f(vector<int>& nums, int index, vector<int> &dp) {
        if (index == 0) return nums[0];
        if (index < 0) return 0;

        if (dp[index] != -1) return dp[index];

        int pick = nums[index] + f(nums, index-2, dp);
        int notPick = f(nums, index-1, dp);


        return dp[index] = max(pick, notPick);
    } 

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);

        return f(nums, nums.size()-1, dp);

        int prev = nums[0];
        int prevS = 0;

        for (int i = 1; i < nums.size(); i++) {
            int temp = prev;
            prev = max(prev, prevS + nums[i]);
            prevS = temp;
        }
        return prev;
    }
};