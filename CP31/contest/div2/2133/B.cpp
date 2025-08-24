#include <bits/stdc++.h>
using namespace std;


int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        

        long long int n;
        cin >> n;
        
        vector<long long int> arr(n);
        for (long long int j = 0 ; j <n; j++) {
            cin >> arr[j];
        }
        
        sort(arr.begin(), arr.end());

        long long int total = 0;
        int decided = (n % 2 == 0) ? 0 : 1;


        for (long long int j = n-1; j >= decided; j-=2) {
            total += max(arr[j], arr[j-1]);
        }

        if (decided) {
            total += arr[0];
        }

        cout << total << endl;
    }
    return 0;
}  


