#include <bits/stdc++.h>
using namespace std;

int main() {

    // understanding queue from STL
    queue<int> q; // creating a queue of integers
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "Front element: " << q.front() << endl;
    q.pop();
    cout << "Front element after pop: " << q.front() << endl;

    cout << q.empty() << endl; // checking if the queue is empty
    cout << q.size() << endl; // getting the size of the queue
    return 0;
}