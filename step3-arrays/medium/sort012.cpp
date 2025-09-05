#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {

    int low=0;
    int med=0;
    int high=nums.size()-1;
    
    while (med<=high) {
        
        if (nums[med]==0) {
            swap(nums[low], nums[med]);
            med++;
            low++;
        }
        else if (nums[med]==2) {
            swap(nums[high], nums[med]);
            high--;
        } else med++;

    }

}

int main() {
    vector<int> nums = {2,0,1};
    sortColors(nums);
    for (int i: nums) cout << i << " ";
    cout << endl;
   

   
    return 0;
}
