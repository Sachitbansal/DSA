#include <bits/stdc++.h>
using namespace std;

int calculateTotalHours(vector<int>& piles, int speed) {
        int totalH = 0;
        for (int bananas : piles) {
            totalH += ceil((double)bananas / speed);
        }
        return totalH;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int maxPile = *max_element(piles.begin(), piles.end());

        // Initialize low and high pointers
    int low = 1, high = maxPile;
    int ans = maxPile;

    while (low <= high) {
            int mid = (low + high) / 2;
            int totalH = calculateTotalHours(piles, mid);

            // If possible, try smaller speed
            if (totalH <= h) {
                ans = mid;
                high = mid - 1;
            }
            // Otherwise, try larger speed
            else {
                low = mid + 1;
            }
        }
    return ans;
        
}   

int main() {
    vector<int> piles = {3,6,7,11};
    int h = 8;

    int ans = minEatingSpeed(piles, h);

    cout << ans << endl;
   
    return 0;
}
