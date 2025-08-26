#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int x, k;
        cin >> x >> k;

        int steps=0;
        vector<int> arr;
        int total=0;
        int temp=x;
        while (total!=x) {

            if (temp % k != 0 && total + temp <= x) {
                total += temp;
                steps++;
                arr.push_back(temp);
            } else {
                temp--;
           }
        }
        cout << steps << endl;
        for (int j: arr) {
            cout << j << " ";
        } cout << endl;


        



        
        
    }  
    return 0;
}
