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

        string arr;
        int count=1;
        int mac=1;
        cin >>arr;

        for (int j=1;j<n;j++){
            if (arr[j]==arr[j-1]){
                count++;
            } else {
                mac=max(count,mac);
                count=1;
            }
            mac=max(count,mac);
        }

        cout << mac+1<<endl;
    }    

    return 0;
}
