#include <iostream>
using namespace std;

// Node structure for a single stack element
struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

// Stack class using a linked list
class Stack {
private:
    Node* top; // Pointer to the top element of the stack

public:
    // Constructor initializes the stack to be empty
    Stack() : top(nullptr) {}

    // Destructor to free the allocated memory
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Method to add an element to the stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top; // Point the new node to the current top
        top = newNode; // Update the top to be the new node
    }

    // Method to remove the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow. No element to pop." << endl;
            return;
        }
        Node* temp = top; // Store the current top
        top = top->next; // Update the top to the next element
        delete temp; // Delete the old top
    }

    // Method to get the top element of the stack
    int topElement() {
        if (!isEmpty()) {
            return top->data;
        }
        cout << "Stack is empty." << endl;
        return -1; // Return an error value or handle differently
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

// Main function to demonstrate stack operations
int main() {
    Stack stack;

    // Demonstrate pushing elements
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Top element after pushes: " << stack.topElement() << endl;

    // Demonstrate popping elements
    stack.pop();
    cout << "Top element after one pop: " << stack.topElement() << endl;
    stack.pop();
    cout << "Top element after two pops: " << stack.topElement() << endl;

    // Check for stack underflow
    stack.pop();
    cout << "Attempting one more pop..." << endl;
    stack.pop(); // This should trigger underflow condition

    return 0;
}
