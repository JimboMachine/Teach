#include <iostream>

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    StackNode* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            std::cerr << "Stack is empty" << std::endl;
            return -1; 
        }
        int value = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    int peek() const {
        if (top == nullptr) {
            std::cerr << "Stack is empty" << std::endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    while (!myStack.isEmpty()) {
        std::cout << "Popped: " << myStack.pop() << std::endl;
    }
    return 0;
}
