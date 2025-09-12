#include <bits/stdc++.h>
using namespace std;

// Without Using backtrack n to 1
void print(int count) {

    if (count != 0) {
        cout << count << endl;
        print(--count);   
        return;
    }
    return;
}

// Using Backtrack 1 to n
void WithBacktrack1Ton(int count) {
    if (count != 0) {
        WithBacktrack1Ton(count-1);    
        cout << count << endl;
    }
    return;
}

// Without Using Backtrack 1 to n
void WithoutUsingBacktrack1Ton(int a, int count) {
    if (a == count) {
        cout << a << endl;
        return;
    } else {
        cout << a << endl;
        WithoutUsingBacktrack1Ton(a+1, count);
    }
}

// Using Backtrack n to 1
void UsingBacktracknTo1(int a, int count) {
    if (a == count) {
        cout << a << endl;
        return;
    } else {
        UsingBacktracknTo1(a+1, count);
        cout << a << endl;
    }
}

int main() {
    UsingBacktracknTo1(1, 10);

    return 0;
}
