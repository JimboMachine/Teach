#include <iostream>

class PriorityQueueNode {
public:
    int data;
    int priority;
    PriorityQueueNode* next;
    PriorityQueueNode(int value, int prio) : data(value), priority(prio), next(nullptr) {}
};

class PriorityQueue {
private:
    PriorityQueueNode* front;

public:
    PriorityQueue() : front(nullptr) {}

    void enqueue(int value, int priority) {
        PriorityQueueNode* newNode = new PriorityQueueNode(value, priority);

        if (front == nullptr || priority > front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            PriorityQueueNode* current = front;

            while (current->next != nullptr && priority <= current->next->priority) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            std::cerr << "Priority Queue is empty" << std::endl;
            return -1;
        }

        int value = front->data;
        PriorityQueueNode* temp = front;
        front = front->next;
        delete temp;
        return value;
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    PriorityQueue myPriorityQueue;
    myPriorityQueue.enqueue(1, 3);
    myPriorityQueue.enqueue(2, 1);
    myPriorityQueue.enqueue(3, 2);
    while (!myPriorityQueue.isEmpty()) {
        std::cout << "Dequeued: " << myPriorityQueue.dequeue() << std::endl;
    }
    return 0;
}
