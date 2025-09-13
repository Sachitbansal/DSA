#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int n;
        cin >> n;

        int arr[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        set<int> s (arr, arr+n);
        vector<int> b;
        vector<int> c;

        int a = INT_MAX;
        for (auto j: s) {
            if (a > j) {
                a = j;
            }
        }

        for (auto j: arr) {
            if (a == j) {
                b.push_back(j);
            } else c.push_back(j);
        }

        if (b.size() == 0 || c.size() == 0) {
            cout << -1 << endl;
        } else {
            cout << b.size() << " " << c.size() << endl;
            for (auto j: b) {
                cout << j << " ";
            }
            cout << endl;
            for (auto j: c) {
                cout << j << " ";
            }
            cout << endl;
        }


        
    }  
    return 0;
}
