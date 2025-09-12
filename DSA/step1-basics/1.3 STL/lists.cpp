#include <bits/stdc++.h>
using namespace std;

int main() {

    list<int> l; // creating a list of integers
    l.push_back(1); // adding elements to the list
    l.push_back(2);
    l.push_back(3);
    l.emplace_back(4); // emplace_back adds an element at the end

    l.push_front(0); // adding an element at the front and cheap compared to insert
    l.emplace_front(-1); // emplace_front adds an element at the front

    // printing the elements of the list using iterators
    for (auto it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // using auto keyword
    for (auto x : l) {
        cout << x << " ";
    }
    cout << endl;

    // using erase
    l.erase(l.begin()); // removing the first element
    for (auto x : l) {
        cout << x << " ";
    }
    cout << endl;

    // using insert
    l.insert(l.begin(), 0); // inserting 0 at the beginning
    for (auto x : l) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}