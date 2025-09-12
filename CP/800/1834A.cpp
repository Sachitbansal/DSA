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
        int countpos = 0;
        int countneg = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == 1)  countpos++;
            else countneg++;
        }

        int operations = 0;
        while (countpos < countneg  || countneg % 2 != 0) {
            countpos ++;
            countneg--;
            operations++;
        }

        cout << operations<< endl;
    }
    return 0;
}
