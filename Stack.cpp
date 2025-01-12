#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class CustomStack {
private:
    int capacity;
    vector<int> stack;

public:
    CustomStack(int capacity) {
        this->capacity = capacity;
    }

    void push(int value) {
        if (stack.size() == capacity) {
            cout << "Stack Overflow" << endl;
        } else {
            stack.push_back(value);
        }
    }

    int pop() {
        if (stack.empty()) {
            throw runtime_error("Stack Underflow");
        } else {
            int value = stack.back();
            stack.pop_back();
            return value;
        }
    }

    int peek() {
        if (stack.empty()) {
            throw runtime_error("Stack is empty");
        } else {
            return stack.back();
        }
    }

    bool isEmpty() {
        return stack.empty();
    }

    bool isFull() {
        return stack.size() == capacity;
    }

    int size() {
        return stack.size();
    }

    void printStack() {
        if (stack.empty()) {
            cout << "Stack is empty" << endl;
        } else {
            for (int val : stack) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    CustomStack stack(5);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    cout << "Elements in stack:" << endl;
    stack.printStack();

    cout << "Popped: " << stack.pop() << endl;
    stack.printStack();

    cout << "Peek: " << stack.peek() << endl;
    return 0;
}
