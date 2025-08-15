#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    vector<string> cells;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string cells;
        cin >> cells;

        int dotCountRow = 0;
        int dot = 0;
        for (int j = 0; j < n-2; j++) {
            if (cells[j] == '.' && cells[j+1] == '.' && cells[j+2] == '.') {
                dotCountRow = 1;
                break;
            }
            if (cells[j] == '.') {
                dot ++;
            }
        }
        if (cells[n-2] == '.') {
            dot ++;
        }
        if (cells[n-1] == '.') {
            dot ++;
        }
        if (dotCountRow == 1) cout << 2 << endl;
        else cout << dot << endl;
    }   
    return 0;
}