class Solution {
public:
    int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int v = queries[i][3];
            int k = queries[i][2];

            for (int j = l; j <= r; j+= k) {
                nums[j] = (1LL * nums[j]  * v) % mod;
            }
        }

        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;

    }
};