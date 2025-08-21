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
        int count = 0;
        int j = 0;
        if (x % k != 0) {
            steps=1;
            arr.push_back(x);
            count += x;
        } else {
            while (x - count > 0 ) {
                // cout << "count "<< x - count - j << endl;
                cout <<  j << endl;
                if ((x - count - j) % k == 0) {
                    // cout << "ran\n";
                    // cout << (x - count - j) % k << endl;
                    j++;
                } else {
                    steps++;
                    arr.push_back(x - count - j);
                    count += x - count - j;
                }
            }
        }
        cout << steps << endl;
        for (auto j: arr) cout << j << " ";
        cout << endl;



        
        
    }  
    return 0;
}
