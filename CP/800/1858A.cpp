#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int n=3;

        int arr[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        if (arr[2] % 2 == 1) arr[0] += (arr[2]/2)+1;
        else arr[0] += (arr[2]/2);
        arr[1] += arr[2]/2;

        if (arr[0] > arr[1]) {
            cout << "First\n";
        } else cout << "Second\n";
        
    }  

    return 0;
}
