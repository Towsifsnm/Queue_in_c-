#include <bits/stdc++.h>

using namespace std;

void reverseQueue(queue<int> &q) {
    stack<int> s;

    // Push elements
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Pop elements
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Original Queue: ";
    queue<int> originalQ = q;
    while (!originalQ.empty()) {
        cout << originalQ.front() << " ";
        originalQ.pop();
    }
    cout << endl;

    reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
