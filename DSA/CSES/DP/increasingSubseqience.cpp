#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> temp;
    temp.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        if (nums[i] > temp.back()) {
            temp.push_back(nums[i]);
        } else {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            nums[ind] = nums[i];
        }
    }
    cout << temp.size();

    return 0;
}