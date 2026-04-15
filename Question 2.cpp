#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* frontNode = NULL;
Node* rearNode = NULL;

// Enqueue
void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (rearNode == NULL) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    cout << "Enqueued: " << value << endl;
}

// Dequeue
void dequeue() {
    if (frontNode == NULL) {
        cout << "Queue Underflow\n";
        return;
    }

    Node* temp = frontNode;
    cout << "Dequeued: " << temp->data << endl;
    frontNode = frontNode->next;

    if (frontNode == NULL)
        rearNode = NULL;

    delete temp;
}

// Front
void front() {
    if (frontNode == NULL)
        cout << "Queue is empty\n";
    else
        cout << "Front element: " << frontNode->data << endl;
}

// isEmpty
void isEmpty() {
    if (frontNode == NULL)
        cout << "Queue is empty\n";
    else
        cout << "Queue is NOT empty\n";
}

// Display
void display() {
    Node* temp = frontNode;
    cout << "Queue: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\n--- QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. isEmpty\n5. Display\n0. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                enqueue(val);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                front();
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
