#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAt(int value, int position) {
        if (position < 0) {
            std::cerr << "Invalid position" << std::endl;
            return;
        }
        if (position == 0) {
            prepend(value);
        } else {
            Node* current = head;
            int count = 0;
            while (current != nullptr && count < position - 1) {
                current = current->next;
                count++;
            }
            if (current == nullptr) {
                std::cerr << "Invalid position" << std::endl;
                return;
            }
            Node* newNode = new Node(value);
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr) {
                current->next->prev = newNode;
            }
            current->next = newNode;

            if (newNode->next == nullptr) {
                tail = newNode;
            }
        }
    }

    void deleteAt(int position) {
        if (head == nullptr || position < 0) {
            std::cerr << "Invalid position" << std::endl;
            return;
        }
        Node* current = head;
        if (position == 0) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete current;
        } else {
            int count = 0;

            while (current != nullptr && count < position) {
                current = current->next;
                count++;
            }
            if (current == nullptr) {
                std::cerr << "Invalid position" << std::endl;
                return;
            }
            current->prev->next = current->next;
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            delete current;
        }
    }

    void reverse() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void deleteList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    ~DoublyLinkedList() {
        deleteList();
    }
};

int main() {
    DoublyLinkedList myLinkedList;
    myLinkedList.append(1);
    myLinkedList.append(2);
    myLinkedList.append(3);
    myLinkedList.prepend(0);
    myLinkedList.printList();
    myLinkedList.insertAt(4, 2);
    myLinkedList.printList();
    myLinkedList.deleteAt(1);
    myLinkedList.printList();
    myLinkedList.reverse();
    myLinkedList.printList();
    return 0;
}