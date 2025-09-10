#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArrayy(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;
    for (int x : nums)
    {
        if (x > 0)
            pos.push_back(x);
        else
            neg.push_back(x);
    }
    int ppos = 0;
    int pneg = 0;
    int ind = 0;
    while (ppos != pos.size() && pneg != neg.size())
    {
        nums[ind++] = pos[ppos++];
        nums[ind++] = neg[pneg++];
    }

    while (ppos != pos.size())
    {
        nums[ind++] = pos[ppos++];
    }
    while (pneg != neg.size())
    {
        nums[ind++] = neg[pneg++];
    }
    return nums;
}

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;
    for (int x : nums)
    {
        if (x > 0)
            pos.push_back(x);
        else
            neg.push_back(x);
    }
    int len = nums.size();
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }
        int ind = neg.size() * 2;

        for (int i = neg.size(); i < pos.size(); i++)
        {
            nums[ind++] = pos[i];
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            nums[2 * i] = pos[i];
            nums[2 * i + 1] = neg[i];
        }
        int ind = pos.size() * 2;

        for (int i = pos.size(); i < neg.size(); i++)
        {
            nums[ind++] = pos[i];
        }
    }

    return nums;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};

    vector<int> ans = rearrangeArray(nums);

    for (int x : ans)
        cout << x << endl;

    return 0;
}
