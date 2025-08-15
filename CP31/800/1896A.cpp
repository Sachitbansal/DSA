#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        if (num % 3 == 0) cout << "Second\n";
        else cout << "First\n";
    }   
    return 0;
}