class Solution {
  public:
  
    void check (vector<int>& arr, int k, int index,  bool &ans) {
        
        
        
        // take the val
        if (k == 0) {
            ans = true;
            return;
        }
        if (index >= arr.size()) return;
        if (ans == true) return;
        if (arr[index] <= k) {
            check(arr, k - arr[index], index+1, ans);   
        }
        
        
        // not taking the val
        check(arr,k,index+1, ans);
    }
  
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        bool ans = false;
        
        check(arr, k, 0, ans);
        return ans;
        
    }
};