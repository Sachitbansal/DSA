class Solution {
public:

    void  f(int num, vector<int> &ans) {
        vector<int> vec;
        while (num) {
            int last = num%10;
            num /= 10;
            vec.push_back(last);
        }
        reverse(vec.begin(), vec.end());
        for (int i : vec) {
            ans.push_back(i);
        }
        
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            f(nums[i], ans);
        }
        return ans;
    }
};