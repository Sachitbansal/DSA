#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        int x;
        cin >> n;
        cin >> x;

        int arr[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        int max = arr[0];
        for (int k = 1; k < n; k++) {
            int dist = arr[k] - arr[k-1];
            if (dist > max) max=dist;
        }
        if (n==1) max = arr[0];
        int last = 2*(x - arr[n-1]);

        if (last > max) max = last;
        cout << max << endl;
    }

    return 0;
}