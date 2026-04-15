class Solution {
  public:
    int longestSubarray(vector<int>& nums, int k) {
        // code here
        unordered_map<int, int> mp;
        mp[0] = -1;

        int ans = 0;
        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
           
            
            int delta = total - k;
            if (mp.count(delta)) {
                ans = max(ans, i- mp[delta]);
            }
            if (!mp.count(total)) {
                mp[total] = i;
            }
        }
        
        return ans;
    }
};