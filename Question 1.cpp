#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* topNode = NULL;

// Push
void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
    cout << "Pushed: " << value << endl;
}

// Pop
void pop() {
    if (topNode == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = topNode;
    cout << "Popped: " << temp->data << endl;
    topNode = topNode->next;
    delete temp;
}

// Peek
void peek() {
    if (topNode == NULL)
        cout << "Stack is empty\n";
    else
        cout << "Top element: " << topNode->data << endl;
}

// isEmpty
void isEmpty() {
    if (topNode == NULL)
        cout << "Stack is empty\n";
    else
        cout << "Stack is NOT empty\n";
}

// Display
void display() {
    Node* temp = topNode;
    cout << "Stack: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                push(val);
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                peek();
                break;
            case 4:
                isEmpty();
                break;
            case 5:
                display();
                break;
        }
    } while (choice != 0);

    return 0;
}
