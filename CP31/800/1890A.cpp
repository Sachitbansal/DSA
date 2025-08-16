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

        vector<vector<int>> temp;

        for (int j = 0; j < n-1; j++) {

            vector<int> neww;

            for (int k = j+1; k < n; k++) {
                neww.push_back(arr[j] + arr[k]);
            }

            temp.push_back(neww);
        }
        

        set<int> common(temp[0].begin(), temp[0].end());

        for (size_t k = 1; k < temp.size(); k++) {
            set<int> current(temp[k].begin(), temp[k].end());
            set<int> intersection;

            for (int num : common) {
                if (current.count(num)) {
                    intersection.insert(num);
                }
            }
            common = move(intersection);

            if (common.empty()) break; 
        }

        if (common.empty()) {cout << "No" << endl;}
        else cout << "Yes" << endl;

    }   
    return 0;
}