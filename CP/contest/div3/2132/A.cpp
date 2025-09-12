#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        

        int a, b;
        string arr1, arrb;
        cin >> a;
        cin >> arr1;
        cin >> b;
        cin >> arrb;

        string order;
        cin >> order;


        for (int j = 0; j < b; j++) {
            if (order[j] == 'V') {
                arr1.insert(0, 1, arrb[j]);
            } else {
                arr1.push_back(arrb[j]);
            }
        }
        cout << arr1 << endl;


        
    }  
    return 0;
}
