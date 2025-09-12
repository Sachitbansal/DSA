#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 5;
    int arr[] = {1, 2, 4, 5};

    // arr.sort();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1 << endl;
            break;
        }
    }

    // optimal approach using summation
    int summa = (n * (n+1))/2;
    int su = 0;
    for (int i : arr) su += i;
    cout << summa - su << endl;

    return 0;
}