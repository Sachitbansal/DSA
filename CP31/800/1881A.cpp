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

        string arr;
        cin >> arr;
        string arr1;
        cin >> arr1;

        int turn = 0;
        bool found = false;
        if (arr.find(arr1) != string::npos) {
            found = true;
            cout << turn << endl;
            continue;
        }
        while (!found) {
            if (arr.find(arr1) != string::npos) {
                found = true;
                continue;
            } else if (arr.length() >= 4*arr1.length() && turn>2) {
                turn = -1;
                break; 
            }
            arr += arr;
            turn++;
        }

        cout << turn << endl;
        
    }   
    return 0;
}