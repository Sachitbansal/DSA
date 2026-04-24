class Solution {
public:

    void f(vector<string>& ans, vector<string>& mapping, string& curr, string digits, int index) {
        if (curr.size() == digits.size() || index>=digits.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < mapping[digits[index] - '0' - 2].size(); i++) {
            curr.push_back(mapping[digits[index] - '0' - 2][i]);
            f(ans, mapping, curr, digits, index+1);
            curr.pop_back();
        } 


    }

    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string curr = "";

        f(ans, mapping, curr, digits, 0);
        return ans;
    }
};  