#include<bits/stdc++.h>
using namespace std;

long long f(vector<long long> &nums, long long time) {
    long long ans = 0;
    for (long long i =  0; i < nums.size(); i++) {
        ans += time / nums[i] ;
    }
    return ans;
}

int main() {
    long long n, t;
    cin >> n >> t;

    vector<long long> nums(n);
    for (long long i = 0; i < n; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    long long l = 0;
    long long r = nums[0] * t;
    while ( l <= r) {
        long long mid = (l +r) >>1;

        long long ans = f(nums, mid);
        if (ans < t) {
            l = mid+1;
        } else{
            r = mid-1;
        }  
    }

    cout << l <<endl;

}