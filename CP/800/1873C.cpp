#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        vector<vector<int>> points = {
            {1,1,1,1,1},
            {1,2,2,2,2},
            {1,2,3,3,3},
            {1,2,3,4,4},
            {1,2,3,4,5},
        };
        string line;
        int score = 0;
        for (int j = 0; j < 10; j++) {
            cin >> line;
            for (int k = 0; k < 10; k++) {
                if (line[k] == 'X') {
                    if (j>4) {
                        if (k>4) score+=points[9-j][9-k];
                        else score += points[9-j][k];
                    } else {
                        if (k>4) score+=points[j][9-k];
                        else score += points[j][k];
                    }
                }
                
            }
        }
        cout << score << endl;  
        
    }   
    return 0;
}
