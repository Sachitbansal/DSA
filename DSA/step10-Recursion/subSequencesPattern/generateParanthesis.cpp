class Solution {
public:

    void generate(int n, int open, int close, vector<string> &ans, string &curr) {
        int len = curr.size();
        if (close == n) {
            ans.push_back(curr);
            return;
        }

        // at the end we want open = 0 and complete = n
        if (open < n) {
            // opening
            curr += '(';
            generate(n, open + 1, close, ans, curr);
            curr.pop_back();
        }

        if (open > close) {
            curr += ')';
            generate(n, open, close + 1, ans, curr);
            curr.pop_back();
        }
        
    }

    vector<string> generateParenthesis(int n) {
        if (n==0) return {};
        vector<string> ans;
        string curr = "(";

        generate(n, 1, 0, ans, curr);
        return ans;
    }
};