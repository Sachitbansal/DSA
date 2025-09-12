#include <bits/stdc++.h>
using namespace std;

int main() {

    // Stack follows LIFO (Last In First Out) principle
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    cout << s.empty() << endl;
    return 0;
}