class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int total = 0;
        for (int i : arr) total += i;
        if (diff < 0) diff *=-1;
        
        int target;
        if ((total + diff ) % 2 == 0) target = (total + diff)/2;
        else return 0;
        
        // vector<vector<int>> dp(arr.size(), vector<int>(target+1, 0));
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        
        prev[0] = 1; curr[0] = 1;
        prev[arr[0]] = 1;

        if (arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        
        for (int i = 1; i < arr.size(); i++) {
            for (int j = 0; j <= target; j++) {
                int notTake = prev[j];
                int take = 0;
                if (j >= arr[i]) take = prev[j - arr[i]];
                curr[j] = take + notTake;
            }
            prev = curr;
        }
        
        return prev[target];
    }
};