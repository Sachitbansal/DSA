class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        
        int ans = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (mp[nums[i]].size() >=2) {
                int first = mp[nums[i]][0];
                int second = mp[nums[i]][1];

                int total = abs(first - second) + abs(i - first) + abs(i - second);

                mp[nums[i]][0] = mp[nums[i]][1];
                mp[nums[i]][1] = i;

                ans = min(ans, total);

            } else {
                mp[nums[i]].push_back(i);
            }
            
        }
        if (ans == INT_MAX) return -1;
        return ans;
    }
};