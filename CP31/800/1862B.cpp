#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int n;
        cin >> n;

        int arr[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        vector<int> b;
        b.push_back(arr[0]);
        for (int j = 1; j < n; j++) {
            if (arr[j-1] <= arr[j]) {
                b.push_back(arr[j]);
            } else {
                int k = 1;
                while ( arr[j]-k >= arr[j-1]) k++;
                if (arr[j]-k == 0) b.push_back(1);
                else b.push_back(arr[j]-k);
                b.push_back(arr[j]);
            }
            
        }

        cout << b.size() << endl;
        for (int k = 0; k < b.size(); k++) {
            cout << b[k] << " ";
        } 
        cout << endl;


        
    }  

    return 0;
}
