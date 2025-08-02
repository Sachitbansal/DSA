#include <bits/stdc++.h>
using namespace std;

int main() {

    pair<int, int> p = {1, 2}; // creating a pair
    cout << "First element: " << p.first << endl; // accessing first element
    cout << "Second element: " << p.second << endl; // accessing second element

    pair<int, pair<int, int>> nestedPair = {3, {4, 5}}; // nested pair
    cout << "Nested pair first: " << nestedPair.first << endl; // accessing first
    cout << "Nested pair second: " << nestedPair.second.first << endl; // accessing second of nested pair
    cout << "Nested pair third: " << nestedPair.second.second << endl; // accessing third of nested pair

    // pair can be used as data type so we can make array of pairs
    pair<int, int> arrPairs[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arrPairs[0].first << " " << arrPairs[0].second << endl; // accessing first pair
    return 0;
}