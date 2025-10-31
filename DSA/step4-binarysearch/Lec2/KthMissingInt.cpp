#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int low = 0;
    int n = arr.size();
    // if (n==1) {
    //     return k;
    // }
    int high = n-1;

    while(low<= high){
        int mid = (low+high)/2;

        if ((arr[mid]-mid-1) >=k){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return high + k+ 1;

}

int main() {
    vector<int> piles = {2,3,4,7,11};
    int k = 5;

    int ans = findKthPositive(piles, k);

    cout << ans << endl;
   
    return 0;
}
