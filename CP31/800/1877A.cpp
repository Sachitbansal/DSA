#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        int arr;

        int total = 0;
        for (int i = 0; i < n-1; i++){
            cin >> arr;
            total += arr;
        }
        cout << -1 * total << endl;
        
    }   
    return 0;
}
