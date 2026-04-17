class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp; // number -> latest index
        int ans = INT_MAX;

        for (int i = nums.size()-1; i >= 0; i--) {
            int rev = reverseNum(nums[i]);

            // check first
            if (mp.find(rev) != mp.end()) {
                ans = min(ans, abs(i - mp[rev]));
            }

            // then insert/update
            mp[nums[i]] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
