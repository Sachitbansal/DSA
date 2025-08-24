#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        

        int a;
        cin >> a;
        
        int arr[a];
        for (int j = 0 ; j <a; j++) {
            cin >> arr[j];
        }

        map<int, int> count;
        for (auto j: arr) {
            count[j] ++;
        }
        bool found = false;
        for (auto [key, value] : count) {
            if (value > 1) {
                found = true;
                break;
            } 
        }

        if (found == true) {
                cout << "Yes\n";
        } else cout << "No\n";

    }  
    return 0;
}
