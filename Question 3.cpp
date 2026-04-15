#include <iostream>
using namespace std;

#define SIZE 5

int queueArr[SIZE];
int front = -1, rear = -1;

// isFull
bool isFull() {
    return (front == (rear + 1) % SIZE);
}

// isEmpty
bool isEmpty() {
    return (front == -1);
}

// Enqueue
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    queueArr[rear] = value;

    cout << "Enqueued: " << value << endl;
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return;
    }

    cout << "Dequeued: " << queueArr[front] << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Peek
void peek() {
    if (isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Front element: " << queueArr[front] << endl;
}

// Display
void display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue: ";
    int i = front;
    while (true) {
        cout << queueArr[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}

int main() {
    int choice, val;

    do {
        cout << "\n--- CIRCULAR QUEUE MENU ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n0. Exit\n";
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
                peek();
                break;
            case 4:
                display();
                break;
        }
    } while (choice != 0);

    return 0;
}
