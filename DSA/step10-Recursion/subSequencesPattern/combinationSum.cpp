class Solution {
public:

    void generate(vector<int>& candidates, int target, vector<int> &curr, vector<vector<int>> &ans, int index) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        } else if (index >= candidates.size()) { return;}

        // picking element at current index
        if (candidates[index] <= target) {
            curr.push_back(candidates[index]);
            generate(candidates, target - candidates[index], curr, ans, index);
            curr.pop_back();
        }

        generate(candidates, target, curr, ans, index + 1);
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
    

        generate(candidates, target, curr, ans, 0);
        return ans;
    }
};