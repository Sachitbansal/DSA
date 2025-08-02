#include <bits/stdc++.h>
using namespace std;

int main() {
    int day;
    cout << "Enter a day (1-7): ";
    cin >> day;
    // break krna padhra hai because switch case mein break nahi karoge toh saare cases execute ho jayenge
    // switch case is used to execute one of the multiple cases based on the value of a variable
    // switch case is more readable than if-else ladder when there are multiple conditions to check

    switch (day) {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
        default:
            cout << "Invalid day";
    }

    return 0;
}