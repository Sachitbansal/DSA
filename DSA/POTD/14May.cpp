class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n==1) return false;
        cout << n<<endl;
        // sequence til 1 to n-1 and last digit be n-1
        for (int i = 1; i <= n-1; i++) {
            // cout << nums[i-1] << " " <<i <<endl;
            if (nums[i-1] != i) return false;
        }
        if (nums[n-1] != nums[n-2]) return false;

        return true;
    }
};