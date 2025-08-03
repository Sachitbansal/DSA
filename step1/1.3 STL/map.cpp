#include <bits/stdc++.h>
using namespace std;

int main() {

    // understanding map from STL
    map<int, string> m; // creating a map of integer to string
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    cout << "Element at key 2: " << m[2] << endl;

    // iterating over the map
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // using find
    auto it = m.find(2);
    if (it != m.end()) {
        cout << "Found element at key 2: " << it->second << endl;
    }

    // using erase
    m.erase(2);
    cout << "Size of map after erasing key 2: " << m.size() << endl;

    return 0;
}