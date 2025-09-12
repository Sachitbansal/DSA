#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int max = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {

        sum += nums[i];
        if (sum > max)
            max = sum;
        if (sum < 0)
            sum = 0;
    }
    return max;
}

int main()
{
    vector<int> nums = {-2, -3};

    int ans = maxSubArray(nums);

    cout << ans << endl;

    return 0;
}
