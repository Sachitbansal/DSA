class Solution {
public:

    int f(vector<int> &prices, int index, int canBuy, vector<vector<int>> &dp) {
        if (index == prices.size()) return 0;
        if (dp[index][canBuy] != -1) return dp[index][canBuy];
        if (canBuy) {
            return dp[index][canBuy] = max(f(prices, index+1, 1, dp), -prices[index] + f(prices, index+1, 0, dp));
        } else {
            return dp[index][canBuy] = max(f(prices, index+1, 0, dp), prices[index] + f(prices, index+1, 1, dp));
        }
        return -1;
    }   

    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return f(prices, 0, 1, dp);   

        // vector<vector<int>> dp(prices.size() +1, vector<int>(2, 0));
        // // dp[prices.size()][0] = dp[prices.size()][1] = 0;
        
        // for (int i = prices.size()-1; i >= 0; i--) {
        //     for (int j = 0; j < 2; j++) {
        //         if (j==1) {
        //             // canBuy case
        //             dp[i][j] = max(dp[i+1][1], -prices[i] + dp[i+1][0]);
        //         } else {
        //             dp[i][j] = max(dp[i+1][0], prices[i] + dp[i+1][1]);
        //         }
        //     }
        // }
        // return dp[0][1];

        vector<int> prev(2, 0);
        vector<int> curr(2, 0);

        for (int i = prices.size() -1; i >= 0; i--) {
            for (int j = 0; j < 2; j++) {
                if (j==1) {
                    // can buy
                    curr[j] = max(prev[1], -prices[i] + prev[0]);
                } else {
                    curr[j] = max(prev[0], prices[i]+ prev[1]);
                }
            }
            prev = curr;
        }
        return prev[1];
    }
};