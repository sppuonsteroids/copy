#include <iostream>
using namespace std;

class PizzaParlor {
private:
    int* queue;       // Array to store orders
    int front;        // Points to the front of the queue
    int rear;         // Points to the rear of the queue
    int capacity;     // Maximum number of orders
    int size;         // Current number of orders

public:
    PizzaParlor(int maxOrders) {
        capacity = maxOrders;
        queue = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~PizzaParlor() {
        delete[] queue;
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void placeOrder(int orderID) {
        if (isFull()) {
            cout << "Order queue is full. Cannot accept new orders.\n";
            return;
        }

        if (isEmpty()) { // First order
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        queue[rear] = orderID;
        size++;
        cout << "Order " << orderID << " placed successfully.\n";
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Order " << queue[front] << " served.\n";

        if (front == rear) { // Last order being served
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
            return;
        }

        cout << "Current orders in the queue: ";
        for (int i = 0; i < size; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int maxOrders = 5; // Maximum orders the pizza parlor can accept
    PizzaParlor parlor(maxOrders);

    parlor.placeOrder(101);
    parlor.placeOrder(102);
    parlor.placeOrder(103);
    parlor.displayOrders();

    parlor.serveOrder();
    parlor.displayOrders();

    parlor.placeOrder(104);
    parlor.placeOrder(105);
    parlor.placeOrder(106); // This will show that the queue is full
    parlor.displayOrders();

    parlor.serveOrder();
    parlor.serveOrder();
    parlor.displayOrders();

    return 0;
}
