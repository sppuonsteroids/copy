#include <iostream>
using namespace std;

#define SIZE 100

int queue[SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
bool isFull() {
    return rear == SIZE - 1;
}

// Function to check if the queue is empty
bool isEmpty() {
    return front == -1;
}

// Function to add an element to the queue
void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue " << value << endl;
        return;
    }
    if (isEmpty()) {
        front = 0; // Initialize front if the queue was empty
    }
    rear++;
    queue[rear] = value;
    cout << "Enqueued: " << value << endl;
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return;
    }
    int value = queue[front];
    cout << "Dequeued: " << value << endl;

    // If the queue becomes empty after dequeuing
    if (front == rear) {
        front = rear = -1; // Reset the queue
    } else {
        front++; // Move front to the next element
    }
}

// Function to display the elements in the queue
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) { // Infinite loop that will exit when choice is 4
        cout << "\nQueue Operations Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0; // Exit the program
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
