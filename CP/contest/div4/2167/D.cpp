#include <bits/stdc++.h>
using namespace std;

long long gcdOfVector(const vector<long long>& nums) {
    if (nums.empty()) return 0; // handle empty case
    long long result = nums[0];
    for (int i = 1; i < nums.size(); ++i)
        result = gcd(result, nums[i]);
    return result;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        vector<long long> arr(n);
        for (int j=0;j<n;j++){
            cin >> arr[j];
        }

        long long ini = gcdOfVector(arr);
        // cout << ini<<endl;
        long long ans = 2;
        long long maxi = *max_element(arr.begin(), arr.end());
        while(gcd(ans, ini) != 1){
            ans++;
            if (ans > maxi){
                ans = -1;
                break;
            }
            
          
        }
        cout << ans<<endl;

    }

    return 0;
}
