class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max = prices[0];
        int ans = max - min;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min) min = max = prices[i];
            else if (prices[i] > max && prices[i] - min > ans) {
                max = prices[i];
                ans = max - min;
            }
        }
        return ans;
    }
};