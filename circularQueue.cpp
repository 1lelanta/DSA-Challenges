#include <iostream>
using namespace std;

#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;


bool isFull() {
    return ((rear + 1) % MAX == front);
}


bool isEmpty() {
    return (front == -1);
}


void enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        return;
    }

    if (isEmpty()) { 
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = x;
    cout << x << " enqueued\n";
}


void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return;
    }

    int y = queue[front];
    cout << "Dequeued: " << y << endl;

    if (front == rear) { 
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}


void display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50); 

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70); 

    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
}