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
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        int point1 = 0;
        int count = 0;

        while (point1 < n)
        {
            if (arr[point1] == 0)
            {
                int point2 = point1 + 1;
                while (arr[point2] == 0 && point2 < n)
                {
                    point2++;
                }
                if (point2 - point1 > count)
                    count = point2 - point1;
            }
            point1++;
        }

        cout << count << endl;
    }
    return 0;
}
