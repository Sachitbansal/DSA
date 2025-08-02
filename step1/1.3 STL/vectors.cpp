#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v{1,2,3,4,5};
    v.push_back(1); // adding elements to the vector
    // generally emplace back is faster than push_back
    v.emplace_back(2); // emplace_back constructs in place

    vector<int> v2(5, 10); // vector of size 5, all elements initialized to 10
    cout << "First element: " << v2[0] << endl; // accessing

    vector<int> v3(5); // vector of size 5, default initialized to 0
    cout << "Second element: " << v3[1] << endl; // accessing second element
    // we can emplace back after initializing
    v3.emplace_back(20); // adding an element to v3

    // understanding interator
    vector<int>::iterator it = v.begin(); // this gives the memory address of the first element
    cout << "First Element "<< *(it) << endl;
    it++;
    cout << "Second Element "<< *(it) << endl;

    vector<int>::iterator it2 = v.end(); // this gives the address after the last element
    it2--;

    cout << "Last Element "<< *(it2) << endl;

    // prining the vector
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }

    // using auto to define varable type
    cout << endl;
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    for (auto x : v) { // range based for loop
        cout << x << " ";
    }

    // using erase - needs starting iterator and ending + 1 iterator
    cout << endl;
    v.erase(v.begin(), v.begin() + 2); // erasing first two elements

    // using insert function
    v.insert(v.begin(), 1); // inserting 1 at the beginning
    v.insert(v.end(), 2); // inserting 2 at the end

    cout << v.size() << endl; // size of the vector
    v.pop_back(); // removing the last element
    v.swap(v2); // swapping two vectors
    v.clear(); // clearing the vector

    return 0;
}