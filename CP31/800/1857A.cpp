#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int n;
        cin >> n;

        int arr;

        int countOdd = 0;

        for (int j = 0; j < n; j++) {
            cin >> arr;
            if (arr % 2 == 1) countOdd++;
        }

        if (countOdd % 2 == 1) cout << "No\n";
        else cout << "Yes\n";
        
    }  
    return 0;
}
