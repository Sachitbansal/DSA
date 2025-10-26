#include <bits/stdc++.h>
using namespace std;


int searchRotated(vector<int>& nums, int target) {
    int low=0;
    int high = nums.size()-1;
    while (low <= high){
        int mid = (low+high)/2;
        if (nums[mid]==target) return mid;
        
        if (nums[low] <= nums[mid]){
            // left half is sorted
            if (target < nums[mid] && target >= nums[low]){
                high=mid-1;
            } else {
                low =mid+1;
            }
        } else {
            // right half is sorted
            if (target > nums[mid] && target <= nums[high]){
                low=mid+1;
            } else {
                high = mid-1;
            }
        }
    }
    return -1;
}

int searchRotatedDuplicate(vector<int>& nums, int target){
    int low=0;
    int high = nums.size()-1;

    while (low <= high){
        int mid = (low+high)/2;
        if (nums[mid]==target) return mid;
        if (nums[low]==nums[mid] && nums[mid]== nums[high]){
            low = low+1;
            high=high-1;
            continue;
        }
        
        if (nums[low] <= nums[mid]){
            // left half is sorted
            if (target < nums[mid] && target >= nums[low]){
                high=mid-1;
            } else {
                low =mid+1;
            }
        } else {
            // right half is sorted
            if (target > nums[mid] && target <= nums[high]){
                low=mid+1;
            } else {
                high = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {2,5,6,0,0,1,2};
    int target = 3;

    int ans = searchRotated(nums, target);

    cout << ans << endl;

   
    return 0;
}
