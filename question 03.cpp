#include <iostream>

using namespace std;

const int MAX_SIZE = 5;
class CircularQueue {
private:
    int queue[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }


    bool isEmpty() {
        return (front == -1 && rear == -1);
    }


    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }


    void enqueue(int val) {
        if (isFull()) {
            cout << "Circular Queue is full." << endl;
            return;
        } else if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        queue[rear] = val;
    }

    // Function to dequeue an element
        int dequeue() {
            if (isEmpty()) {
            cout << "Circular Queue is empty." << endl;
            return -1;
        } else if (front == rear) {
            int frontElement = queue[front];
            front = rear = -1;
            return frontElement;
        } else {
            int frontElement = queue[front];
            front = (front + 1) % MAX_SIZE;
            return frontElement;
        }
    }

    //  display function
    void display() {
        if (isEmpty()) {
            cout << "Circular Queue is empty." << endl;
            return;
        }

        cout << "Current Circular Queue: ";
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }
};

int main() {
    CircularQueue circularQueue;

    circularQueue.enqueue(1);
    circularQueue.enqueue(2);
    cout << "Dequeued: " << circularQueue.dequeue() << endl;
    circularQueue.enqueue(3);
    cout << "Dequeued: " << circularQueue.dequeue() << endl;
    circularQueue.enqueue(4);

    circularQueue.display();

    return 0;
}

