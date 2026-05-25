class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        // Code here
        int n = arr.size();
        int ans = 1;
        vector<int> dp(n, 1);
        vector<int> hash(n);
        int ind = 0;
        
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                    if (dp[i] > ans) {
                        ans = dp[i];
                        ind = i;
                    }
                }
            }

        }
        // startin from ind as the in idex
        // cout << ans <<endl;
        // for (int i : hash) {
        //     cout << i <<endl;
        // }
        vector<int> anss;
        anss.push_back(arr[ind]);
        while(hash[ind] != ind) {
            ind = hash[ind];
            anss.push_back(arr[ind]);
        }
        
        reverse(anss.begin(), anss.end());
        return anss;
        
    }
};