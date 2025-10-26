#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target, int n)
{
    int low=0;
    int high = n-1;
    int ans=0;
    while (low <= high){
        int mid=(low+high)/2;

        if (target <=nums[mid]){
            ans=mid;
            high = mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
    
}

int upperBound(vector<int>& nums, int target, int n)
{
    int low=0;
    int high = n-1;
    int ans=0;
    while (low <= high){
        int mid=(low+high)/2;

        if (target <nums[mid]){
            ans = mid;
            high = mid-1;
        } else {
            low=mid+1;
        }
    }
    return ans;
    
}

int floor (vector<int>& nums, int target, int n) {
    int low=0;
    int high = n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;

        if (target >= nums[mid]){
            low=mid+1;
            ans=mid;
        } else{
            high=mid-1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int lower = lowerBound(nums, target, nums.size());
    int higher = upperBound(nums, target, nums.size());
    int flo = floor(nums, target, nums.size());
    // if (nums[flo]!=target) flo=-1;
    if (nums[lower]!=target) lower=-1;
    return {lower, higher, flo};
}

int main() {
    vector<int> nums = {1};
    int target = 0;

    vector<int> ans = searchRange(nums, target);

    for (auto i: ans) cout << i << endl;
   
    return 0;
}
