class Solution {
public:

    // get position (x, y) from char index
    vector<int> getPos(int c) {
        return {c / 6, c % 6};
    }

    int dist(int a, int b) {
        if (b == -1) return 0;
        auto p1 = getPos(a);
        auto p2 = getPos(b);
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int dp[301][27][27];

    int f(string &word, int index, int f1, int f2) {
        if (index == word.size()) return 0;

        if (dp[index][f1 + 1][f2 + 1] != -1)
            return dp[index][f1 + 1][f2 + 1];

        int curr = word[index] - 'A';

        int useF1 = dist(curr, f1) + f(word, index + 1, curr, f2);
        int useF2 = dist(curr, f2) + f(word, index + 1, f1, curr);

        return dp[index][f1 + 1][f2 + 1] = min(useF1, useF2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return f(word, 0, -1, -1);
    }
};