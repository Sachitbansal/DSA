#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        int ahan=false;
       

        for (int j=0;j<n;j++){
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end(), greater<int>());

        if (arr[0]!=arr[n-1]){
            ahan=true;
            if (arr[0]==arr[1] && arr[0]!=arr[n-1]){
                swap(arr[0], arr[n-1]);
            }
        }
        

       

        if (ahan) {
            cout<< "YES"<<endl;
            for (auto j: arr) {
                cout << j << " ";
            } 
            cout <<endl;
        } else cout << "NO"<<endl;


    }
    return 0;
}

