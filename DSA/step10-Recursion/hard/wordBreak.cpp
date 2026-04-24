class Solution {
public:

    bool f(string s, vector<string>& wordDict, int SIndex, vector<int> &dp) {
        if (SIndex == s.size()) return true;
        if (dp[SIndex] != -1) return dp[SIndex];
        bool ans = false;
        for (int i = 0; i < wordDict.size(); i++) {
            int wordLen = wordDict[i].size();
            if (wordDict[i] == s.substr(SIndex, wordLen)) {
                ans = ans || f(s, wordDict, SIndex+wordLen, dp);
            }
        }
        return dp[SIndex] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return f(s, wordDict, 0, dp);
    }
};