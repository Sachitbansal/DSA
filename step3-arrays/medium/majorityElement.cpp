#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int num=0;
    int count=0;
    for (int j=0;j<nums.size();j++){
        if(count==0) num=nums[j];
        if (nums[j]==num) count++;
        else count--;
    }
    int final=0;
    for (int j=0;j<nums.size();j++){
        if (nums[j]==num) final++;
    }
    // cout << final <<" "<<count<<" "<<num <<endl;
    if (final > nums.size()/2)
        return num;
    return -1;
}

int main()
{
    vector<int> nums = {6,5,5};

    int ans = majorityElement(nums);

    cout << ans << endl;

    return 0;
}
