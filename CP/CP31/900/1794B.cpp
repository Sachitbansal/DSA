#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        vector<long long> arr(n);
   
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i]==1) {
                arr[i]++;
            }
        }


        for (int i = 1; i < n; i++) {
            // if (arr[0]==1) arr[0]++;
            if (arr[i]%arr[i-1] == 0) {
                arr[i]++;
            }
        }
        for (int i = 1; i < n; i++) {
            // if (arr[0]==1) arr[0]++;
            if (arr[i]%arr[i-1] == 0) {
                arr[i]++;
            }
        }


        for (auto i : arr) {
            cout << i << " ";
        } cout << endl;

    }    

    return 0;
}
