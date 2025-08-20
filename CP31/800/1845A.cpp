#include <bits/stdc++.h>
using namespace std;
edwDWEAD
int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        
        vector<int> arr;

        int n;
        int k;
        int x;
        cin >> n >> k >> x;

        int count = 0;
        while(count<n ) {
            if (k==x) {
                count +=k-1;
                arr.push_back(k-1);
            } else {
                count +=k;
                arr.push_back(k);
            }
        }
        if (k == x) count-=k;
        else count -= k-1;
        arr.pop_back();

        while(count != n){
            if (n-count != x) {
                arr.push_back(n-count);
                count += n - count;
            } else {
                int addi = n-count-1;
                while (count<n && addi!=0) {
                    if (n - count >= addi) {
                        count+= addi;
                        arr.push_back(addi);
                    } else addi--;
                }
                break;
            }
        }




        if (count == n) {
            cout << "Yes\n";
            cout << arr.size() << endl;
            for (auto j: arr) {
                cout << j << " ";
            }
            cout << endl;
        } else {
            cout << "No\n";
        }
        
    }  
    return 0;
}
