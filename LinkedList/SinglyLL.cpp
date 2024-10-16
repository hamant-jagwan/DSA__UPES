#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data);
    void insertAtEnd(int data);
    void insertAtPosition(int data, int position);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteNode(int data);
    void traverse();
    bool search(int data);
    int length();
};

void LinkedList :: insertAtBeginning(int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
 
void LinkedList :: insertAtEnd(int data){
    Node* newNode = new Node(data);
    if(!head){
        head = newNode;
    } else{
        Node* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList :: insertAtPosition( int data , int position){
    if(position == 0 ){
        insertAtBeginning(data);
        return;
    }
    Node* newNode = new Node(data);
    Node* temp = head;
    for(int i =1; temp != nullptr && i < position; i++){
        temp = temp->next;
    }
    if(temp == nullptr){
        cout << "position out of bounds" << endl;
        return ;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList :: deleteFromBeginning(){
    if(!head){
        cout << "list is empty" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp; 
    //If you didn't store head in temp, you would lose the reference to the original head node after updating head, 
    //making it impossible to delete that node

}

void LinkedList :: deleteFromEnd(){
    if(!head){
        cout << "List is empty" << endl;
        return;
    }
    if(!head->next){
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while(temp->next->next){
        temp  = temp->next;
    }
    delete temp ->next;
    temp->next = nullptr;
}

void LinkedList :: deleteNode(int data){
    if(!head){
        cout << "List is empty" << endl;
        return;
    }
    if(head->data == data){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while(temp ->next && temp-> next->data != data){
        temp = temp->next;
    }
    if(!temp->next){
        cout << "Node not found" << endl;
        return ;
    }
    Node* nodeToDelete  = temp ->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void LinkedList :: traverse(){
    Node* temp = head;
    while(temp){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "nullptr" << endl;
}

bool LinkedList :: search(int data){
    Node* temp  = head;
    while(temp){
        if(temp->data == data){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int LinkedList :: length(){
    int count = 0;
    Node* temp = head;
    while(temp){
        count ++;
        temp = temp ->next;
    }
    return count;
}

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.traverse();

    list.insertAtBeginning(0);
    list.insertAtPosition(1, 1);
    list.traverse();

    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteNode(2);
    list.traverse();

    std::cout << "Length of the list: " << list.length() << std::endl;

    int searchKey = 3;
    if (list.search(searchKey)) {
        std::cout << searchKey << " found in the list" << std::endl;
    } else {
        std::cout << searchKey << " not found in the list" << std::endl;
    }

    return 0;
}
