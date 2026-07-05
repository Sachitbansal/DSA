class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        unordered_map<long, long> mp;
        mp[0] = 1;
        // mp[arr[0]] = 1;
        
        long ans = 0;
        long xorr = 0;
        for (int i = 0; i < arr.size(); i++) {
            xorr = xorr ^ arr[i];
            
            // checking for required number
            
            if (mp.find(k ^ xorr) != mp.end()) {
                ans += mp[k ^ xorr];
            }
            
            mp[xorr]++;
            
        }
        return ans;
    }
};