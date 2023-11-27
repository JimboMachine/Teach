#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        head->next = head;  // 將最後一個節點指向第一個節點，形成循環
    } else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
}

void prepend(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
        head->next = head;
    } else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        newNode->next = head;
        current->next = newNode;
        head = newNode;
    }
}

void insertAt(Node*& head, int value, int position) {
    if (position < 0) {
        cerr << "Invalid position" << endl;
        return;
    }

    if (position == 0) {
        prepend(head, value);
    } else {
        Node* current = head;
        int count = 0;

        while (current != nullptr && count < position - 1) {
            current = current->next;
            count++;
        }

        if (current == nullptr) {
            cerr << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node{value, nullptr};
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteAt(Node*& head, int position) {
    if (head == nullptr || position < 0) {
        cerr << "Invalid position" << endl;
        return;
    }

    Node* current = head;

    if (position == 0) {
        Node* lastNode = head;
        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }

        if (head == lastNode) {
            delete head;
            head = nullptr;
        } else {
            lastNode->next = head->next;
            delete head;
            head = lastNode->next;
        }
    } else {
        int count = 0;
        while (current != nullptr && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current == nullptr || current->next == head) {
            cerr << "Invalid position" << endl;
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node* current = head;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

void deleteList(Node*& head) {
    if (head == nullptr) {
        return;
    }
    Node* current = head;
    Node* nextNode;
    do {
        nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
    head = nullptr;
}

int main() {
    Node* head = nullptr;
    append(head, 1);
    append(head, 2);
    append(head, 3);
    prepend(head, 0);
    printList(head);
    insertAt(head, 4, 2);
    printList(head);
    deleteAt(head, 1);
    printList(head);
    deleteList(head);
    return 0;
}
