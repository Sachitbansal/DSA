#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int n;
        cin >> n;

        int arr[n];

        int leastDiff = INT_MAX;

        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            
        }

        for (int j = 1; j < n; j++) {
            if (arr[j] - arr[j-1] < leastDiff) leastDiff = arr[j] - arr[j-1];
        }

        if (leastDiff < 0) {
            cout << 0 << endl;
            continue;
        }

        cout << (leastDiff/2) +1 << endl;
        
    }  
    return 0;
}
