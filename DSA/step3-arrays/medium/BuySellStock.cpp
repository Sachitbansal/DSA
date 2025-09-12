#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int buy = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        int cost = prices[i] - buy;
        profit = max(cost, profit);
        buy = min(buy, prices[i]);
    }
    return profit;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};

    cout << maxProfit(nums);

    return 0;
}
