#include <bits/stdc++.h>
using namespace std;

void reverseFirstK(queue<int> &q, int k) {
    if (k <= 0 || k > q.size()) {
        cerr << "Invalid value of k!" << endl;
        return;
    }

    stack<int> s;
    // Push the first k elements
    for (int i = 0; i < k; ++i) {
        s.push(q.front());
        q.pop();
    }

    // Enqueue the elements
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }


    int remaining = q.size() - k;
    for (int i = 0; i < remaining; ++i) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original Queue: ";
    queue<int> originalQ = q;
    while (!originalQ.empty()) {
        cout << originalQ.front() << " ";
        originalQ.pop();
    }
    cout << endl;

    int k = 3;
    reverseFirstK(q, k);

    cout << "Modified Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
