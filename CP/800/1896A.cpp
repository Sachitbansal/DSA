#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int arr[n];
        bool vertict = true;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            if (arr[0] > arr[j]) {
                vertict = false;
            }
        }
        if (vertict) cout << "Yes" << endl;
        else cout << "NO" << endl;
    }   
    return 0;
}