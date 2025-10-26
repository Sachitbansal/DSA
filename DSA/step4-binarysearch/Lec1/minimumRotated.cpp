#include <bits/stdc++.h>
using namespace std;

int mini(vector<int>& nums){
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

// index of the snallest element is the number of times the array has been rotated.
int main() {
    vector<int> nums = {3,4,5,1,2};
    int target = 3;

    int ans = mini(nums);

    cout << ans << endl;

   
    return 0;
}
