#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int breakpoint = -1;

    for (int i = nums.size() - 1; i >= 1; i--)
    {
        if (nums[i] > nums[i - 1])
        {
            breakpoint = i - 1;
            break;
        }
    }
    if (breakpoint == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = nums.size() - 1; i > breakpoint; i--)
    {
        if (nums[breakpoint] < nums[i])
        {
            swap(nums[breakpoint], nums[i]);
            break;
        }
    }
    // sort not needed, we can directlt reverse, think why
    // sort(nums.begin()+breakpoint+1, nums.end());
    reverse(nums.begin() + breakpoint + 1, nums.end());
}

int main()
{
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};

    nextPermutation(nums);

    for (int x : nums)
        cout << x << endl;

    return 0;
}
