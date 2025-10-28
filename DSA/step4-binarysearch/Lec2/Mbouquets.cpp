#include <bits/stdc++.h>
using namespace std;

bool cont(vector<int>& bloomDay, int m, int k, int mid) {
    int count=0;
    int month=0;
    for (int i: bloomDay){
        if (mid >=i){
            count ++;
            if (count>=k) {
                month ++;
                count=0;
            }
            if (month >= m) return true;
        }
        else {
            count =0;
        }
        // cout << month<<endl;
    }
    return false;
    
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    if (!cont(bloomDay, m,k,high)) return -1;
    else cout << "fine"<<endl;

    while (low <= high){
        int mid = (low + high)/2;
        bool fine = cont(bloomDay, m,k,mid);
        if (fine) {
            high = mid-1;
            // cout << "fine"<<endl;
        } else {
            low = mid+1;
        }
    }
    
    return low;
}

int main() {
    vector<int> piles = {1,10,3,10,2};
    int m = 3;
    int k = 2;

    int ans = minDays(piles, m,k);

    cout << ans << endl;
   
    return 0;
}
