#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int m;
        cin >> m;

        int arr[n];
        bool found = false;
        for (int i = 0; i<n; i++) {
            cin >> arr[i];
            if (arr[i] == m) {
                found = true;
                continue;
            }
        }
        if (found) cout << "Yes\n";
        else cout << "No\n";
        
    }   
    return 0;
}