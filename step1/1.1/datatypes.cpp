#include <bits/stdc++.h>
using namespace std;

int main() {

    int x = 10; // Integer type
    double y = 3.14; // Floating-point type 
    char z = 'A'; // Character type
    string str = "Hello"; // String type
    bool flag = true; // Boolean type

    long a = 100000L; // Long type
    short b = 30000; // Short type

    // if we put multiple words, it will only take the first word
    string s1;
    cin >> s1; // Input string
    cout << "String input: " << s1 << endl;

    // using ingore to consume the newline character left in the input buffer
    cin.ignore(); // <- This consumes the leftover newline

    // to take a full line input, we can use getline
    string str2;
    getline(cin, str2);
    cout << "Full line input: " << str2 << endl;

}