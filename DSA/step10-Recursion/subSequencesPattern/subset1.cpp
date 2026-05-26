class Solution {
public:

    void make(vector<vector<int>>& ans, vector<int>& nums, int index, vector<int>& curr) {
        int n = nums.size();
        if (index== n) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        make(ans, nums, index+1, curr);
        curr.pop_back();

        make(ans, nums, index+1, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        // vector<vector<int>> answer;
        
        make(ans, nums, 0, curr);
        // for (const auto& it : ans) {
        //     answer.push_back(it);
        // }
        return ans;

    }
};