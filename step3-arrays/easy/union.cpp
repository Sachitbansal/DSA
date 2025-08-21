#include <bits/stdc++.h>
using namespace std;

int main() {

    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 

    vector <int> arr;
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < n; i++){
        if (arr1[p1] < arr1[p2]) {
            arr.push_back(arr1[p1]);
            p1++;
        } else if (arr1[p2] < arr1[p1]) {
            arr.push_back(arr1[p1]);
            p1++;
        }
    }
safsea
    return 0;
}