class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        vector<vector<int>> prev(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));

        for (int i = n-1; i >= 0; i--) {
            for (int canBuy = 0; canBuy <= 1; canBuy++) {
                for (int tran = k; tran > 0; tran--) {
                    if (canBuy) {
                        curr[canBuy][tran] = max(
                            -prices[i] + prev[0][tran],
                            prev[1][tran] 
                        );
                    } else curr[canBuy][tran] = max(
                        prices[i] + prev[1][tran-1],
                        prev[0][tran]
                    );
                }
            }
            prev = curr;
        }
        return prev[1][k];
    }
};