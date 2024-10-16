#include <iostream>
using namespace std;
#define SIZE 1000 // Define the size of the array

class Queue {
private:
    int arr[SIZE];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}
        
    bool is_full() {
        return rear == SIZE - 1;
    }
    
    bool is_empty() {
        return front == -1;
    }

    void enqueue(int value) {
        if (is_full()) {
            std::cerr << "Queue is full" << std::endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    int dequeue() {
        if (is_empty()) {
            std::cerr << "Queue is empty" << std::endl;
            return -1;
        }
        int dequeued_value = arr[front];
        if (front >= rear) {
            front = rear = -1; // Reset the queue if it becomes empty
        } else {
            front++;
        }
        return dequeued_value;
    }

    int peek() {
        if (is_empty()) {
            std::cerr << "Queue is empty" << std::endl;
            return -1;
        }
        return arr[front];
    }




};

// Example usage:
int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    std::cout << "Peek: " << queue.peek() << std::endl;    // Output: 1
    std::cout << "Dequeue: " << queue.dequeue() << std::endl; // Output: 1
    std::cout << "Is empty: " << std::boolalpha << queue.is_empty() << std::endl; // Output: false
    queue.enqueue(3);
    std::cout << "Dequeue: " << queue.dequeue() << std::endl; // Output: 2
    std::cout << "Dequeue: " << queue.dequeue() << std::endl; // Output: 3
    std::cout << "Is empty: " << std::boolalpha << queue.is_empty() << std::endl; // Output: true

    return 0;
}

