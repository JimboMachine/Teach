#include <iostream>

class QueueNode {
public:
    int data;
    QueueNode* next;

    QueueNode(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        QueueNode* newNode = new QueueNode(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            std::cerr << "Queue is empty" << std::endl;
            return -1;
        }
        int value = front->data;
        QueueNode* temp = front;
        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
        }
        delete temp;
        return value;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    while (!myQueue.isEmpty()) {
        std::cout << "Dequeued: " << myQueue.dequeue() << std::endl;
    }
    return 0;
}
