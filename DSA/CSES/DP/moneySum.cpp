#include<bits/stdc++.h>
using namespace std;

void f(int i, vector<int> &nums, set<int> &ans, int curr, vector<vector<bool>> &dp) {
    if (i < 0) return;
    if (dp[i][curr]) return;
    // take
    curr+= nums[i];
    ans.insert(curr);
    f(i-1, nums, ans, curr, dp);
    curr-= nums[i];

    // not take
    f(i-1, nums, ans, curr, dp);

    dp[i][curr] = true;
    return;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    int maxx = 0;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        maxx += nums[i];
    }
    
    // vector<vector<bool>> dp(n+1, vector<bool>(maxx+1, false));
    // set<int> ans;
    // f(n-1, nums, ans, 0, dp);
    // cout << ans.size() << endl;

    // for ( const int & i : ans) {
    //     cout << i << " ";
    // }

    vector<vector<bool>> dp(n+1, vector<bool>(maxx +1, false));
    dp[n-1][maxx] = true;

    set<int> ans;
    for (int i = 0; i < n; i++) {
        for (int curr = maxx; curr >= 0; curr--) {
            dp[i][curr] = dp[i-1][curr] || dp[i-1][curr - nums[i]];   
         
            if (dp[i][curr]) ans.insert(curr);
        }
    }
    cout << dp[n-1][]
    return 0;
}