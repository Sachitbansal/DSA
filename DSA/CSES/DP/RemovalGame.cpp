#include<bits/stdc++.h>
using namespace std;

long long f(vector<int> &nums, int l, int r, vector<vector<long long>> &dp) {

    if(l == r) return nums[l];
    if (dp[l][r] != -1) return dp[l][r];
    return dp[l][r] = max(nums[l] - f(nums, l+1, r, dp), nums[r] - f(nums, l, r-1, dp));
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    long long total = 0;
    for (int i = 0; i < n; i++){
        cin >> nums[i];
        total += nums[i];
    }
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1));

    //cout <<  (total + f(nums, 0, n-1, dp))/2 <<endl;
    
    for (int l = 0; l < n; l++) {
        for (int r = 0; r < n; r++) {
            if (l == r) dp[l][r] = nums[l];
        }
    }

    for (int l = n-1; l >= 0; l--) {
        for (int r = l+1; r < n; r++){
            if (r < l) continue;
            dp[l][r] = max(nums[l] - dp[l+1][r], nums[r] - dp[l][r-1]);
        }
    }
    cout << (total + dp[0][n-1]) /2;

    return 0;
}
