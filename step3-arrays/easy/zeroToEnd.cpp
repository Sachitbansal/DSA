#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = { 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};

    int p = 7;
    for (int i = 0; i < p; i++) {
        if (arr[i] == 0) {
            while(arr[p]==0) p--;
            swap(arr[i],arr[p]);
        }
    }
    
    for (auto i: arr) {
        cout << i << endl;
    }
    return 0;
}