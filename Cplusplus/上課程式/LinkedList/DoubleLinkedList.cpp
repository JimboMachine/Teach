#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void append(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void prepend(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAt(Node*& head, Node*& tail, int value, int position) {
    if (position < 0) {
        cerr << "Invalid position" << endl;
        return;
    }
    if (position == 0) {
        prepend(head, tail, value);
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
        Node* newNode = new Node{value, nullptr, nullptr};
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

void deleteAt(Node*& head, Node*& tail, int position) {
    if (head == nullptr || position < 0) {
        cerr << "Invalid position" << endl;
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
            cerr << "Invalid position" << endl;
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

void reverse(Node*& head, Node*& tail) {
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

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    append(head, tail, 1);
    append(head, tail, 2);
    append(head, tail, 3);
    prepend(head, tail, 0);
    printList(head);
    insertAt(head, tail, 4, 2);
    printList(head);
    deleteAt(head, tail, 1);
    printList(head);
    reverse(head, tail);
    printList(head);
    deleteList(head);
    return 0;
}
