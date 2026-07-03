#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp) {
    if ( i < 0 || j < 0) return 0;

    if (dp[i+1][j+1] != -1) return dp[i+1][j+1];
    if (nums1[i] == nums2[j]) {
        
        return dp[i+1][j+1] = 1 + f(i-1, j-1, nums1, nums2, dp);
    } else {
        int one = f(i-1, j, nums1, nums2, dp);
        int two = f(i, j-1, nums1, nums2, dp);
        return dp[i+1][j+1] = max(one, two);
    }
    return -1;
}

int main() {

    int n, m;
    cin >> n >> m ;
    vector<int> nums1(n);
    vector<int> nums2(m);

    for (int i = 0; i< n; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < m ; i++) cin >> nums2[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout << f(n-1, m-1, nums1, nums2, dp)<<endl;
    
    // printio=ng using dp table
    vector<int> ans;
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
            if (nums1[i-1] == nums2[j-1]) {
                ans.push_back(nums1[i-1]);
                i--;
                j--;
            } else {
                if (dp[i-1][j] > dp[i][j-1]) {
                    i--;
                } else j--;
            }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}