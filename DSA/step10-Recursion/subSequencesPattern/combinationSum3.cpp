class Solution {
public:

    void f(vector<vector<int>>& ans, vector<int>& curr, int k, int n, int index) {
        if (k==0 && n==0) {
            ans.push_back(curr);
            return;
        } else if (n <0 || k<0 || index==10) return;
        
        if (index <= n) {
            curr.push_back(index);
            f(ans, curr, k-1, n-index, index+1);
            curr.pop_back();
        }

        f(ans, curr, k, n, index+1);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;

        f(ans, curr, k, n, 1);
        return ans;
    }
};