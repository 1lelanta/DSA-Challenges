#include <iostream>
using namespace std;

#define MAX 100

int pq[MAX];   
int n = 0;     

// Insert element with priority
void enqueue(int x) {
    int i = n - 1;

    // Move elements smaller than x one position ahead
    while (i >= 0 && pq[i] < x) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = x;
    n++;
    cout << x << " inserted\n";
}

// Remove element with highest priority (front element)
void dequeue() {
    if (n == 0) {
        cout << "Queue Underflow\n";
        return;
    }

    int y = pq[0]; // highest priority element
    cout << "Deleted element: " << y << endl;

    // Shift all elements left
    for (int i = 1; i < n; i++) {
        pq[i - 1] = pq[i];
    }
    n--;
}


void display() {
    if (n == 0) {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Priority Queue: ";
    for (int i = 0; i < n; i++)
        cout << pq[i] << " ";
    cout << endl;
}


int main() {
    enqueue(30);
    enqueue(10);
    enqueue(20);
    enqueue(50);
    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(35);
    display();

    return 0;
}
