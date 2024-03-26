
#include <bits/stdc++.h>

using namespace std;

struct QueueNode {
    int value;
    int priority;

    QueueNode(int val, int pri) : value(val), priority(pri) {}
};

class PriorityQueue {
private:
    queue<QueueNode> q;

public:
    void enqueue(int val, int priority) {
        q.push(QueueNode(val, priority));
    }

    QueueNode dequeue() {
        if (q.empty()) {
            cerr << "Queue is empty!" << endl;
            return QueueNode(-1, -1);
        }

        QueueNode highestPriority = q.front();
        queue<QueueNode> temp;
        while (!q.empty()) {
            if (q.front().priority < highestPriority.priority)
                highestPriority = q.front();
            temp.push(q.front());
            q.pop();
        }

        // Refill the original queue except for the dequeued element
        while (!temp.empty()) {
            if (temp.front().value != highestPriority.value)
                q.push(temp.front());
            temp.pop();
        }

        return highestPriority;
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    PriorityQueue pq;

    // Enqueue elements with priorities
    pq.enqueue(3, 1);
    pq.enqueue(5, 3);
    pq.enqueue(2, 2);

    // Dequeue
    if (!pq.isEmpty()) {
        QueueNode dequeued = pq.dequeue();
        cout << "Dequeued Element: (" << dequeued.value << ", Priority " << dequeued.priority << ")" << endl;
    } else {
        cout << "Queue is empty, cannot dequeue!" << endl;
    }

    return 0;
}

