#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int n, k;
        cin >> n >> k;

        string arr;
        cin >> arr;

        map<char, int> count;

        int countEven = 0;
        int countOdd = 0;
        for (char c: arr) {
            count[c]++;
        }

        for (auto &p: count) {
            if (p.second % 2 == 0) {
                countEven++;
            } else countOdd++;
        }
        if (n-k==1) {cout << "Yes\n"; continue;}

        if (countOdd >= k) {
            if (countOdd - k == 1 || countOdd - k == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            } 
        } else {
            cout << "Yes\n";
            
        }

        
        
    }  
    return 0;
}
