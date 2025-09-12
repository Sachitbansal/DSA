#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 11;
    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1,1,1,1};
    // int arr[] = {1, 0, 1, 1, 0, 1};

    int dis = 0;
    int ind = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            if (ind - i > dis)
            {
                dis = ind - i;
                ind = i-1;
            }
        }
    }

    cout << dis << endl;

    return 0;
}