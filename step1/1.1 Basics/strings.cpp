#include <bits/stdc++.h>
using namespace std;

int main() {

    string s = "Sachit"; // ordered and stored at index

    cout << s[2] << endl;
    int length = s.size(); // gives length
    cout << s[length - 1] << endl; // last character

    // string are ordered characters and are mutable
    s = "Sachit Singh";
    cout << s << endl;
    s[0] = 's'; // changing first character
    cout << s << endl;
    return 0;
}