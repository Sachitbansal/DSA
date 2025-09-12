#include <bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int> &arr)
{
    int max = arr[arr.size() - 1];

    for (int i = arr.size() - 1; i > 0; i--)
    {
        int prev = arr[i - 1];
        arr[i - 1] = max;
        if (prev > max)
            max = prev;
    }
    arr[arr.size() - 1] = -1;
    return arr;
}

int main()
{
    vector<int> nums = {400};

    vector<int> ans = replaceElements(nums);
    for (int x : ans)
        cout << x << " ";

    return 0;
}
