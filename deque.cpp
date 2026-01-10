#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Pointers to track front and rear
Node* front = NULL;
Node* rear = NULL;

// Insert at front
void insertFront(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->prev = NULL;
    temp->next = front;

    if (front == NULL) { // empty deque
        front = rear = temp;
    } else {
        front->prev = temp;
        front = temp;
    }

    cout << x << " inserted at front\n";
}

// Insert at rear
void insertRear(int x) {
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    temp->prev = rear;

    if (rear == NULL) { // empty deque
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }

    cout << x << " inserted at rear\n";
}

// Delete from front
void deleteFront() {
    if (front == NULL) {
        cout << "Underflow\n";
        return;
    }

    Node* temp = front;
    cout << "Deleted from front: " << temp->data << endl;

    front = front->next;
    if (front != NULL)
        front->prev = NULL;
    else
        rear = NULL;

    delete temp;
}

// Delete from rear
void deleteRear() {
    if (rear == NULL) {
        cout << "Underflow\n";
        return;
    }

    Node* temp = rear;
    cout << "Deleted from rear: " << temp->data << endl;

    rear = rear->prev;
    if (rear != NULL)
        rear->next = NULL;
    else
        front = NULL;

    delete temp;
}

// Display deque
void displayDeque() {
    Node* temp = front;
    cout << "Deque: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main function
int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(1);

    displayDeque();

    deleteFront();
    deleteRear();

    displayDeque();

    deleteFront();
    deleteRear();

    displayDeque(); // empty now
    deleteFront();  // Underflow

    return 0;
}
