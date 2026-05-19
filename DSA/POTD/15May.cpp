class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
    int high = nums.size()-1;
    int min=INT_MAX;
    while (low<=high){
        int mid=(low+high)/2;

        if (nums[low]<= nums[mid]){
            // left is sorted
            if (nums[low] < min) {
                min=nums[low];
                // low = mid+1;
            }
            low = mid+1;
        } else {
            // right is sorted
            if (nums[mid] < min) {
                min=nums[mid];
                // high = mid-1;
            }
            high = mid-1;

        }
    }
    return min;
    }
};