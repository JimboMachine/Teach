#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
void insert(Node<T>* &head, T val) {
    Node<T>* newNode = new Node<T>{val, nullptr};
    //Node<T>* newNode = new Node<T>;
    //newNode->data = val;
    //newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = nullptr;
    }
}

template <typename T>
void insertFromHead(Node<T>* &head, T val) {
    Node<T>* newNode = new Node<T>{val, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void insertXData(Node<T>*& head, T val,T target) {
    Node<T>* newNode = new Node<T>{val, nullptr};
    if (head == nullptr) {
        return;
    } else {
        Node<T>* temp = head;
        while (temp != nullptr && temp->data != target){
            temp = temp->next;
        }
        if(temp != nullptr){
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

template <typename T>
void display(Node<T>* head) {
    Node<T>* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    //cout << "\n";
}

template <typename T>
void remove(Node<T>*& head, T val) {
    Node<T>* temp = head;
    Node<T>* prev = nullptr;

    while (temp != nullptr && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != nullptr) {
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
}

template <typename T>
void clear(Node<T>*& head) {
    Node<T>* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node<int>* intList = nullptr;
    insertFromHead(intList,7);
    insert(intList, 1);
    insert(intList, 2);
    insert(intList, 3);
    insertFromHead(intList,5);
    // for(int i = 0; i <= 5 ;i++)
    //     insert(intList,i);
    // std::cout << "Linked List: ";
    display(intList);
    insertXData(intList, 56, 7);
    display(intList);
    // std::cout << "Linked List after removal: ";
    // display(intList);
    // clear(intList);

    return 0;
}
