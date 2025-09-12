#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int middle, int high) {
    vector<int> arrr;
    int left = low;
    int right = middle;
    

    while (left < middle && right < high) {
        if (arr[left] < arr[right]) {arrr.push_back(arr[left++]); cout << "adding left" << endl;}
        else {arrr.push_back(arr[right++]); cout << "adding right" << endl;}
    }
    while (left < middle) {
        arrr.push_back(arr[left++]); 
        cout << "adding all left" << endl;
    }
    cout << "right " << right << arr[right]<<endl;
    while (right < high) {
        arrr.push_back(arr[right]); 
        right++; 
        cout << "adding all right" << endl;
    }
    for (auto i: arrr) {
        cout << i << endl;
    }
    
}

void devide(int arr[], int low, int high) {
    if (low == high) return;
    int middle = (low + high)/2;
    devide(arr, low, middle);
    devide(arr, middle, high);
    // merge(arr, low, middle, high);
}


int main() {

    vector<int> arr = {1,1,2,3,4,2,4,5,6};

    merge(arr, 0,5, 9);
    

    // for (auto i: arr) {
    //     cout << i << endl;
    // }

    return 0;
}