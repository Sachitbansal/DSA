#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    map<int, int> hashed;
    for (int j =0; j < nums.size(); j++) {
        if (hashed.find(target - nums[j]) != hashed.end()) {
            return {j, hashed[target-nums[j]]};
        } else {
            hashed[nums[j]] = j;
        }
    }
    return {-1};
        
}

int main() {
    vector<int> nums = {3,2,4};
    int target = 6;

    vector<int> ans = twoSum(nums, target);

    for (int i: ans) cout << i << endl;

   
    return 0;
}
