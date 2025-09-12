#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n = 5, m = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 4, 5};

    vector<int> arr;
    int p1 = 0;
    int p2 = 0;
    while (p1 < n && p2 < m)
    {
        if (arr1[p1] <= arr2[p2])
        {
            if (!arr.empty())
            {
                if (arr.back() != arr1[p1])
                {
                    arr.push_back(arr1[p1]);
                }
            }
            else
                arr.push_back(arr1[p1]);
            p1++;
        }
        else
        {
            if (!arr.empty())
            {
                if (arr.back() != arr2[p2])
                {
                    arr.push_back(arr2[p2]);
                }
            }
            else
                arr.push_back(arr2[p2]);
            p2++;
        }
    }

    while (p1 < n)
    {
        if (arr.back() != arr1[p1]) arr.push_back(arr1[p1]);
        p1++;
    }
    while (p2 < m)
    {
        if (arr.back()!= arr2[p2])
            arr.push_back(arr2[p2]);
        p2++;
    }

    cout << arr.size() << endl;

    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << p1 << " " << p2 << endl;
    return 0;
}