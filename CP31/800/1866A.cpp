#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    int num;
    int smallest = INT_MAX;
    for (int i = 0; i < t; i++) {
        cin >> num;
        if (num < 0) num *= -1;
        if (smallest > num) smallest = num;
    }
    cout << smallest << endl;
    return 0;
}
