# include <iostream>
using namespace std;

class node
{
    public:
	int data;
	node *next;
};

class Stack
{
	node *front;  // points to the head of list
	
    public:
	Stack()
	{
		front = NULL;
	}
	// push method to add data element
	void push(int);
	// pop method to remove data element
	void pop();
	// top method to return top data element
	int top();
    // isEmptyto check if the stack is empty
    bool isEmpty();
    // display all the element of stack
    void display();
};

// Inserting Data in Stack(Linked List)
void Stack :: push(int d)
{
	// creating a new node
	node *temp;
	temp = new node();
	// setting data to it
	temp->data = d;

	// add the node in front of list
	if(front == NULL)
	{
		temp->next = NULL;
	}
	else
	{
		temp->next = front;
	}
	front = temp;
}

// Removing Element from Stack (Linked List)
void Stack :: pop()
{
	// if empty
	if(front == NULL)
		cout << "UNDERFLOW\n";
	
	// delete the first element
	else
	{
		node *temp = front;
		front = front->next;
		delete(temp);
	}
}

// Return Top of Stack (Linked List)
int Stack :: top()
{
	return front->data;
}

bool Stack :: isEmpty() {
      
        // If head is nullptr, the stack is empty
    return front == nullptr;
}

void Stack :: display() {
   node* ptr;
   if(front==NULL)
   cout<<"stack is empty";
   else {
      ptr = front;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}

// Driver program to test above functions
int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop() ;
  
    //print top element of stack after popping
    cout << "Top element is : " << s.top() << endl;
    cout << s.isEmpty() << endl;
  
    //print all elements in stack :
    s.display();
    

    return 0;
}