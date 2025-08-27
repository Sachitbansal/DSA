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

        int arr[n];
        map<int, int> count;

        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
            count[arr[j]]++;
        }

        int operations = 0;

        if (count[1] == 0)
        {
            operations = count[-1];
            cout << operations << endl;
            continue;
        }
        else if (count[-1] == 0 || count[-1] == count[1] && count[-1] != 1)
        {
            operations = 0;
            cout << operations << endl;
            continue;
            // cout << "hua" << endl;
        }
        else if (count[-1] > count[1])
        {
            while(count[-1]%2!=0 || count[1]<count[-1]){
                count[-1]--;
                count[1]++;
                operations++;
            }

        }
        else if (count[-1] < count[1])
        {
            while(count[-1]%2!=0 || count[1]<count[-1]){
                count[-1]++;
                count[1]--;
                operations++;
            }
        } else operations = 1;
        

        cout << operations<< endl;
    }
    return 0;
}
