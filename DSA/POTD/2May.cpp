class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        vector<int> dp(n+1, -1);
        while (n) {
            int digi = n;
            int invalid = false;
            int foundValid = false;
            while (digi) {
                int last = digi % 10;
                digi /= 10;
                if (dp[digi] != -1) {
                    ans += dp[digi];
                    break;
                }
                if (last == 3 || last == 4 || last == 7 ) {
                    invalid = true;
                    break;
                }
                if (last == 2 || last == 5 || last == 6 || last == 9) {
                    // ans++;
                    foundValid = true;
                    // break;
                }
            } 
    
            if (invalid == false && foundValid) {
                ans++;
                if (dp[n]==-1) dp[n] = ans; 
            }
            n--;
            
        }
        return ans;
    
    }
};