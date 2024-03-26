#include <bits/stdc++.h>


using namespace std;

class MyQueue {
private:
    queue<int> q;

public:
    // added a function
    void enqueue(int val) {
        q.push(val);
    }

    // remove function
    int dequeue() {
        if (q.empty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int frontElement = q.front();
        q.pop();
        return frontElement;
    }

    // display function
    void display() {
        cout << "Current Queue: ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    // check a function string
    bool isPalindrome(const string& str) {
        queue<char> charQueue;
        stack<char> charStack;

        // Enqueue characters
        for (char c : str) {
            charQueue.push(c);
            charStack.push(c);
        }

        // Compare characters
        while (!charQueue.empty() && !charStack.empty()) {
            if (charQueue.front() != charStack.top()) {
                return false;
            }
            charQueue.pop();
            charStack.pop();
        }

        return true;
    }
};

int main() {
    MyQueue myQueue;

    myQueue.enqueue(5);
    myQueue.enqueue(10);

    cout << "Front element dequeued: " << myQueue.dequeue() << endl;
    myQueue.display();


    string inputStr = "radar";
    bool isPal = myQueue.isPalindrome(inputStr);
    cout << "Is palindrome: " << (isPal ? "Yes" : "No") << endl;

    return 0;
 }

