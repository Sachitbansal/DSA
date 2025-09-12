#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        int a, b, n;
        cin >> a >> b >> n;

        int arr[n];
        for (int j = 0; j < n; j++){
            cin >> arr[j];
        }
dsadasdsa
        int totalTime = 0;
        int index = 0;
        if (b == 1){
            totalTime=1;
            index=n;
        }
        while (index < n) {

            if (b==1) {
                (arr[index]+b>a) ? b+=arr[index] : b+=a;
                index++;
                b--;
            } else {
                totalTime += b-1;
                b=1;
            }
        }

        cout << totalTime << endl;
    }

        
        
    return 0;
}
