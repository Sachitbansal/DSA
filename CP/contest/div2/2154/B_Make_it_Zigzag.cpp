#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
    
        int arr[n];
        for (int j=0;j<n;j++){
            cin >> arr[j];
        }

        int mac=0;
        int count=0;
        for (int j=0;j<n;j++){
            mac= max(arr[j], mac);
            if (j%2==1){arr[j]=mac;}
        }

        // for (int j=0;j<n;j++){
        //     cout << arr[j]<<endl;
        // }
        
        for (int j=1;j<n;j+=2) {
            if (arr[j]<= arr[j-1]){
                count += arr[j-1]-arr[j]+1;
                arr[j-1]=arr[j]-1;
            }
            if (j+1 < n){
                if (arr[j]<= arr[j+1]){
                count += arr[j+1]-arr[j]+1;
                arr[j+1]=arr[j]-1;       
            }
            }
            
            // cout << count<<endl;
        }
        cout << count<<endl;
        
    }  
    return 0;
}
