class Solution {
public:
    int (vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int ans = 0;
        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];

            if (mp.count(total - k)) {
                ans+= mp[total-k];
            }
            if (!mp.count(total)) {
                mp[total] = 1;
            } else mp[total]++;
        }
        return ans;
    }
};