#include <bits/stdc++.h>


using namespace std;

class MyQueue {
private:
    queue<int> q;

public:
    // added function
    void enqueue(int val) {
        q.push(val);
    }

    // Function to remove and return

    int dequeue() {
        if (q.empty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int frontElement = q.front();
        q.pop();
        return frontElement;
    }

    //   display function
    void display() {
        cout << "Current Queue: ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    MyQueue myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(10);

    cout << "Front element dequeued: " << myQueue.dequeue() << endl;
    myQueue.display();

    return 0;
}

