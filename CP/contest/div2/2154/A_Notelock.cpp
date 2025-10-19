#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        

        int n,k;
        cin >> n>>k;
        k--;
        
        string s;
        cin >> s;

        int saves=0;
        int first = 0;
        int count0=0;

        for (int j=0; j<s.size(); j++){
            if (!saves && s[j]=='1') {saves++; first = j;}
            if (saves){
                
                if (s[j]=='0'){
                    count0++;
                } else {
                    if (count0>=k) saves++;
                    count0=0;
                }
            }


        }
        cout << saves<<endl;

        

    }  
    return 0;
}
