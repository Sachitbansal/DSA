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
        int count=0;
        
        for (int j=0;j<n;j++){
            cin >> arr[j];
            if (arr[j]==2) count++;
        }

        if (count%2==0){
            count/=2;
            for (int j=0;j<n;j++){
                if (arr[j]==2) count--;
                if (count==0) {
                    cout << j+1<<endl;
                    break;
                }
            }
        } else {
            cout << -1 <<endl;
        }


    }
    return 0;
}

