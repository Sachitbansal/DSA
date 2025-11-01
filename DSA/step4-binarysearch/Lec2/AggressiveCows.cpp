#include <bits/stdc++.h>
using namespace std;
bool canPlace(vector<int> arr, int cows, int dist) {
    int las = arr[0];
    int cou = 1;

    for (int i = 1; i < arr.size(); i++){
        if (cows>cou){
            if (arr[i] >= dist+las) {
                las=arr[i];
                cou++;
            }
        } 
          
    }
    if (cou<cows) return false;
    else return true;
}

int aggressiveCows(vector<int>& arr, int k) {
    int low = 1;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int high = arr[n-1]- arr[0];

    while (low <= high) {
        int mid = (low+high)/2;

        if (canPlace(arr, k, mid)) {
            low = mid+1;
        } else high = mid-1;
    }
    return high;

}

int main() {
    vector<int> piles = {0, 3, 4, 7, 10, 9};
    
    int k = 4;
    int ans = aggressiveCows(piles, k);

    cout << ans << endl;
   
    return 0;
}
