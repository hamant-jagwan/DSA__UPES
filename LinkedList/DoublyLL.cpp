# include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList();
    void insertAtFront(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int position);
    void deleteAtFront();
    void deleteAtEnd();
    void deleteAtPosition(int position);
    void display();
};

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
}

void DoublyLinkedList::insertAtFront(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void DoublyLinkedList::insertAtPosition(int data, int position) {
    if (position <= 0) {
        cout << "Position should be greater than 0" << endl;
        return;
    }
    if (position == 1) {
        insertAtFront(data);
        return;
    }
    Node* newNode = new Node(data);
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }
    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void DoublyLinkedList::deleteAtFront() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::deleteAtEnd() {
    if (head == nullptr) return;
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::deleteAtPosition(int position) {
    if (position <= 0) {
        cout << "Position should be greater than 0" << endl;
        return;
    }
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    if (position == 1) {
        deleteAtFront();
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position && temp != nullptr; ++i) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds" << endl;
        return;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void DoublyLinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main() {
    DoublyLinkedList dll;
    dll.insertAtFront(10);
    dll.insertAtEnd(20);
    dll.insertAtPosition(15, 2);
    dll.insertAtPosition(5, 1);
    dll.insertAtPosition(25, 5);

    cout << "List after insertions: ";
    dll.display();

    dll.deleteAtPosition(1);
    cout << "List after deleting at position 1: ";
    dll.display();

    dll.deleteAtPosition(3);
    cout << "List after deleting at position 3: ";
    dll.display();

    return 0;
}




