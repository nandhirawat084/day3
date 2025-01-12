#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class CustomQueue {
private:
    int capacity;
    vector<int> queue;

public:
    CustomQueue(int capacity) {
        this->capacity = capacity;
    }

    void enqueue(int value) {
        if (queue.size() == capacity) {
            cout << "Queue Overflow" << endl;
        } else {
            queue.push_back(value);
        }
    }

    int dequeue() {
        if (queue.empty()) {
            throw runtime_error("Queue Underflow");
        } else {
            int value = queue.front();
            queue.erase(queue.begin());
            return value;
        }
    }

    int front() {
        if (queue.empty()) {
            throw runtime_error("Queue is empty");
        } else {
            return queue.front();
        }
    }

    bool isEmpty() {
        return queue.empty();
    }

    bool isFull() {
        return queue.size() == capacity;
    }

    int size() {
        return queue.size();
    }

    void printQueue() {
        if (queue.empty()) {
            cout << "Queue is empty" << endl;
        } else {
            for (int val : queue) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    CustomQueue queue(5);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    
    cout << "Elements in queue:" << endl;
    queue.printQueue();

    cout << "Dequeued: " << queue.dequeue() << endl;
    queue.printQueue();

    cout << "Front: " << queue.front() << endl;
    return 0;
}
