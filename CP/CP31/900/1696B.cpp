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

        vector<int> arr(n);
        int correct = true;
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
            if (correct && arr[j] != 0) correct = false;
        }

        if (correct) {
            cout << 0 << endl;
            continue;
        }

        int parts = 0;
        int p1 = 0;
        int p2 = 1;

        if (arr[0] != 0) {
            parts = 1;
            p2 = 1;
        }

        int segments = 0;
            
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0 && (i == 0 || arr[i-1] == 0)) {
                segments++;
            }
        }
        
        if (segments == 0) cout << 0 << endl;
        else if (segments == 1) cout << 1 << endl;
        else cout << 2 << endl;

    

    }

    return 0;
}
