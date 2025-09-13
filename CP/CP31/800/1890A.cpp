#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int arr[n];

        for (int j = 0; j <n; j++) cin >> arr[j];

    //   there can only be 2 numbers else condition will not stisfy
        set<int> elements(arr, arr + n);
        bool possible = true;
        if (elements.size() > 2) {
            possible = false;
        }

        int count1 = 0;
        int count2 = 0;

        for (auto j: arr) {
            if (j == *(elements.begin())) count1++;
            else count2++;
        }


        if (count2 == 0) { }
        else if ((count1 - count2) > 1 || (count1 - count2) < -1) { possible = false; }



        if (possible) cout << "Yes\n";
        else cout << "No\n"; 
      

    }   
    return 0;
}