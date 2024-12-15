#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int bit; // 0 or 1
    Node* next;
    Node* prev;

    Node(int b) : bit(b), next(nullptr), prev(nullptr) {}
};

// Class for the doubly linked list
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to insert a bit at the end of the list
    void insert(int bit) {
        Node* newNode = new Node(bit);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to display the binary number
    void display() const {
        Node* current = head;
        while (current) {
            cout << current->bit;
            current = current->next;
        }
        cout << endl;
    }

    // Function to compute 1's complement
    void onesComplement() {
        Node* current = head;
        while (current) {
            current->bit = (current->bit == 0) ? 1 : 0; // Flip the bit
            current = current->next;
        }
    }

    // Function to compute 2's complement
    void twosComplement() {
        onesComplement(); // First compute 1's complement

        // Add 1 to the 1's complement
        Node* current = tail;
        int carry = 1;

        while (current && carry) {
            int sum = current->bit + carry;
            current->bit = sum % 2;
            carry = sum / 2;
            current = current->prev;
        }

        // If there's still a carry, add a new bit at the front
        if (carry) {
            Node* newNode = new Node(1);
            newNode->next = head;
            if (head) {
                head->prev = newNode;
            }
            head = newNode;
        }
    }

    // Function to add two binary numbers
    static DoublyLinkedList addBinary(const DoublyLinkedList& b1, const DoublyLinkedList& b2) {
        Node* t1 = b1.tail;
        Node* t2 = b2.tail;
        DoublyLinkedList result;

        int carry = 0;
        while (t1 || t2 || carry) {
            int sum = carry;
            if (t1) {
                sum += t1->bit;
                t1 = t1->prev;
            }
            if (t2) {
                sum += t2->bit;
                t2 = t2->prev;
            }
            result.insertFront(sum % 2); // Insert at the front to maintain order
            carry = sum / 2;
        }

        return result;
    }

    // Function to insert a bit at the front of the list
    void insertFront(int bit) {
        Node* newNode = new Node(bit);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
};

int main() {
    DoublyLinkedList binaryNumber;

    // Input binary number
    cout << "Enter binary number (e.g., 1101): ";
    string input;
    cin >> input;

    // Store binary number in doubly linked list
    for (char bit : input) {
        binaryNumber.insert(bit - '0'); // Convert char to int
    }

    cout << "Original binary number: ";
    binaryNumber.display();

    // Compute and display 1's complement
    binaryNumber.onesComplement();
    cout << "1's complement: ";
    binaryNumber.display();

    // Compute and display 2's complement
    binaryNumber.twosComplement();
    cout << "2's complement: ";
    binaryNumber.display();

    // Adding two binary numbers
    DoublyLinkedList binaryNumber2;
    cout << "Enter another binary number to add (e.g., 1011): ";
    cin >> input;

    // Store second binary number in doubly linked list
    for (char bit : input) {
        binaryNumber2.insert(bit - '0'); // Convert char to int
    }

    cout << "Second binary number: ";
    binaryNumber2.display();

    cout << "Sum of the two binary numbers: ";
    DoublyLinkedList sum = DoublyLinkedList::addBinary(binaryNumber, binaryNumber2);
    sum.display();

    return 0;
}
